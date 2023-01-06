#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_size 10
int a[max_size];
int top=-1;
bool isempty(){
    if(top==-1)
        return true;
    else
        return false;
    }
bool isfull(){
    if(top==max_size-1)
        return true;
    else
        return false;
    }
int peek(){
    if(!isempty())
        return a[top];
    else
        printf("\nstack underflow!!");
    }
int pop(){
    if(!isempty()){
        return(a[top--]);
    }
    else
        printf("\nstack underflow!!");
    }
void push(int item){
        if(!isfull())
            a[++top]=item;
        else
            printf("\nstack overflow!!");
    }
int main()
{
    int choice,item;
    while(2){
        printf("\npress 1 for push");
        printf("\npress 2 pop");
        printf("\npress 3 peek");
        printf("\npress 4 exit\n");
        printf("\nenter choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nenter element to push :");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2: item=pop();
                    printf("\npoped item is %d",item);
                    break;
            case 3: item=peek();
                    printf("\npeeked item is %d",item);
                    break;
            case 4: exit(0);
            default:printf("\ninvalid choice!!");
        }
    }
}
