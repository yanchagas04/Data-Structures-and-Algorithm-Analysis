// Yan Campêlo das Chagas

#ifndef queue_yan_h
#define queue_yan_h
#include <stdio.h>

#define MAX 100
#define true 1
#define false 0
#define or ||
#define and &&

typedef int
    tp_item;

typedef struct {
    int start;
    int end;
    tp_item item[MAX];
} Queue;

void start_queue(Queue *ptQueue){
    ptQueue->start = MAX - 1;
    ptQueue->end = MAX - 1;
}

int queue_empty(Queue *ptQueue){
    if (ptQueue->end == ptQueue->start)
        return true;
    return false;
}

int queue_full(Queue *ptQueue){
    if ((ptQueue->start == 0 and ptQueue->end == MAX - 1) or (ptQueue->end == ptQueue->start - 1)){
        return true;
    }
    return false;
}

int enqueue(Queue *ptQueue, tp_item element){
    if (queue_full(ptQueue))
        return false;
    if (ptQueue->end == MAX - 1)
        ptQueue->end = 0;
    else
        ptQueue->end++;
    ptQueue->item[ptQueue->end] = element;
    return true;
}

int unqueue(Queue *ptQueue, tp_item *out){
    if (queue_empty(ptQueue))
        return false;
    if (ptQueue->start == MAX - 1)
        ptQueue->start = 0;
    else
        ptQueue->start++;
    *out = ptQueue->item[ptQueue->start];
    return true;
}

int inicio_da_fila(Queue *ptQueue, tp_item *out){
    if (queue_empty(ptQueue))
        return false;
    *out = ptQueue->item[ptQueue->start + 1];
    return true;
}

int queue_lenght(Queue *ptQueue){
    if (ptQueue->start > ptQueue->end)
        return ((ptQueue->end + 1) + (MAX - 1 - ptQueue->start));
    return (ptQueue->end - ptQueue->start);
}

int show_queue(Queue queue){
    if (queue_empty(&queue))
        return false;
    printf("\n[ ");
    while (!queue_empty(&queue)){
        tp_item aux;
        unqueue(&queue, &aux);
        printf("%d ", aux);
    }
    printf("]\n");
    return true;
}


#endif