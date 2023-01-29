#ifndef _QUEUE
#define _QUEUE
#include "list.h"
#include <stdbool.h>

typedef struct queue
{
    int size;
    struct node *head;
    struct node *tail;
} queue;

void init_queue(queue *q);

void enqueue(queue *q, int item);
int dequeue(queue *q);
bool empty_queue(queue *q);

void print_queue(queue *q);

#endif