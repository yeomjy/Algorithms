#ifndef _STACK
#define _STACK
#include "list.h"
#include <stdbool.h>

typedef struct stack
{
    int size;
    struct node *top;
} stack;

void init_stack(stack *s);
void push(stack *s, int item);
int pop(stack *s);
bool empty_stack(stack *s);
void print_stack(stack *s);

#endif