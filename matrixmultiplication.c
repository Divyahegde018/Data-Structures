#include<stdio.h>
#include<stdlib.h>
void main()
{
 int a[5][5],b[5][5],c[5][5];
 int i,j,k,m,n;
 printf("enter value of m and n\n");
 scanf("%d%d",&m,&n);
 printf("enter the elements of first matrix\n");
 for(i=0;i<m;i++)
{
 for(j=0;j<n;j++)
 scanf("%d",*(a+i)+j);
 }
 printf("enter the elements of second matrix\n");
 for(i=0;i<m;i++)
{
 for(j=0;j<n;j++)
 scanf("%d",*(b+i)+j);
 }
 printf("addition result is\n");
 *(*(c+i)+j)=0;
 for(i=0;i<m;i++)
{
 for(j=0;j<n;j++)
{
 *(*(c+i)+j)=(*(*(a+i)+j))+(*(*(b+i)+j));
 printf("%d\t",*(*(c+i)+j));
 }
 printf("\n"); 
}
}
