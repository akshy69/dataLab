#include <stdio.h>
#include <stdlib.h>
struct node* header =NULL;
struct node{
    int dat;
    struct node* next;
};
void insertLast(int data)
{
    if(header==NULL)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->dat=data;
        newnode->next=NULL;
        header=newnode;
    }
    else
    {
        struct node* temp = header;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->dat=data;
        newnode->next=NULL;
        temp->next=newnode;
    }
}
void insertFront(int data)
{
    if(header==NULL)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->dat=data;
        newnode->next=NULL;
        header=newnode;
    }
    else
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->dat=data;
        newnode->next=header;
        header=newnode;
    }
}
void insertSpecific(int data,int spec)
{
    if(header!=NULL)
    {
        struct node* temp;
        temp=header;
        while(temp!=NULL&&temp->dat!=spec)
        {
            temp=temp->next;
        }
        if(temp!=NULL)
        {
            printf("\nspecified data found!!");
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->next=temp->next;
            newnode->dat=data;
            temp->next=newnode;
        }
        else
            printf("\nspecified data not found!!");
    }
    else
        printf("\nlist is empty!!");
}
void deleteFront()
{
    if(header!=NULL)
    {
        struct node* temp;
        temp=header;
        header=temp->next;
    }
    else
        printf("\nnothing to delete");
}
void deleteSpecific(int spec)
{
    if(header!=NULL)
    {
        struct node* temp;
        struct node* prev;
        temp=header;
        while(temp!=NULL&&temp->dat!=spec)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("\nspecified data not found and deleted!!\n");
            return;
        }
        prev->next=temp->next;
    }
    else
        printf("\nnothing to delete");
}
void display()
{
    printf("\n");
    if(header==NULL)
        printf("\nlist is empty\n");
    else
    {
        struct node* temp = header;
        while(temp!=NULL)
        {
            printf("%d  ",temp->dat);
            temp=temp->next;
        }
    }
}
void deleteEnd()
    {
        if(header!=NULL)
        {
            struct node* temp;
            struct node* prev;
            temp=header;
            while(temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
        }
        else
            printf("\nnothing to delete");
    }
int main()
{
    int choice,item,key;
    while(1)
    {
        printf("\n\n     MENU     \n");
        printf("\n1.Insert at Front");
        printf("\n2.Insert after Specified data");
        printf("\n3.Insert at Last");
        printf("\n4.Delete from Front");
        printf("\n5.Delete Specified data");
        printf("\n6.Delete from Last");
        printf("\n7.Display");
        printf("\n8.Exit\n\n");
        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("\nenter item to insert :");
                scanf("%d",&item);
                insertFront(item);
                break;
            case 2:
                printf("\nwhere to insert :");
                scanf("%d",&key);
                printf("\nenter item to insert :");
                scanf("%d",&item);
                insertSpecific(item,key);
                break;
            case 3:
                printf("\nenter item to insert :");
                scanf("%d",&item);
                insertLast(item);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                printf("\nwhich one to delete :");
                scanf("%d",&key);
                deleteSpecific(key);
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
        }
    }
    return 0;
}
