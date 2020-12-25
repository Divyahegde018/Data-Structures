#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
void push(int item,int *top,int s[]);
int pop(int *top,int s[]);
void display(int top,int s[]);
void main()
{
 int s[10],top=-1,item,choice;
 for(;;)
{
 printf("enter 1 PUSH 2 POP 3 DISPLAY\n");
 scanf("%d",&choice);
 switch(choice){
 case 1:printf("enter item\n");
	scanf("%d",&item);
	push(item,&top,s);
	break;
 case 2:item=pop(&top,s);
	if(item==0)
	printf("stack empty\n");
	else printf("deleted item is %d\n",item);
	break;
 case 3:display(top,s);
	break;
 default:exit(0);
 }
}
}
void push(int item,int *top,int s[])
{
 if(*top==SIZE-1)
 {
 printf("stack full\n");
 return;
 }
 s[++(*top)]=item;
}
int pop(int *top,int s[])
{ int item;
 if(*top==-1)
{
 return 0;
}
 item=s[(*top)--];
 return item;
}
void display(int top,int s[])
{
 if(top==-1)
{
 printf("stack empty\n");
 return;
}
int i;
printf("stack elements are\n");
for(i=0;i<=top;i++)
{
 printf("%d ",s[i]);
 }
}
