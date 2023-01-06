#include <stdio.h>
#include <stdlib.h>
void read2d(int a[][10],int m,int n)
{
    int i,j;

    printf("\nenter array elements\n");
    for(i =0;i<m;i++)
    {
        for(j =0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

}
void display(int a[10][10],int m,int n)
{
	int i,j;
	printf("dispalying array....\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void sparse(int a[10][10],int sp[10][10],int m,int n)
{
   int i,j,k=1;
    for(i =0;i<m;i++)
    {
        for(j =0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                sp[k][0]=i;
                sp[k][1]=j;
                sp[k][2]=a[i][j];
                k++;
            }
        }
    }
    sp[0][0]=m;
    sp[0][1]=n;
    sp[0][2]=k-1;
    display(sp,k,3);
}
void add(int sp1[10][10],int sp2[10][10],int sp3[10][10])
{
    int i=1,j=1,k=1,sum;
    int r1=sp1[0][0];
    int c1=sp1[0][1];
    int n1=sp1[0][2];
    int r2=sp2[0][0];
    int c2=sp2[0][1];
    int n2=sp2[0][2];
    if((r1==r2)&&(c1==c2))
    {
        while(i<=n1&&j<=n2)
        {
             if(sp1[i][0]==sp2[j][0])
             {
                 if(sp1[i][1]==sp2[j][1])
                 {
                     sum = sp1[i][2]+sp2[j][2];
                     if(sum!=0)
                     {
                         sp3[k][0]= sp1[i][0];
                         sp3[k][1]=sp1[i][1];
                         sp3[k][2]=sum;
                         k++;
                     }
                     i++;
                     j++;
                 }
                 else if(sp1[i][1]<sp2[j][1])
                 {
                     sp3[k][0]= sp1[i][0];
                     sp3[k][1]=sp1[i][1];
                     sp3[k][2]=sp1[i][2];
                     k++;
                     i++;
                 }
                 else
                 {
                     sp3[k][0]= sp2[j][0];
                     sp3[k][1]=sp2[j][1];
                     sp3[k][2]=sp2[j][2];
                     k++;
                     j++;
                 }
             }
             else if(sp1[i][0]<sp2[j][0])
             {
                 sp3[k][0]= sp1[i][0];
                 sp3[k][1]=sp1[i][1];
                 sp3[k][2]=sp1[i][2];
                 k++;
                 i++;
             }
             else
             {
                 sp3[k][0]= sp2[j][0];
                 sp3[k][1]=sp2[j][1];
                 sp3[k][2]=sp2[j][2];
                 k++;
                 j++;
             }
        }
        if(i<=n1)
        {
            while(i<=n1)
            {
                 sp3[k][0]= sp1[i][0];
                 sp3[k][1]=sp1[i][1];
                 sp3[k][2]=sp1[i][2];
                 k++;
                 i++;
            }
        }
        if(j<=n2)
        {
            while(j<=n2)
            {
                 sp3[k][0]= sp2[j][0];
                 sp3[k][1]=sp2[j][1];
                 sp3[k][2]=sp2[j][2];
                 k++;
                 j++;
            }
        }
        sp3[0][0]=r1;
        sp3[0][1]=c1;
        sp3[0][2]=k-1;
    }
    else
    {
        printf("\naddition cant be done..");
    }
}
int main()
{
    int r1,c1,r2,c2,a[10][10],b[10][10],sp2[10][10],sp1[10][10],sp3[10][10];
    printf("enter no colomn and rows :");
    scanf("%d%d",&r1,&c1);
    read2d(a,r1,c1);
    sparse(a,sp1,r1,c1);
    printf("enter no colomn and rows :");
    scanf("%d%d",&r2,&c2);
    read2d(b,r2,c2);
    sparse(b,sp2,r2,c2);
    add(sp1,sp2,sp3);
    display(sp3,sp3[0][2]+1,3);
}
