Tara has an array, , consisting of  integers where each integer occurs at most  times in the array.

Let's define  to be a permutation of  where  is the  element of permutation . Tara thinks a permutation is beautiful if there is no index  such that  where .

You are given  queries where each query consists of some array . For each , help Tara count the number of possible beautiful permutations of the  integers in  and print the count, modulo , on a new line.

Note: Two permutations,  and , are considered to be different if and only if there exists an index  such that  and .

Input Format

The first line contains a single integer, , denoting the number of queries. The  subsequent lines describe each query in the following form:

The first line contains an integer, , denoting the number of elements in array .
The second line contains  space-separated integers describing the respective values of  in array .
Constraints

Each integer in  can occur at most  times.
For  of the maximum score:

The sum of  over all queries does not exceed .
For  of the maximum score:

Output Format

For each query, print the the number of possible beautiful permutations, modulo , on a new line.

Sample Input 0

3
3
1 1 2
2
1 2
4
1 2 2 1
Sample Output 0

1
2
2
Explanation 0

We perform the following  queries:

Array  and there is only one good permutation:
image
Thus, we print the result of  on a new line.

Array  and there are two good permutations:
image
Thus, we print the result of  on a new line.

Array  and there are two good permutations:
image
For demonstration purposes, the following two permutations are invalid (i.e., not good):
image
Because we only want the number of good permutations, we print the result of  on a new line.
