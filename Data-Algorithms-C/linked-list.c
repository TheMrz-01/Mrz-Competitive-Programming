#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* next;
    int data;
};

struct Node* insertAtBeginning(struct Node* head,int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = newData;
    newNode->next = head;
    return newNode; 
}

struct Node* insertAtEnd(struct Node* head,int newData){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }
    
    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

struct Node* insertAtNth(struct Node* head,int newData,int pos){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    int tempPos = 0;

    while (temp != NULL && tempPos < pos - 1)
    {
        temp = temp->next;
        tempPos++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void printList(struct Node* head){
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

struct Node* deleteNodeAtNth(struct Node* head,int pos){
    if(head == NULL){
        printf("tf u mean\n");
    }
    
    struct Node* temp = head;

    if(pos == 0){
        temp = head->next;
        free(head);
        return temp; 
    }

    int tempPos = 0;
    struct Node* pre;

    while (temp != NULL && tempPos < pos - 1)
    {
        temp = temp->next;
        pre = temp->next;
        tempPos++;
    }

    if (temp == NULL) {
        printf("Out of reach\n");
        return head;
    }

    pre = temp;
    temp = temp->next;
    pre->next = temp->next;
    free(temp);
    return head;
}

struct Node* deleteNodeWithKey(struct Node* head,int key){
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return head;
    }

    prev->next = temp->next;

    free(temp);

    return head;
}

int main(void){
    struct Node* head = NULL;

    head = insertAtBeginning(head,1);
    head = insertAtEnd(head, 2);
    head = insertAtBeginning(head,3);
    head = insertAtEnd(head,4);
    head = insertAtNth(head,5,3);

    printList(head);

    head = deleteNodeAtNth(head,1);

    printList(head);

    freeList(head);

    int wait;
    scanf("%d",wait);

    return 0;
}
