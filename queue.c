#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_size 2

int a[max_size];
int rear=-1;
int front=-1;

bool isempty(){
    if(front==-1)
        return true;
    else
        return false;
    }

bool isfull(){
    if(rear==max_size-1)
        return true;
    else
        return false;
    }

int peek(){
    if(!isempty())
        return a[front];
    else
        printf("\nstack underflow!!");
    }

int dequeue(){
         int item;
         if(!isempty())
         {
             if(rear==front)
             {
                 item =a[front++];
                 rear=front=-1;
                 return item;
             }

             else
                return a[front++];

         }
         else
            printf("\nqueue underflow!!");
    }

void enqueue(int item){
        if(!isfull()){
                if(front==-1){
                    front=0;
                    a[++rear]=item;
                }
                else
                    a[++rear]=item;

        }
        else
            printf("\nqueue overflow!!");
    }

int main()
{
    int item,choice;
    while(2){
        printf("\npress 1 for enqueue");
        printf("\npress 2 for dequeue");
        printf("\npress 3 for peek");
        printf("\npress 4 for exit\n");

        printf("\n front is %d",front);
        printf("\n rear is %d",rear);

        printf("\nenter choice :");
        scanf("%d",&choice);


        switch(choice){
            case 1: printf("\nenter element to  :");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2: if(!isempty()){
                        item=dequeue();
                        printf("\npoped item is %d",item);

                    }
                    else
                        printf("\nqueue underflow!!");
                    break;
            case 3: if(!isempty()){
                        item=peek();
                        printf("\npeeked item is %d",item);

                    }
                    else
                        printf("\nqueue underflow!!");
                    break;

            case 4: exit(0);

            default:printf("\ninvalid choice!!");
        }
    }
}
