#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

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
        printf("The bst is empty!\n");
        return;
    }

    if(data == (*root)->data){
        printf("Yes sir\n");
        return;
    }
    else if(data <= (*root)->data){
        searchData(&((*root)->left), data);
    }
    else if(data > (*root)->data){
        searchData(&((*root)->right), data);   
    }
    else{
        printf("Where is my data bruce");
        return;
    }
}

void bfs(Node** root){
    if(!root) return;

    queue<Node*> q;
    q.push(*root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);  
    }    

    cout << " \n";
}

void preorder_dfs(Node** root){
    if (!(*root)) return;       

    cout << (*root)->data << " "; 
    preorder_dfs(&(*root)->left);     
    preorder_dfs(&(*root)->right); 
}

void inorder_dfs(Node** root){
    if (!(*root)) return;       

    preorder_dfs(&(*root)->left);   
    cout << (*root)->data << " ";   
    preorder_dfs(&(*root)->right); 
}

void postorder_dfs(Node** root){
    if (!(*root)) return;       

    preorder_dfs(&(*root)->left);     
    preorder_dfs(&(*root)->right); 
    cout << (*root)->data << " "; 
}

int main(int argc,char *argv[]){
    //Nothing to look at here browski
    if(argc > 1){
        return 0;
    }

    printf("Started\n");

    //In this example I will use a root that's not global and to keep main function clean I will pass the adress of the root
    struct Node* root = NULL;

    insertNode(&root,1);
    insertNode(&root,3);
    insertNode(&root,2);
    insertNode(&root,5);
    insertNode(&root,6);
    insertNode(&root,4);
    insertNode(&root,7);

    /*searchData(&root,15);
    searchData(&root,10);
    searchData(&root,20);*/

    searchData(&root,16);

    cout << "Preorder DSF" << "\n";
    preorder_dfs(&root);
    cout << "\nInorder DSF" << "\n";
    inorder_dfs(&root);
    cout << "\nPostorder DSF" << "\n";
    postorder_dfs(&root);
    cout << "\nBSF" << "\n";
    bfs(&root);

    //-----------------------
    int closeWindow;
    scanf("%d",&closeWindow);

    return 0;
}
