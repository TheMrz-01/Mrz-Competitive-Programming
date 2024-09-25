#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->items[++(s->top)] = value;
    printf("%d pushed to stack\n", value);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top];
}


int main(int argc,char *argv[]){
    if(argc > 1){
        return 0;
    }
    
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is %d\n", peek(&s));

    printf("%d popped from stack\n", pop(&s));
    printf("Top element is now %d\n", peek(&s));

    int closeWindow;
    scanf("%d",&closeWindow);

    return 0;
}