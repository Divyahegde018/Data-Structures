#include<stdio.h>
#include<string.h>
#include<math.h>
double compute(char symbol,double op1,double op2);
void main()
{
double s[10],op1,op2,result;
char symbol,postfix[10];
int top=-1;
int i;
printf("enter postfix expression\n");
scanf("%s",postfix);
for(i=0;i<strlen(postfix);i++)
{
 symbol=postfix[i];
 if(isdigit(symbol))
  s[++top]=symbol-'0';
else{
 op2=s[top--];
 op1=s[top--];
 result=compute(symbol,op1,op2);
 s[++top]=result;
}
}
result=s[top--];
printf("result=%f\n",result);
}
double compute(char symbol,double op1,double op2)
{
 switch(symbol)
{
 case'+':return op1+op2;
 case'-':return op1-op2;
 case'*':return op1*op2;
 case'/':return op1/op2;
 case'^':return pow(op1,op2);
 default:printf("invalid operator used\n");
}
}
