#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

void createQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q,int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)){
        q->front = q->rear = newNode;
        q->rear->next = q->front;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }    
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!");
        return;
    }

    int value;
    Node *temp = q->front;

    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    }
    else{
        q->front = q->front->next;
        q->rear->next = q->front;
        value = temp->data;
        free(temp);
    }

    printf("%d dequeued from the queue\n", value);
    return value;
}

void display(Queue *q){
    Node* temp = q->front;

    do{
        printf("%d <- ",temp->data);
        temp = temp->next;
    }while(temp != q->front);

    printf("\n");
}

int main(int argc,char *argv[]){
    if(argc > 1){
        return 0;
    }
    
    printf("Started");

    Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 50);
    enqueue(&q, 60);

    display(&q);

    int closeWindow;
    scanf("%d",&closeWindow);

    return 0;
}