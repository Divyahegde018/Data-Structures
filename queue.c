#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
void insert(int item,int *r,int q[]);
void delete(int *r,int *f,int q[]);
void display(int r,int f,int q[]);
void main()
{
 int q[5],f=0,r=-1,item,choice;
 for(;;)
{
 printf("enter 1 INSERT 2 DELETE 3 DISPLAY\n");
 scanf("%d",&choice);
 switch(choice)
{
 case 1:printf("enter item\n");
	scanf("%d",&item);
	insert(item,&r,q);
	break;
 case 2:delete(&r,&f,q);
	break;
 case 3:display(r,f,q);
	break;
 default:exit(0);
}
}
}
void insert(int item,int *r,int q[])
{
 if(*r==SIZE-1)
 {
 printf("queue full\n");
 return;
}
q[++(*r)]=item;
}
void delete(int *r,int *f,int q[])
{
 if((*f)>(*r))
{printf("queue empty\n");
 return;
}
 printf("deleted item is %d\n",q[(*f)++]);
 if(*f>*r)
{ *f=0;
 *r=-1;}
}
void display(int r,int f,int q[])
{
 if(f>r){
printf("queue empty\n");
 return;
}
int i;
printf("contents of q are \n");
for(i=f;i<=r;i++)
{
printf("%d ",q[i]);
}
}
