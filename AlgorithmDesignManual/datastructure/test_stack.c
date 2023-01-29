#include "stack.h"
#include <stdio.h>

int main()
{
    stack s;
    init_stack(&s);

    push(&s, 0);
    print_stack(&s);
    printf("Expected: 0\n\n");
    pop(&s);
    print_stack(&s);
    printf("Expected: \n\n");

    push(&s, 2);
    push(&s, 3);
    print_stack(&s);
    printf("Expected: 3 2\n\n");
    pop(&s);
    print_stack(&s);
    printf("Expected: 2\n\n");
    pop(&s);
    print_stack(&s);
    printf("Expected: \n\n");

    push(&s, 1);
    push(&s, 4);
    push(&s, 3);
    push(&s, 7);
    print_stack(&s);
    printf("Expected: 7 3 4 1\n\n");
    pop(&s);
    print_stack(&s);
    printf("Expected: 3 4 1\n\n");
}
