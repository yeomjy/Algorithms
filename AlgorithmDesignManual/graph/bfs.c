#include "bfs.h"
#include <stdbool.h>
#include <stdio.h>

bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV + 1];

void initialize_search(graph *g)
{
    int i;
    for (i = 1; i <= g->nvertices; i++)
    {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}

void bfs(graph *g, int start)
{
    queue q;
    int v;
    int y;
    edgenode *p;

    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = true;

    while (!empty_queue(&q))
    {
        v = dequeue(&q);
        process_vertex_early(v);
        processed[v] = true;
        p = g->edges[v];
        while (p != NULL)
        {
            y = p->y;
            if ((!processed[y]) || g->directed)
            {
                process_edge(v, y);
            }
            if (!discovered[y])
            {
                enqueue(&q, y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        process_vertex_late(v);
    }
}

void find_path(int start, int end, int *parents)
{
    if ((start == end) || (end == -1))
    {
        printf("\n%d", start);
    }
    else
    {
        find_path(start, parents[end], parents);
        printf(" %d", end);
    }
}
