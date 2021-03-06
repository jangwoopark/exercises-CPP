Consider a lowercase English alphabetic letter character denoted by . A shift operation on some  turns it into the next letter in the alphabet. For example, and , ,  .

Given a zero-indexed string, , of  lowercase letters, perform  queries on  where each query takes one of the following two forms:

1 i j t: All letters in the inclusive range from  to  are shifted  times.
2 i j: Consider all indices in the inclusive range from  to . Find the number of non-empty subsets of characters,  where , such that characters  can be rearranged to form a palindrome. Then print this number modulo  on a new line. Two palindromic subsets are considered to be different if their component characters came from different indices in the original string.
Note Two palindromic subsets are considered to be different if their component characters came from different indices in the original string.

Input Format

The first line contains two space-separated integers describing the respective values of  and .
The second line contains a string of  lowercase English alphabetic letters (i.e., a through z) denoting .
Each of the  subsequent lines describes a query in one of the two formats defined above.

Constraints

 for each query.
 for each query of type .
Subtasks

For  of the maximum score:

For another  of the maximum score:

All queries will be of type .
Output Format

For each query of type  (i.e., 2 i j), print the number of non-empty subsets of characters satisfying the conditions given above, modulo , on a new line.

Sample Input 0

3 5
aba
2 0 2
2 0 0
2 1 2
1 0 1 1
2 0 2
Sample Output 0

5
1
2
3
Explanation 0

We perform the following  queries:

2 0 2:  and we want to find the palindromic subsets of substring . There are five such subsets that form palindromic strings (, , , , and ), so we print the result of  on a new line
2 0 0:  and we want to find the palindromic subsets of substring . Because this substring only has one letter, we only have one subset forming a palindromic string (). We then print the result of  on a new line.
2 1 2:  and we want to find the palindromic subsets of substring . There are two such subsets that form palindromic strings ( and ), so we print the result of  on a new line.
1 0 1 1:  and we need to perform  shift operations on each character from index  to index . After performing these shifts, .
2 0 2:  and we want to find the palindromic subsets of substring . There are three valid subsets that form palindromic strings (, , and ), so we print the result of  on a new line.
