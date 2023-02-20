#include <stdio.h>

void bubbleSort(int a[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

void main(){
    int a[]={3,351,1341,223,234};
    bubbleSort(a,5);
    display(a,5);
}