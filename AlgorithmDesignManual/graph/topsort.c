#include "../datastructure/stack.h"
#include "dfs.h"
#include "edge_classification.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

stack sorted;
void topsort(graph *g);

int main()
{
    graph g;
    initialize_graph(&g, true);
    read_graph(&g, true);

    topsort(&g);
}

void topsort(graph *g)
{
    int i;
    init_stack(&sorted);
    for (i = 1; i <= g->nvertices; i++)
        if (discovered[i] == false)
            dfs(g, i);

    print_stack(&sorted);
}

void process_vertex_early(int v)
{
}
void process_vertex_late(int v)
{
    push(&sorted, v);
}

void process_edge(int x, int y)
{
    edgeclass class = edge_classification(x, y);
    if (class == BACK)
    {
        printf("Warning: directed cycle from %d to %d found, not a DAG\n", x, y);
        find_path(y, x, parent);
        exit(EXIT_FAILURE);
    }
}
