#ifndef _DFS
#define _DFS

#include "graph.h"
extern bool processed[MAXV + 1];
extern bool discovered[MAXV + 1];
extern int parent[MAXV + 1];
extern int entry_time[MAXV + 1];
extern int exit_time[MAXV + 1];
extern bool finished;
extern int time;

void initialize_search(graph *g);
void dfs(graph *g, int start);
extern void process_vertex_early(int v);
extern void process_vertex_late(int v);
extern void process_edge(int x, int y);
void find_path(int start, int end, int *parents);

#endif