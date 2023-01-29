#include "queue.h"
#include <stdio.h>

int main()
{
    queue q;
    init_queue(&q);

    enqueue(&q, 0);
    print_queue(&q);
    printf("Expected: 0\n\n");
    dequeue(&q);
    print_queue(&q);
    printf("Expected: \n\n");

    enqueue(&q, 2);
    enqueue(&q, 3);
    print_queue(&q);
    printf("Expected: 2 3\n\n");
    dequeue(&q);
    print_queue(&q);
    printf("Expected: 3\n\n");
    dequeue(&q);
    print_queue(&q);
    printf("Expected: \n\n");

    enqueue(&q, 1);
    enqueue(&q, 4);
    enqueue(&q, 3);
    enqueue(&q, 7);
    print_queue(&q);
    printf("Expected: 1 4 3 7\n\n");
    dequeue(&q);
    print_queue(&q);
    printf("Expected: 4 3 7\n\n");
}