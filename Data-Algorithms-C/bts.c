#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insertNode(Node** root,int data){
    if(*root == NULL){
        *root = createNode(data);
    }

    if(data <= (*root)->data){
        insertNode(&((*root)->left), data);
    }
    else if(data > (*root)->data){
        insertNode(&((*root)->right), data);   
    }
}

int main(int argc,char *argv[]){
    //Nothing to look at here browski
    if(argc > 1){
        return 0;
    }

    //In this example I will use a root that's not global and to keep main function clean I will pass the adress of the root
    struct Node* root = NULL;

    insert(&root,15);
    insert(&root,10);
    insert(&root,20);

    //-----------------------
    int closeWindow;
    scanf("%d",&closeWindow);

    return 0;
}
