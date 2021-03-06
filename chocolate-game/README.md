Laurel and Hardy have  piles of chocolates with each pile containing some number of chocolates. The piles are arranged from left to right in a non decreasing order based on the number of chocolates in each pile. They play the following game.

For every continuous subsequence of chocolate piles (at least 2 piles form a subsequence), Laurel and Hardy will play game on this subsequence of chocolate piles, Laurel plays first, and they play in turn. In one move, the player can choose one of the piles and remove at least one chocolate from it, but the non-decreasing order of the chocolate piles must be maintained. The last person to make a valid move wins.

How many continuous subsequences of chocolate piles will Laurel win if both of them play optimally? The number of chocolates of each pile will be recovered after the game ends for each subsequences.

Input Format

The first line contains an integer  denoting the number of piles.
The second line contains the number of chocolates in each pile, arranged from left to right and separated by a single space between them.

Constraints

 ≤  ≤ 
 ≤     ≤ 

Output Format

A single integer denoting the number of continuous subsequences of chocolate piles in which Laurel will win.

Sample Input

5
1 1 2 2 3
Sample Output

5
Explanation

Of the 10 continuous-sub-sequence of chocolate piles,

Laurel loses in [1,1], [1,1,2], [1,1,2,2], [1,2,2,3], [2,2] and
wins in [1,1,2,2,3], [1,2], [1,2,2], [2,2,3] and [2,3] and hence 5.
