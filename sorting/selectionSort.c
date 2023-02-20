#include <stdio.h>

int getMinLoc(int a[],int i,int n){
    int temp;
    int minEle= a[i];
    int minPos= i;
    for(int j=i+1;j<n;j++){
        if(a[j] < minEle){
            minEle=a[j];
            minPos = j;
        }
    }
    return minPos;
}
void selectionSort(int a[],int n){
    int minLoc,temp;
    for(int i=0;i<n;i++){
        minLoc= getMinLoc(a,i,n);
        temp=a[i];
        a[i]=a[minLoc];
        a[minLoc]=temp;
    }
}


void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

void main(){
    int a[]={324,2344,5423134,32,21};
    selectionSort(a,5);
    display(a,5);
}