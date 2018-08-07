/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月26日 星期四 20时48分47秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef struct 
{
    int *data;
    int top;
    int Stacksize;
}Stack;

Stack* InitStack(Stack *s,int Stacksize)//初始化一个栈
{
    s = (Stack*)malloc(sizeof(Stack));
    s->data= (int *)malloc(Stacksize*sizeof(int));
    s->Stacksize = Stacksize;
    
    s->top=-1;
    return s;
}
int EmptyStack(Stack *s)//判栈空
{
   if(s->top==-1)
    return 1;
   else
    return 0;
}
void PushStack(Stack *s,int a)//入栈
{
    if(s->top == (s->Stacksize-1))
    {
        printf("Stack is full!\n");
    }
    else
    {
        //printf("%d\n",s->top);
        s->data[++s->top]=a;
        //printf("***%d\n",s->data[s->top]);
    }
    
}
int  PopStack(Stack *s,int *a)//出栈
{
    if(s->top==-1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        //printf("sd->top = %d\n s->data= %d\n",s->top,s->data[s->top]);
        *a = s->data[s->top--];
    }
    return 0;
}
void TopStack(Stack *s,int *a)
{
    if(s->top==-1)

    {
        printf("Stack is Empty!\n");
    }
    else
    {
        *a = s->data[s->top];
    }
}
void PrintStack(Stack *s)
{
    int temp=0;
    if(s->top==-1)
    {
        printf("Stack is empty!\n");
    }
    else
    {

       printf("%d\n",s->data[s->top]);
        
     }
}
int main()
{
    Stack *s;

    int p;
    int Stacksize = 3;
   s=   InitStack(s,Stacksize);
   /* printf("请输入栈的长度！\n");
    scanf("%d",&Stacksize);
    s = InitStack(s,Stacksize);
    printf("%d\n%d\n",Stacksize,s->top);*/
    PushStack(s,10);
    PushStack(s,12);
    PopStack(s,&p);
    printf("%d\n",p);
    PopStack(s,&p);
    printf("%d\n",p);
    return 0;
}
