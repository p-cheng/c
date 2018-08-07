#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct
{
    int data[MAXSIZE];  
    int top;
    int len;

}Seqstack;

void InitStack(Seqstack *s)//创建空链表
{
    printf("init\n");
   s->top =-1;
   return;
   printf("init q\n");
}

int Emptystack(Seqstack *s)//判栈空
{
    if(s->top == -1)
    {
        printf("栈空\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void Pushstack(Seqstack *s,int x)
{
    if(s->top == MAXSIZE-1)
    {
        printf("栈满\n");
    }
    else
    {
        s->top++;
        s->data[s->top] = x;
    }
    printf("push%d\n",x);
}
void Popstack(Seqstack *s,int *x)
{
    if(s->top == -1)
    {
        printf("栈空\n");
    }
    else
    {
       *x = s->data[s->top];
       s->top--;
    }
}
void Topstack(Seqstack *s,int *x)
{
    if(s->top == -1)
    {
        printf("栈空\n");
    }
    else
    {
        *x = s->data[s->top];
    }
}
void Printstack(Seqstack *s)
{
    int i = s->top;
    while(s->top != -1)
    {
        printf("%d\n",s->data[(s->top)--]);
    }
    s->top  = i;
}
int main()
{
    Seqstack *a;

    int x;
    InitStack(a);
    Emptystack(a);
    Pushstack(a,1);
    Pushstack(a,3);
    Pushstack(a,2);
    Printstack(a);
    Popstack(a,&x);
    printf("%d\n",x);
    Topstack(a,&x);
    printf("%d\n",x);
        return 0;
}
