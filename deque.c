#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define  MAX_SIZE 5
int a[MAX_SIZE];
int front=-1;
int rear =-1;
bool isempty()
{
    if(front==-1)
        return true;
    else
        return false;
}
bool isfull()
{
    if((front==rear+1)|| (front==0&&rear==MAX_SIZE-1))
        return true;
    else
        return false;
}
void insFront(int item)
{
    if(!isfull())
    {
        if(isempty())
        {
            rear=front=0;
            a[front]=item;
        }
        else if(front==0)
        {
            front=MAX_SIZE-1;
            a[front]=item;
        }
        else
        {
            front=front-1;
            a[front]=item;
        }
        printf("\nitem inserted!!");
    }
    else
        printf("\nqueue is full!!");

}
void insRear(int item)
{
    if(!isfull())
    {
        if(isempty())
        {
            rear=front=0;
            a[rear]=item;
        }
        else if(rear==MAX_SIZE-1)
        {
            rear=0;
            a[rear]=item;
        }
        else
        {
            rear=front+1;
            a[front]=item;
        }
        printf("\nitem inserted!!");
    }
    else
        printf("\nqueue is full!!");
}
void delFront()
{
    if(!isempty())
    {
        if(front==rear)
        {
            printf("deleted item is %d",a[front]);
            front=rear=-1;
        }
        else if(front ==MAX_SIZE-1)
        {
            front=0;
            printf("deleted item is %d",a[front]);
        }
        else
        {
            printf("deleted item is %d",a[front++]);
        }
    }
    else
        printf("\nqueue is empty!!");
}
void delRear()
{
    if(!isempty())
    {
        if(front==rear)
        {
            printf("deleted item is %d",a[rear]);
            front=rear=-1;
        }
        else if(rear ==0)
        {
            rear=MAX_SIZE-1;
            printf("deleted item is %d",a[rear]);
        }
        else
        {
            printf("deleted item is %d",a[rear--]);
        }
    }
    else
        printf("\nqueue is empty!!");
}
int main()
{
    int item,choice;
    printf("\n\nMenu\n\n");
    printf("\n1 for insertion at front");
    printf("\n2 for insertion at rear");
    printf("\n3 for deletion at front");
    printf("\n4 for deletion at rear");
    printf("\n5 for exit\n");
    while(2){
        printf("\n front is %d",front);
        printf("\n rear is %d",rear);

        printf("\nenter choice :");
        scanf("%d",&choice);


        switch(choice){
            case 1: printf("\nenter element to  :");
                    scanf("%d",&item);
                    insFront(item);
                    break;
            case 2: printf("\nenter element to  :");
                    scanf("%d",&item);
                    insRear(item);
                    break;
            case 3: delFront();
                    break;
            case 4: delRear();
                    break;
            case 5: exit(0);

            default:printf("\ninvalid choice!!");
        }
    }
}
