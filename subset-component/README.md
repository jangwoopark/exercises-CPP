You are given an array with  -bit integers: .

BIT(x, i) = (x >> i) & 1. (where  is the  lower bit of  in binary form.)

If we regard every bit as a vertex of a graph G, there exists one undirected edge between vertex  and vertex  if there exists at least one k such that BIT(d[k], i) == 1 && BIT(d[k], j) == 1.

For every subset of the input array, how many connected-components are there in that graph?

The number of connected-components in a graph are the sets of nodes, which are accessible to each other, but not to/from the nodes in any other set.

For example if a graph has six nodes, labelled . And contains the edges . There are three connected-components: ,  and . Because  can be accessed from each other through one or more edges,  can access each other and  is isolated from everone else.

You only need to output the sum of the number of connected-component() in every graph.

Input Format

n
d[0] d[1] ... d[n - 1]
Constraints



Output Format

Print the value of .

Sample Input 1

CopyDownload
Array: d
2
5
9

 
3
2 5 9
Sample Output 1

504

Explanation 1

There are  subset of .

{}
=> We don't have any number in this subset => no edge in the graph => Every node is a component by itself => Number of connected-components = 64.

{2}
=> The Binary Representation of 2 is . There is a bit at only one position. => So there is no edge in the graph, every node is a connected-component by itself => Number of connected-components = 64.

{5}
=> The Binary Representation of 5 is . There is a bit at the 0th and 2nd position. => So there is an edge: (0, 2) in the graph => There is one component with a pair of nodes (0,2) in the graph. Apart from that, all remaining 62 vertices are indepenent components of one node each (1,3,4,5,6...63) => Number of connected-components = 63.

{9}
=> The Binary Representation of 9 is . => There is a 1-bit at the 0th and 3rd position in this binary representation. => edge: (0, 3) in the graph => Number of components = 63

{2, 5}
=> This will contain the edge (0, 2) in the graph which will form one component
=> Other nodes are all independent components
=> Number of connected-component = 63

{2, 9}
=> This has edge (0,3) in the graph
=> Similar to examples above, this has 63 connected components

{5, 9}
=> This has edges (0, 2) and (0, 3) in the graph
=> Similar to examples above, this has 62 connected components

{2, 5, 9}
=> This has edges(0, 2) (0, 3) in the graph. All three vertices (0,2,3) make one component => Other 61 vertices are all independent components
=> Number of connected-components = 62



