#ifndef _EDGE_CLASSIFICATION
#define _EDGE_CLASSIFICATION

#include "graph.h"
#include "dfs.h"
#include <stdbool.h>
typedef enum
{
    TREE,
    BACK,
    FORWARD,
    CROSS,
    UNCLASSIFIED
} edgeclass;

edgeclass edge_classification(int x, int y);

#endif