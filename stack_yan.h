// Yan Campêlo das Chagas

#ifndef stack_yan_h
#define stack_yan_h

#include <stdio.h>
#define MAX 100
#define true 1
#define false 0

typedef int tp_item;

typedef struct{
    int topo;
    tp_item item[MAX];
} Stack;

int start_stack(Stack *ptStack){
    ptStack->topo = -1;
    return 1;
}

int stack_empty(Stack *ptStack){
    if (ptStack->topo == -1)
        return true;
    return false;
}

int stack_full(Stack *ptStack){
    if (ptStack->topo == (MAX - 1))
        return true;
    return false;
}

int push(Stack *ptStack, tp_item element){
    if (stack_full(ptStack))
        return false;
    ptStack->topo++;
    ptStack->item[ptStack->topo] = element;
    return true;
}

int pop(Stack *ptStack, tp_item *answer){
    if (stack_empty(ptStack))
        return false;
    *answer = ptStack->item[ptStack->topo];
    ptStack->topo--;
    return true;
}

int top(Stack *ptStack, tp_item *answer){
    if (stack_empty(ptStack))
        return false;
    *answer = ptStack->item[ptStack->topo];
    return true;
}

int stack_height(Stack *ptStack){
    return (ptStack->topo + 1);
}

int compare_stack(Stack stack1, Stack stack2){
    if (stack_empty(&stack2))
        return -1;
    if (stack_height(&stack1) == stack_height(&stack2)){
        while (!stack_empty(&stack1)){
            tp_item ans1, ans2;
            pop(&stack1, &ans1); pop(&stack2, &ans2);
            if (ans1 != ans2)
                return false;
        }
        return true;
    }
    return false;
}

int invert_stack(Stack *ptStack){
    if (stack_empty(ptStack))
        return false;
    int h_stack = stack_height(ptStack), control = 0;
    tp_item aux_array[h_stack];
    while (!stack_empty(ptStack)){
        tp_item aux;
        pop(ptStack, &aux);
        aux_array[control] = aux;
        control++;
    }
    control = 0;
    while (control < h_stack){
        push(ptStack, aux_array[control]);
        control++;
    }
    return true;
}

int stack_the_stack(Stack *ptStack1, Stack ptStack2){
    if ((stack_height(ptStack1) + stack_height(&ptStack2)) > MAX || (stack_empty(ptStack1) || stack_empty(&ptStack2)))
        return false;
    while (!stack_empty(&ptStack2)){
        tp_item element;
        pop(&ptStack2, &element);
        push(ptStack1, element);
    }
    return true;
}

int show_stack(Stack stack){
    if (stack_empty(&stack))
        return false;
    tp_item show;
    printf("\n");
    while (!(stack_empty(&stack))){
        pop(&stack, &show);
        printf("%c\n", show);
    }
    return true;
}

#endif