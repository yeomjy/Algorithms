# Proof of Exercise 5.5 (Chromatic Number of Deg(v) <= 2)
## Running Time
It runs at linear time because we only do single bfs and degree of each vertex is bounded by constant 

## Correctness 
It is obvious that this algorithm always prints (number of color <= 3 = deg(v) + 1)
We only have to prove its optimality.
The case that chromatic number = 1 is obvious (no edge)
Therefore, we only need to show that it prints chromatic number 2 when bipartite graph is given.
Since we traverse by BFS, if we are processing a black vertex, then 
the adjacents are all white, and vice versa.
Therefore it only outputs chromatic number 2, as desired.

# Proof of Exercise 5.15 (Finding Independent Vertex Cover)
## G has Independent Vertex Cover <=> G is bipartite
First, if G is bipartite, it is obvious.
Let us assume that G is not bipartite, 
then there exists v1, v2, v3 such that it has color 1, 2, 3 and (v1, v3) in E, (v2, v3) in E,
and there exists a odd-length path from v1 to v2.
Then, first, minimum vertex cover should contain v1, v2.
and color(v1) != color(v2), then it is contradict to the fact that it is independent.