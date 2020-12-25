#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
void insert(int item,int *count,int *r,int q[]);
void delete(int *count,int *f,int q[]);
void display(int count,int f,int q[]);
void main()
{
 int item,choice;
 int q[5],r=-1,f=0,count=0;
 for(;;)
{
 printf("enter 1 INSERT 2 DELETE 3 DISPLAY\n");
 scanf("%d",&choice);
 switch(choice)
{
 case 1:printf("enter item\n");
	scanf("%d",&item);
	insert(item,&count,&r,q);
	break;
 case 2:delete(&count,&f,q);
	break;
 case 3:display(count,f,q);
	break;
 default:exit(0);
}
}
}void insert(int item,int *count,int *r,int q[])
{
if(*count==SIZE)
{
 printf("q full\n");
 return;
}
*r=(*r+1)%SIZE;
q[*r]=item;
*count+=1;
}
void delete(int *count,int *f,int q[])
{
if(*count==0)
{
 printf("q empty\n");
 return;
}
printf("deleted item is %d\n",q[*f]);
*f=(*f+1)%SIZE;
*count-=1;
}
void display(int count,int f,int q[])
{
if(count==0)
{
 printf("q empty\n");
 return;
}
int i,j;
i=f;
printf("contents of q are\n");
for(j=0;j<count;j++)
{ printf("%d ",q[i]);
 i=(i+1)%SIZE;
}
}

