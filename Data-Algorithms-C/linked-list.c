#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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
struct Node* insertAtNth(struct Node* head, int newData, int pos)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp;
    temp = head;

    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Function to delete a node with a given value from the linked list
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // Check if the node to be deleted is the head
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        return head;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free the memory of the deleted node
    free(temp);

    return head;
}

//Function to delete the node at nth position
struct Node* deleteAtNth(struct Node* head,int pos){
    struct Node* temp;
    temp = head->next;
    
    if(pos == 0){
        head = temp->next;
        free(temp);
        return head;
    }

    struct Node* prev;
    prev = head;

    for (int i = 1; i < pos; i++)
    {
        prev->next = prev;

        if (temp->next == NULL)
        {
            printf("Out of reach");
            return head;
        }
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

struct Node* reverseList(struct Node* head){
    if(head == NULL){
        return head;
    }

    struct Node *prev,*current,*next;

    prev = NULL;
    current = head;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;

    return head;
}

//WORKS WITH ONLY GLOBAL HEAD!
void reverseListrecursion(struct Node* head){
    struct Node* p;
    if(p->next == NULL){
        head = p;
        return;
    }

    reverseListrecursion(head);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printListRecursive(struct Node* node){
    if(node == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ",node->data);
    printListRecursive(node->next);
}

void printListRecursiveReverse(struct Node* node){
    if(node == NULL){
        printf("\n");
        return;
    }
    printListRecursiveReverse(node->next);
    printf("%d -> ",node->data);
}

int main(int argc,char *argv[]) {
    if(argc > 1){
        return 1;
    }

    struct Node* head = NULL;

    /*head = insertAtEnd(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);*/

    head = insertAtNth(head,1,0);
    head = insertAtNth(head,2,1);
    head = insertAtNth(head,3,2);
    head = insertAtNth(head,4,3);
    //head = deleteAtNth(head,);

    printListRecursive(head);
    printListRecursiveReverse(head);
    printf("NULL\n\n");

    printList(head);

    head = reverseList(head);
    printf("\n");
    printList(head);

    freeList(head);

    //Closing Stuff
    int closeWindow;
    scanf("%d",&closeWindow);

    return 0;
}
