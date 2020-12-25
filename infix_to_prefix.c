#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char intopre(char infix[],char prefix[]);
int F(char);
int G(char);
char *strrev(char *str);
void main()
{
 char infix[10],prefix[10];
 printf("enter infix expression\n");
 scanf("%s",infix);
 intopre(infix,prefix);
 }
int F(char symbol)
{
 switch(symbol)
{
 case '+':case '-':return 1;
 case '*':case'/':return 3;
 case'^':case'$':return 6;
 case')':return 0;
 case'#':return -1;
 default:return 8;
}
}
int G(char symbol)
{
 switch(symbol)
{
 case '+':case '-':return 2;
 case '*':case'/':return 4;
 case'^':case'$':return 5;
 case'(':return 0;
 case')':return 9;
 default:return 7;
}
}
char intopre(char infix[],char prefix[])
{
int top=-1,i,j=0;
char s[10],symbol;
strrev(infix);
s[++top]='#';
for(i=0;i<strlen(infix);i++)
{
 symbol=infix[i];
 while(F(s[top])>G(symbol))
 {
 prefix[j]=s[top--];
 j++;
}
if(F(s[top])!=G(symbol))
s[++top]=symbol;
else top--;
}
while(s[top]!='#')
{
 prefix[j++]=s[top--];
}
prefix[j]='\0';
strrev(prefix);
for(j=0;j<strlen(infix);j++)
{
 printf("%c",prefix[j]);
}
}

char *strrev(char *s)
{
   int len=strlen(s);
   int i;
   for(i=0;i<(len/2);i++)
{
   char temp=*(s+i);
   *(s+i)=*(s+len-1-i);
   *(s+len-1-i)=temp;
}
      return s;
}
