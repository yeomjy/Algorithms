#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void init_queue(queue *q)
{
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(queue *q, int item)
{
    node *p = (node *)malloc(sizeof(node));
    p->item = item;
    if (q->size == 0)
    {
        p->prev = NULL;
        p->next = NULL;
        q->head = p;
        q->tail = p;
    }
    else if (q->size == 1)
    {
        p->next = NULL;
        p->prev = q->head;
        q->head->next = p;
        q->tail = p;
    }
    else
    {
        p->next = NULL;
        q->tail->next = p;
        p->prev = q->tail;
        q->tail = p;
    }
    q->size++;
}

int dequeue(queue *q)
{
    if (q->size == 0)
        exit(EXIT_FAILURE);
    int ret = q->head->item;
    node *temp = q->head;
    if (q->size == 1)
    {
        q->head = q->tail = NULL;
    }
    else if (q->size == 2)
    {
        q->head = q->tail;
        q->head->prev = NULL;
    }
    else
    {
        q->head = q->head->next;
        q->head->prev = NULL;
    }
    free(temp);
    q->size--;
    return ret;
}

bool empty_queue(queue *q)
{
    return q->size == 0;
}

void print_queue(queue *q)
{
    if (q->size > 0 && (q->head->prev != NULL || q->tail->next != NULL))
    {
        printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    node *temp = q->head;
    int idx = 1;
    printf("------------------------------\n");

    while (temp != NULL)
    {
        printf("Item at %d = %d\n", idx++, temp->item);
        temp = temp->next;
    }
    printf("Total size of queue: %d\n", q->size);
    printf("------------------------------\n");
}