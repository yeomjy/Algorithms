#include "edge_classification.h"
#include <stdio.h>

edgeclass edge_classification(int x, int y)
{
    if (parent[y] == x)
        return TREE;
    if (discovered[y] && !processed[y])
        return BACK;
    if (processed[y] && (entry_time[y] > entry_time[x]))
        return FORWARD;
    if (processed[y] && (entry_time[y] < entry_time[x]))
        return CROSS;

    printf("Warning: unclassified edge (%d, %d)\n", x, y);
    return UNCLASSIFIED;
}