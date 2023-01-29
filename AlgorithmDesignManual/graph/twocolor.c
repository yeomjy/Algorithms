#include "bfs.h"
#include "graph.h"
#include <stdbool.h>
#include <stdio.h>

enum
{
    UNCOLORED = -1,
    WHITE = 1,
    BLACK = 0
};

int color[MAXV + 1];
bool bipartite;

void twocolor(graph *g)
{
    int i;
    for (i = 1; i <= g->nvertices; i++)
        color[i] = UNCOLORED;

    bipartite = true;
    initialize_search(g);

    for (i = 1; i <= g->nvertices; i++)
    {
        if (discovered[i] == false)
        {
            color[i] = WHITE;
            bfs(g, i);
        }
    }
}

int complement(int color)
{
    if (color == WHITE)
        return BLACK;
    if (color == BLACK)
        return WHITE;
    return UNCOLORED;
}

void process_edge(int x, int y)
{
    if (color[x] == color[y])
    {
        bipartite = false;
        printf("Warning: not bipartite due to (%d, %d)\n", x, y);
    }
    color[y] = complement(color[x]);
}

void process_vertex_early(int v)
{
    // printf("processed vertex %d\n", v);
}
void process_vertex_late(int v)
{
    // printf("processed vertex %d late\n", v);
}

int main()
{
    graph g;
    initialize_graph(&g, false);
    read_graph(&g, false);
    twocolor(&g);
    for (int i = 1; i <= g.nvertices; i++)
    {
        if (color[i] == WHITE)
            printf("Node %d: WHITE\n", i);
    }
    for (int i = 1; i <= g.nvertices; i++)
    {
        if (color[i] == BLACK)
            printf("Node %d: BLACK\n", i);
    }
}