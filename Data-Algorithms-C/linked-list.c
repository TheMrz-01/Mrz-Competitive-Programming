#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

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

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    int tempPos = 1;

    while (temp != NULL && tempPos < pos - 1) {
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

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    struct Node* head = NULL; 

    // Insert some elements at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    // Print the linked list
    printf("Linked List after insertion at the beginning:\n");
    printList(head);

    // Insert an element at the end
    head = insertAtEnd(head, 4);

    // Print the linked list
    printf("Linked List after insertion at the end:\n");
    printList(head);

    //Print the linked list after inserting in nth position
    head = insertAtNth(head,5,5);
    head = insertAtNth(head,6,2);
    head = insertAtNth(head,7,1);

    // Print the linked list
    printf("Linked List after insertion at the end:\n");
    printList(head);

    // Delete a node with a given value
    head = deleteNode(head, 2);

    // Print the linked list after deletion
    printf("Linked List after deleting node with value 2:\n");
    printList(head);

    //Print the linked list after inserting in nth position

    // Free the memory allocated for the linked list
    freeList(head);

    int number;
    printf(" ");
    scanf("%d", &number);
    return 0;
}
