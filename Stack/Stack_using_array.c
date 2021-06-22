#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

struct Stack{
    int top;
    int max;
    int *arr;
};

struct Stack* create(int max1){
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct  Stack));
    stack->max = max1;
    stack->top = -1;
    stack->arr = (int *)malloc(sizeof(int )*(stack->max));
    return stack;
}

int isEmpty(struct Stack* stack){
    return stack->top==-1;
}

int isFull(struct Stack* stack){
    return stack->top == stack->max-1;
}
int pop(struct Stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    int x = stack->arr[stack->top-1];
    stack->top--;
    return x;
}

void push(struct Stack* stack, int x){
    if(isFull(stack))
        return ;
    stack->arr[stack->top++] = x;
    printf("%d pushed !!\n",x);
    return;
}

int peek(struct Stack* stack){
    if(stack->top == -1)
        return INT_MIN;
    return stack->arr[stack->top];
}

int main(){
    struct Stack* stack = create(10);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printf("%d popped!!\n",pop(stack));
    printf("%d popped!!\n",pop(stack));
    printf("%d popped!!\n",pop(stack));
}