#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;
void stackPush(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}
int stackPop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return 0; 
}
int evaluateRPN(char **tokens, int tokensSize) {
    Stack stack = {.top = -1};

    for (int i = 0; i < tokensSize; i++) {
        char *token = tokens[i];

        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            
            stackPush(&stack, atoi(token));
        } else {
                int b = stackPop(&stack);
            int a = stackPop(&stack);
            int result = 0;

            if (strcmp(token, "+") == 0) {
                result = a + b;
            } else if (strcmp(token, "-") == 0) {
                result = a - b;
            } else if (strcmp(token, "*") == 0) {
                result = a * b;
            } else if (strcmp(token, "/") == 0) {
                result = a / b;
            }

            
            stackPush(&stack, result);
        }
    }
return stackPop(&stack);
}

int main() {
    char *tokens[] = {"2", "1", "+", "3", "*"};
    int tokensSize = sizeof(tokens) / sizeof(tokens[0]);

    int result = evaluateRPN(tokens, tokensSize);
    printf("Result: %d\n", result); // Output: 9

    return 0;
}
