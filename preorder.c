#include <stdio.h>
#include <stdlib.h>

struct  node
{
    int data;
    struct node *left;
    struct node *right;
};

struct  node *newnode(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

void display(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        display(root->left);
        display(root->right);
    }
}

struct node *insert(struct node *node ,int data){
    if(node==NULL)
        return newnode(data);
    else if(data<node->data)
        node->left=insert(node->left,data);
    else if(data>node->data)
        node->right=insert(node->right,data);
    return node;
}

int main(){
    int n,x;
    struct node *root=NULL;
    printf("enter the number of nodes :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the node value : ");
        scanf("%d",&x);
        root=insert(root,x);
    }
    printf("binary search tree :");
    display(root);
    return 0;
}
