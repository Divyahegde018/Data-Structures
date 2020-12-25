#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node*llink;
struct node*rlink;
};
typedef struct node node;
node*getnode();
node*maketree(int item,node*root);
void inorder(node*root);
void preorder(node*root);
void postorder(node*root);
int search(int item,node*root);
void main()
{
int item,choice;
int flag=0;
node*root=NULL;
for(;;)
{
 printf("enter 1 INSERT 2 INORDER 3 PREORDER 4 POSTORDER 5 SEARCH\n");
 scanf("%d",&choice);
 switch(choice)
{
 case 1:printf("enter item\n");
	scanf("%d",&item);
	root=maketree(item,root);
	break;
 case 2:if(root==NULL)
	printf("tree empty\n");
	else{
	printf("inorder traversal\n");
	inorder(root);}
	break;
 case 3:if(root==NULL)
	printf("tree empty\n");
	else{
	printf("preorder traversal\n");
	preorder(root);}
	break;
 case 4:if(root==NULL)
	printf("tree empty\n");
	else{
	printf("postorder traversal\n");
	postorder(root);}
	break;
 case 5:printf("enter item to be searched\n");
	scanf("%d",&item);
	flag=search(item,root);
	if(flag==0)
	printf("search unsuccessful\n");
	else
	printf("search successful\n");
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
node*maketree(int item,node*root)
{
 node*cur;
 node*temp;
 node*prev;
 temp=getnode();
 temp->info=item;
 temp->llink=NULL;
 temp->rlink=NULL;
 if(root==NULL)
 return temp;
 cur=root;
 prev=NULL;
 while(cur!=NULL)
{
 prev=cur;
 if(item<cur->info)
	cur=cur->llink;
 else cur=cur->rlink;
}
if(item<prev->info)
 prev->llink=temp;
else 
 prev->rlink=temp;
return root;
}
void inorder(node*root)
{
if(root==NULL)
 return;
inorder(root->llink);
printf("%d ",root->info);
inorder(root->rlink);
}
void preorder(node*root)
{
if(root==NULL)
 return;
printf("%d ",root->info);
preorder(root->llink);

preorder(root->rlink);
}
void postorder(node*root)
{
if(root==NULL)
 return;
postorder(root->llink);
postorder(root->rlink);
printf("%d ",root->info);
}
int search(int item,node*root)
{
 node*cur;
 if(root==NULL)
 return 0;
 cur=root;
 while(cur!=NULL)
 {
 if(item==cur->info)
 break;
 if(item<cur->info)
 cur=cur->llink;
 else
 cur=cur->rlink;
}
if(cur==NULL)
return 0;
else 
return 1;
}


