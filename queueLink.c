#include <stdio.h>
#include <stdlib.h>
struct node* header =NULL;
struct node{
    int dat;
    struct node* next;
};
void enQueue(int data)
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
int deQueue()
{
    if(header!=NULL)
    {
        struct node* temp;
        temp=header;
        header=temp->next;
        return temp->dat;

    }
    else
        printf("\nQueue is empty");
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
int main()
{
    int item,choice;
    while(2){
        printf("\n\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.display");
        printf("\n4.exit\n");
        printf("\nenter choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nenter element to  :");
                    scanf("%d",&item);
                    enQueue(item);
                    break;
            case 2: if(header!=NULL){
                        item=deQueue();
                        printf("\ndeleted item is %d",item);
                    }
                    else
                        printf("\nqueue empty!!");
                        break;
            case 3: display();
                    break;
            case 4: exit(0);
            default:printf("\ninvalid choice!!");
        }
    }
}
