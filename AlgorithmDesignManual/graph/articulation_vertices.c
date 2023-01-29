#include "dfs.h"
#include "edge_classification.h"
#include "graph.h"
#include <stdio.h>

int reachable_ancestor[MAXV + 1];
int tree_out_degree[MAXV + 1];

void process_vertex_early(int v)
{
    reachable_ancestor[v] = v;
}

void process_edge(int x, int y)
{
    edgeclass class = edge_classification(x, y);
    if (class == TREE)
    {
        tree_out_degree[x] = tree_out_degree[x] + 1;
    }
    if ((class == BACK) && (parent[x] != y))
    {
        if (entry_time[y] < entry_time[reachable_ancestor[x]])
            reachable_ancestor[x] = y;
    }
}

void process_vertex_late(int v)
{
    bool root;
    int time_v;
    int time_parent;
    if (parent[v] < 1)
    {
        if (tree_out_degree[v] > 1)
            printf("root articulation vertex: %d\n", v);
    }

    root = (parent[parent[v]] < 1);
    if (!root)
    {
        if (reachable_ancestor[v] == parent[v])
        {
            printf("parent articulation vetex: %d\n", parent[v]);
        }
        if (reachable_ancestor[v] == v)
        {
            printf("bridge articulation vertex: %d\n", parent[v]);
            if (tree_out_degree[v] > 0)
            {
                printf("bridge articulation vertex: %d\n", v);
            }
        }
        time_v = entry_time[reachable_ancestor[v]];
        time_parent = entry_time[reachable_ancestor[parent[v]]];

        if (time_v < time_parent)
            reachable_ancestor[parent[v]] = reachable_ancestor[v];
    }
}

int main()
{
    graph g;
    initialize_graph(&g, false);
    read_graph(&g, false);

    dfs(&g, 1);
}
