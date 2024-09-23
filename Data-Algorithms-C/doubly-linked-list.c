#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node *head,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL){
        return newNode;
    }

    struct Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct Node* insertAtbeg(struct Node *head,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(head == NULL){
        return newNode;
    }

    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    return newNode;
}

void printList(struct Node *head){
    struct Node *temp;
    temp = head;

    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }

    printf("NULL");
}


int main(int argc,char *argv[]){
    if(argc > 1){
        return 1;
    }

    struct Node *head = NULL;

    head = insertAtEnd(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);

    head = insertAtbeg(head,5);

    printList(head);

    int closeWindow;
    scanf("%d",&closeWindow);

    return 1;
}
