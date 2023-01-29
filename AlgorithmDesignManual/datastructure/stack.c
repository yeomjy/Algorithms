#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(stack *s)
{
    s->size = 0;
    s->top = NULL;
}

void push(stack *s, int item)
{
    node *p = (node *)malloc(sizeof(node));
    p->item = item;
    p->prev = s->top;
    s->top = p;
    s->size++;
}

int pop(stack *s)
{
    if (s->size == 0)
        exit(EXIT_FAILURE);

    int ret = s->top->item;
    node *temp = s->top;
    s->top = s->top->prev;

    free(temp);
    s->size--;
    return ret;
}

bool empty_stack(stack *s)
{
    return s->size == 0;
}

void print_stack(stack *s)
{
    node *temp = s->top;
    int idx = s->size;

    printf("------------------------------\n");

    while (temp != NULL)
    {
        printf("Item at %d = %d\n", idx--, temp->item);
        temp = temp->prev;
    }
    printf("Total size of stack: %d\n", s->size);

    printf("------------------------------\n");
}