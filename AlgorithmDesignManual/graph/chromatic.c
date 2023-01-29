#include "../datastructure/queue.h"
#include "graph.h"
#include <stdbool.h>
#include <stdio.h>

int color[MAXV + 1];

void search(graph *g, int start);
int find_color(int arr[2]);

int main()
{
    graph g;
    initialize_graph(&g, false);
    read_graph(&g, false);

    for (int i = 1; i <= g.nvertices; i++)
    {
        color[i] = -1;
    }

    search(&g, 1);

    for (int i = 1; i <= g.nvertices; i++)
    {
        printf("Vertex %d: color %d\n", i, color[i]);
    }
}
void search(graph *g, int start)
{
    queue q;
    init_queue(&q);
    int y;

    int arr[2];

    edgenode *p;

    enqueue(&q, start);
    color[start] = 0;

    while (!empty_queue(&q))
    {
        arr[0] = arr[1] = -1;
        int v = dequeue(&q);

        p = g->edges[v];
        int i = 0;

        while (p != NULL)
        {
            y = p->y;
            if (color[y] == -1)
            {
                color[y] = 0;
                enqueue(&q, y);
            }
            else
            {
                // store adjacent vertices' color
                arr[i++] = color[y];
            }
            p = p->next;
        }
        // update its color
        color[v] = find_color(arr);
    }
}

int find_color(int arr[2])
{
    int i = 0;

    if (arr[0] == 0 || arr[1] == 0)
    {
        i = 1;
        if (arr[0] == 1 || arr[1] == 1)
            i = 2;
    }

    return i;
}
