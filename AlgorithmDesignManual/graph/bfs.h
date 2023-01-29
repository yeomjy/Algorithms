#ifndef _BFS
#define _BFS
#include "../datastructure/queue.h"
#include "graph.h"
#include <stdbool.h>
extern bool processed[MAXV + 1];
extern bool discovered[MAXV + 1];
extern int parent[MAXV + 1];

void initialize_search(graph *g);
void bfs(graph *g, int start);
extern void process_vertex_early(int v);
extern void process_vertex_late(int v);
extern void process_edge(int x, int y);
void find_path(int start, int end, int *parents);

#endif
