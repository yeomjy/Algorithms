#ifndef _LIST
#define _LIST

typedef struct node
{
    int item;
    struct node *prev;
    struct node *next;
} node;
#endif