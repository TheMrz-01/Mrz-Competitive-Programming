#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* Top = NULL;

void push(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = Top;
    Top = temp; 
}

void pop(){
    struct Node* temp;
    if(Top == NULL) return;
    temp = Top;
    Top = Top->link;
    free(temp);
}

void print(){
    if(Top == NULL) return;
    struct Node* temp = Top;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
    return;
}

int main(int argc,char *argv[]){
    if(argc > 1){
        return 0;
    }
    
    push(1);
    push(2);
    push(3);
    push(4);

    print();

    pop();

    print();

    int closeWindow;
    scanf("%d",&closeWindow);

    return 0;
}