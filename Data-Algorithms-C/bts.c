#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); 
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insertNode(Node** root,int data){
    if(*root == NULL){
        *root = createNode(data);
        return;
    }

    if(data <= (*root)->data){
        insertNode(&((*root)->left), data);
    }
    else if(data > (*root)->data){
        insertNode(&((*root)->right), data);   
    }
}

void searchData(Node** root,int data){
    if(*root == NULL){
        printf("The bst is empty!");
        return;
    }

    if(data == (*root)->data){
        printf("Where is my data bruce\n");
        return;
    }
    else if(data <= (*root)->data){
        searchData(&((*root)->left), data);
    }
    else if(data > (*root)->data){
        searchData(&((*root)->right), data);   
    }
    else{
        return;
    }
}

void findMin(Node** root){
    if((*root)->left == NULL){
      printf("Min: %d\n",(*root)->data);
      return;
    }
    else {
      findMin(&((*root)->left));
    }
}

void findMax(Node** root){
    if((*root)->right == NULL){
      printf("Max: %d\n",(*root)->data);
      return;
    }
    else {
      findMax(&((*root)->right));
    }
}

int main(int argc,char *argv[]){
    //Nothing to look at here browski
    if(argc > 1){
        return 0;
    }

    printf("Started\n");

    //In this example I will use a root that's not global and to keep main function clean I will pass the adress of the root
    struct Node* root = NULL;

    insertNode(&root,15);
    insertNode(&root,10);
    insertNode(&root,20);

    searchData(&root,15);
    searchData(&root,10);
    searchData(&root,20);

    searchData(&root,16);
    
    findMin(&root);
    findMax(&root);

    //-----------------------
    int closeWindow;
    scanf("%d",&closeWindow);

    return 0;
}
