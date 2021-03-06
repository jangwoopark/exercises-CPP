#include <vector>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <assert.h>
#include <math.h>

using namespace std;

uint64_t myPow(uint64_t num, uint64_t pow)
{
    uint64_t result=1;
    for (uint64_t i=0; i < pow; i++) {
        result = result*num;
    }
    return result;
}

// Mostly using class as a namespace :-) 
class DeciNumber {

public:

    // Decicache is a two dimensional array. 
    // This tracks number of ways a decimal number can be represented as 
    //   a decibinary number. 
    // Row tracks the max power of 2 that is used 
    //  e.g. row 0 would only contain entries for numbers that can be created 
    //    using 2**0, so will have only 10 entries (0..9).
    //  row 1 would contain entreis for numbers that can be created with 2**1
    //    and lower so would have entries from 0..27 (00..99 in decibinary)
    //  Each row is a superset of previous row but we track each one to allow
    //    us to get the precise decibinary number
    //  Also note that certain segements of each row will be a repeat of the 
    //    previous row. We don't bother optimizing space to eliminate
    //    this duplication
    //
    vector< vector<uint64_t>> DeciCache;

    // This tracks the cummulative total of deci-binary for a given decimal 
    //  number e.g. 1 => 2 (There are 2 decibinary with decimal value <= 1)
    //              2 => 4 
    //              3 => 6 
    vector<uint64_t> DeciCombos;


    //Some trial and error shows that we can get to 10**16 deci-binary 
    //  number by the time we reach 300,000 decimal. 300K in turn would
    //  use at most 18 digits (2**18), since smallest number using 2**19 is ~500K
    //  
    const uint64_t maxPowerOf2 = 18;
    const int maxDecimal = 300*1000;

    DeciNumber()
    {
        // Fill in row 0 manually
        DeciCache.push_back({1,1,1,1,1,1,1,1,1,1});

        for (int pow2=1; pow2 <= maxPowerOf2; pow2++) {
            uint64_t pow2Num = 1 << pow2;

            int maxEntries = 1 + 9*(2*pow2Num-1);
            maxEntries = min(maxEntries, maxDecimal+1);
            DeciCache.push_back(vector<uint64_t>(maxEntries,0));

            vector<uint64_t>& prevRow(DeciCache[pow2-1]);
            vector<uint64_t>& currRow(DeciCache[pow2]);

            for (int multiple=0; multiple <= 9; multiple++) {
                for (int prevIndex=0; prevIndex < prevRow.size(); prevIndex++) {
                    int currIndex = prevIndex + multiple*pow2Num;
                    if (currIndex > maxDecimal) break;
                    currRow[currIndex] += prevRow[prevIndex];
                }
            }
        }

        uint64_t total=0;
        for (int i=0; i <= maxDecimal; i++) {
            total += DeciCache[maxPowerOf2][i];
            DeciCombos.push_back(total);
        }
    }

    // Get an approximate measure of how much memory is used
    uint64_t GetSize()
    {
        int numEntries=0;
        for (int pow2=0; pow2 <= maxPowerOf2; pow2++) {
            numEntries += DeciCache[pow2].size();
        }
        return(numEntries * sizeof(DeciCache[0][0]));
    }

    // Return decimal value for the Nth deci-binary number
    //  Older linear search implementation. Keeping for comparison
    int GetDecimalAtIndexLinear(uint64_t numIndex) 
    {
        assert(numIndex > 0);
        for (int i=0; i < DeciCombos.size(); i++) {
            if (DeciCombos[i] >= numIndex) return i;
        }
        // didn't find the value 
        return -1;
    }

    // Return decimal value for the Nth deci-binary number
    //  binary search version
    int GetDecimalAtIndex(uint64_t numIndex) 
    {
        assert(numIndex > 0);
        int left = 0; 
        int right = DeciCombos.size()-1;

        while (right - left > 1) {
            int mid = int((right+left)/2);
            if (DeciCombos[mid] == numIndex) return mid;
            if (DeciCombos[mid] < numIndex) left = mid;
            else right = mid;
        }

        if (DeciCombos[left] >= numIndex) return left;
        assert(DeciCombos[right] > numIndex);
        return right;
    }



    // A given decimal number can be expressed in various ways in deci-binary 
    // This method returns the Nth of this, with the additional constraint 
    //   that only maxDigit positions be used (0 => 1 digit allowed)
    uint64_t GetDeciBinary(int decimalNumber, uint64_t indexN, int maxDigit)
    {

        //cout << "MaxDigit = " << maxDigit << " decimal " << decimalNumber << " indexN " << indexN << endl;

        if (maxDigit == 0) {
            assert(decimalNumber < 10);
            assert(indexN == 1);
            return decimalNumber;
        }

        // For this digit (maxDigit): find number of combos when digit=0,1,..9
        // 
        for (int digitVal=0; digitVal < 10; digitVal++) {

            // I was missing this check in previous implemenation. It is possible 
            //   that current decimalNumber is not at all possible with fewer digits and 
            //   hence won't have an entry for maxDigit-1 vector e.g. 12 is not possible with 0
            //   in digit1 position; need at least 2 in digit1 viz 28
            if (decimalNumber < DeciCache[maxDigit-1].size()) {
                //cout << "*** Digit " << digitVal << " dec " << decimalNumber << " indexN "<< indexN << " next " << DeciCache[maxDigit-1][decimalNumber] << endl;

                if ( DeciCache[maxDigit-1][decimalNumber] >= indexN) {

                    uint64_t deciBinary = GetDeciBinary(decimalNumber, indexN, maxDigit - 1);
                    deciBinary +=  digitVal*myPow(10,maxDigit);
                    //cout << "*** returning for digit " << maxDigit << " " << deciBinary << endl;
                    return deciBinary;
                }
                indexN -= DeciCache[maxDigit-1][decimalNumber];
            } else {
                //cout << "*** Digit " << digitVal << " dec " << decimalNumber << " indexN "<< indexN << " no entry for next " << endl;
            }
            decimalNumber -= (1 << maxDigit);
        }

        // Should never reach here. Maybe assert ?
        return -1;
    }


    // convert given deci-binary number into decimal
    uint64_t ToDecimal(uint64_t deciBinary)
    {
        uint64_t decimal=0;
        uint64_t power2=1;
        while (deciBinary > 0){
            int digit = deciBinary % 10;
            deciBinary = uint64_t(deciBinary/10);
            decimal += digit*power2;
            power2 *= 2;
        }
        return decimal;
    }


    uint64_t GetDeciBinary(uint64_t indexN)
    {
        assert(indexN > 0);

        // Handle some edge cases to keep the loop below simple
        if (indexN == 1) return 0;
        if (indexN == 2) return 1;

        int decimalValue = GetDecimalAtIndex(indexN);
        assert(decimalValue > 1);

        //cout << "Looking for indexN = " << indexN << " decimal value = " << decimalValue << endl;
        //cout << "Combo values for i-1 " << DeciCombos[decimalValue-1] << endl;
        //cout << "                 i   " << DeciCombos[decimalValue] << endl;

        indexN -= DeciCombos[decimalValue-1];
        assert(indexN > 0);

        int deciBinary = 0;        // result

        // Maximum power of 2 that can be used for this decimal value
        int pow2 = int(log2(decimalValue));
        assert(pow2 > 0);

        return GetDeciBinary(decimalValue, indexN, pow2);
    }


};

void test()
{
    DeciNumber deciNumber; 
    assert(deciNumber.GetDecimalAtIndex(1) == 0);
    assert(deciNumber.GetDecimalAtIndex(2) == 1);
    assert(deciNumber.GetDecimalAtIndex(7) == 4);
    assert(deciNumber.GetDecimalAtIndex(8) == 4);
    assert(deciNumber.GetDecimalAtIndex(10) == 4);

    //cout << "Size in MiB = " << deciNumber.GetSize()/(1000*1000) << endl;
    
    assert(myPow(2,0) == 1);
    assert(myPow(2,2) == 4);
    assert(myPow(10,4) == 10000);
    assert(myPow(10,14) == 100000000000000ULL);
    assert(myPow(10,15) == 1000000000000000ULL);
    assert(myPow(10,16) == 10000000000000000ULL);


    assert(deciNumber.GetDeciBinary(3716282173562748) == 21102583914947437);
    assert(deciNumber.GetDeciBinary(6900926474930045) == 14018710175370495 );
}


int main()
{
    //test();

    DeciNumber deciNumber; 

    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        uint64_t x;
        cin >> x;
        cout << deciNumber.GetDeciBinary(x) << endl;
    }
}
