#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node*link;
};
typedef struct node node;
node*getnode();
node*insertf(int item,node*first);
node*insertr(int item,node*first);
node*deletef(node*first);
node*deleter(node*first);
void display(node*first);
void main()
{
int item,choice;
node*first=NULL;
for(;;)
{
 printf("enter 1 INSERT REAR 2 INSERT FRONT 3 DELETE REAR 4 DELETE FRONT 5 DISPLAY\n");
 scanf("%d",&choice);
 switch(choice)
{
 case 1:printf("enter item\n");
	scanf("%d",&item);
	first=insertr(item,first);
	break;
 case 2:printf("enter item\n");
	scanf("%d",&item);
	first=insertf(item,first);
	break;
 case 3:first=deleter(first);
	break;
 case 4:first=deletef(first);
	break;
 case 5:display(first);
	break;
 default:exit(0);
}
}
}
node*getnode()
{
node*temp;
temp=(node*)malloc(sizeof(node));
if(temp==NULL)
{
 printf("out ofmemeory\n");
exit(0);
}
return temp;
}

node*insertf(int item,node*first)
{
node*temp;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
 return temp;
temp->link=first;
return temp;
}
node*insertr(int item,node*first)
{
node*temp;
node*cur;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
 return temp;
cur=first;
while(cur->link!=NULL)
{
 cur=cur->link;
}
cur->link=temp;
return first;
}
node*deletef(node*first)
{
 node*temp;
 if(first==NULL)
{
 printf("list empty\n");
 return NULL;
}
if(first->link==NULL)
{
 printf("deleted item is %d\n",first->info);
 free(first);
 return NULL;
}
temp=first->link;
printf("deleted item is %d\n",first->info);
free(first);
return temp;
}
node*deleter(node*first)
{
if(first==NULL)
{
 printf("list empty\n");
 return NULL;
}
if(first->link==NULL)
{
 printf("deleted item is %d\n",first->info);
 free(first);
 return NULL;
}
node*cur;
node*prev;
cur=first;
prev=NULL;
while(cur->link!=NULL)
{
 prev=cur;
 cur=cur->link;
}
prev->link=NULL;
printf("deleted item is %d\n",cur->info);
free(cur);
return first;
}
void display(node*first)
{
if(first==NULL)
{
 printf("list empty\n");
 return;
}
node*temp;
temp=first;
printf("elements of list are\n");
while(temp!=NULL)
{
 printf("%d ",temp->info);
 temp=temp->link;
}
}

