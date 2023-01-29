#include <stdio.h>
#include "graph.h"
#include "edge_classification.h"
#include "dfs.h"
#include "../datastructure/stack.h"

stack active;
int low[MAXV + 1];
int scc[MAXV + 1];
int components_found;

void pop_component(int v);
void strong_components(graph *g);

int main()
{
    graph g;
    initialize_graph(&g, true);
    read_graph(&g, true);

    strong_components(&g);

    for (int i = 1; i <= g.nvertices; i++)
    {
        printf("Vertex %d: component %d\n", i, scc[i]);
    }
}

void process_edge(int x, int y)
{
    edgeclass class = edge_classification(x, y);
    if (class == BACK)
    {
        if (entry_time[y] < entry_time[low[x]])
        {
            low[x] = y;
        }
        if (class == CROSS)
        {
            if (scc[y] == -1)
            {
                if (entry_time[y] < entry_time[low[x]])
                {
                    low[x] = y;
                }
            }
        }
    }
}

void process_vertex_early(int v)
{
    push(&active, v);
}

void process_vertex_late(int v)
{
    if (low[v] == v)
        pop_component(v);

    if (parent[v] > 0)
        if (entry_time[low[v]] < entry_time[low[parent[v]]])
            low[parent[v]] = low[v];
}

void pop_component(int v)
{
    int t;
    components_found += 1;
    scc[v] = components_found;
    while ((t = pop(&active)) != v)
    {
        scc[t] = components_found;
    }
}

void strong_components(graph *g)
{
    int i;
    for (i = 1; i <= (g->nvertices); i++)
    {
        low[i] = i;
        scc[i] = -1;
    }
    components_found = 0;
    init_stack(&active);
    initialize_search(g);

    for (i = 1; i <= (g->nvertices); i++)
    {
        if (!discovered[i])
        {
            dfs(g, i);
        }
    }
}