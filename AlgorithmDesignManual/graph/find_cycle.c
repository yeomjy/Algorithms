#include "dfs.h"
#include "graph.h"
#include <stdbool.h>
#include <stdio.h>

void process_edge(int x, int y)
{
    if (discovered[y] && (parent[x] != y))
    {
        printf("Cycle from %d to %d\n", x, y);
        find_path(y, x, parent);
        printf("\n\n");
        finished = true;
    }
}

void process_vertex_early(int v)
{
}

void process_vertex_late(int v)
{
}

int main()
{
    graph g;
    initialize_graph(&g, false);
    read_graph(&g, false);
    dfs(&g, 1);
}