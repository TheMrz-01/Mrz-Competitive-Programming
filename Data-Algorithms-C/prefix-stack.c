#include <stdio.h>
#include <ctype.h>  
#include <string.h> 
#include <stdlib.h> 

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluatePrefix(char* expr) {
    Stack stack;
    init(&stack);
    int n = strlen(expr);

    for (int i = n - 1; i >= 0; i--) {
        if (isdigit(expr[i])) {
            push(&stack, expr[i] - '0');
        }
        else if (isOperator(expr[i])) {
            int op1 = pop(&stack);
            int op2 = pop(&stack);

            switch (expr[i]) {
                case '+': push(&stack, op1 + op2); break;
                case '-': push(&stack, op1 - op2); break;
                case '*': push(&stack, op1 * op2); break;
                case '/': push(&stack, op1 / op2); break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char expr[] = "-+7*45+20";
    printf("The result of the prefix expression '%s' is: %d\n", expr, evaluatePrefix(expr));
    return 0;
}