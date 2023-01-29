#include "bfs.h"
#include "graph.h"
#include <stdio.h>

int main()
{
    graph g;
    initialize_graph(&g, false);
    read_graph(&g, false);

    print_graph(&g);

    initialize_search(&g);
    bfs(&g, 1);
    find_path(1, 4, parent);
    return EXIT_SUCCESS;
}

void process_vertex_early(int v)
{
    printf("processed vertex %d\n", v);
}
void process_vertex_late(int v)
{
    printf("processed vertex %d late\n", v);
}
void process_edge(int x, int y)
{
    printf("processed edge (%d, %d)\n", x, y);
}
