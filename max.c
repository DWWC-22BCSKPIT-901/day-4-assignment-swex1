#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct {
    int stack[MAX_SIZE];
    int min_stack[MAX_SIZE];
    int top;
    int min_top;
} MinStack;
void minStackInit(MinStack *obj) {
    obj->top = -1;
    obj->min_top = -1;
}
void minStackPush(MinStack *obj, int val) {
    obj->stack[++(obj->top)] = val; 
    if (obj->min_top == -1 || val <= obj->min_stack[obj->min_top]) {
        obj->min_stack[++(obj->min_top)] = val; 
}
void minStackPop(MinStack *obj) {
    if (obj->stack[obj->top] == obj->min_stack[obj->min_top]) {
        obj->min_top--; 
    }
    obj->top--; 
int minStackTop(MinStack *obj) {
    return obj->stack[obj->top];
}
int minStackGetMin(MinStack *obj) {
    return obj->min_stack[obj->min_top];
}
int main() {
    MinStack minStack;
    minStackInit(&minStack);

    minStackPush(&minStack, 5);
    minStackPush(&minStack, 3);
    minStackPush(&minStack, 7);

    printf("Minimum: %d\n", minStackGetMin(&minStack)); 
    minStackPop(&minStack);
    printf("Top: %d\n", minStackTop(&minStack));        
    printf("Minimum: %d\n", minStackGetMin(&minStack)); 

    minStackPop(&minStack);
    printf("Minimum: %d\n", minStackGetMin(&minStack)); 

    return 0;
}
