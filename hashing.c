#include <stdio.h>
#include <stdlib.h>


#define max 100


int hash[max];
int size;

int hashfn(int key){
    return key%size;
}

void insert(int key){
    int index=hashfn(key);
    while(hash[index]!=-1){
        index=(index+1)%size;
    }
    hash[index]=key;
}

void display(){
    int i;
    for(i=0;i<size;i++){
        printf("\n%d",hash[i]);
    }
    printf("\n");
}


void main(){
    int i,key =1;
    printf("enter size of hash table :");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        hash[i]=-1;
    }
    printf("enter elements to insert (0 to continue)");
    while(key!=0){
        scanf("%d",&key);
        insert(key);
    }
    printf("hashtable : ");
    display();
}
