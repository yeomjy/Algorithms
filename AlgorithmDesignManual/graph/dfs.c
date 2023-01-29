#include "dfs.h"
#include "graph.h"
#include <stdbool.h>
#include <stdio.h>

bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV + 1];
int entry_time[MAXV + 1];
int exit_time[MAXV + 1];
bool finished;
int time;

void initialize_search(graph *g)
{
    int i;
    for (i = 1; i <= g->nvertices; i++)
    {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
    finished = false;
    time = 0;
}

void dfs(graph *g, int v)
{
    edgenode *p;
    int y;
    if (finished)
        return;

    discovered[v] = true;
    time = time + 1;
    entry_time[v] = time;

    process_vertex_early(v);
    p = g->edges[v];
    while (p != NULL)
    {
        y = p->y;
        if (!discovered[y])
        {
            parent[y] = v;
            process_edge(v, y);
            dfs(g, y);
        }
        else if ((!processed[y] && (parent[v] != y)) || (g->directed))
        {
            process_edge(v, y);
        }
        if (finished)
            return;

        p = p->next;
    }
    process_vertex_late(v);
    time = time + 1;
    exit_time[v] = time;
    processed[v] = true;
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
