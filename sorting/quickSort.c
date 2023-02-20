#include <stdio.h>
#include <stdlib.h>
int a[]={5,4,3,2,1,8};
int partition(int start,int end)
{
    int pivot = a[end];
    int i=start-1;
    int j;
    int temp;
    for(j=start;j<end;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            temp = a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[end];
    a[end]=temp;
    return i+1;
}

void quick(int start,int end)
{
    if (start < end)
    {
        int p = partition(start, end); //p is the partitioning index
        quick(start, p - 1);
        quick(p + 1, end);
    }
}

int main()
{
    quick(0,5);
    for(int i=0;i<6;i++)
        printf("%d  ",a[i]);
}
