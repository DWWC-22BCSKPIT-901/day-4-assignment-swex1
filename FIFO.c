#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;
typedef struct {
    Stack stack1;
    Stack stack2;
} MyQueue;
void stackPush(Stack *stack, int x) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = x;
    }
}
int stackPop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return -1; 
}int stackPeek(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    }
    return -1; 
}

bool stackEmpty(Stack *stack) {
    return stack->top == -1;
}
MyQueue* myQueueCreate() {
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->stack1.top = -1;
    queue->stack2.top = -1;
    return queue;
}
void myQueuePush(MyQueue *queue, int x) {
    stackPush(&queue->stack1, x);
}

int myQueuePop(MyQueue *queue) {
    if (stackEmpty(&queue->stack2)) {
        
        while (!stackEmpty(&queue->stack1)) {
            stackPush(&queue->stack2, stackPop(&queue->stack1));
        }
    }
    return stackPop(&queue->stack2);
}

int myQueuePeek(MyQueue *queue) {
    if (stackEmpty(&queue->stack2)) {
        // Transfer elements from stack1 to stack2
        while (!stackEmpty(&queue->stack1)) {
            stackPush(&queue->stack2, stackPop(&queue->stack1));
        }
    }
    return stackPeek(&queue->stack2);
}

bool myQueueEmpty(MyQueue *queue) {
    return stackEmpty(&queue->stack1) && stackEmpty(&queue->stack2);
}

void myQueueFree(MyQueue *queue) {
    free(queue);
}
int main() {
    MyQueue *queue = myQueueCreate();

    myQueuePush(queue, 1);
    myQueuePush(queue, 2);
    printf("Front element: %d\n", myQueuePeek(queue)); 
    printf("Popped element: %d\n", myQueuePop(queue));
    printf("Queue empty: %s\n", myQueueEmpty(queue) ? "true" : "false"); 

    myQueueFree(queue);
    return 0;
}
