#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct SqList *List;

 struct SqList{
    int Data[MAX];
    int Last;
} L;

List MakeEmpty()
{
    List list;
     list =(List)malloc(sizeof(struct SqList));
    list->Last = -1;
    return list;
}

int Find(int x,List list)
{
    int i = 0;
    while(i <= list->Last && list->Data[i] != x)
    {
        i++;
    }
    if(i > list->Last)
    {
        return -1;

    }
    else
    {
        return i;
    }
}

void  Insert(int x,int i,List list)
{
   int j;
    if(list->Last == MAX-1)
    {
        printf("full\n");
        return ;
    }
    if(i<1 || i>list->Last+2)
    {
        printf("error");
        return ;
    }
    for(j=list->Last;j>=i-1;j--)
    {
        list->Data[j+1] = list->Data[j];
    }
        list->Data[i-1] = x;
        list->Last++;
        return ;
}

void Delete(int i,List list)
{
    printf("进入dele\n");
    int j;
    if(i < 1 || i>list->Last+1)
    {
        printf("error\n");
        return;
    }
    for(j=i;j<=list->Last;j++)
    {
        printf("进入for\n");
        list->Data[j-1]=list->Data[j];
    }
    list->Last--;
    printf("last =%d\n",list->Last);
    return;
}
int main()
{
    List list;
    list = MakeEmpty();
    int i;
    int j;
    list->Last = 9;
    for(i=0;i<10;i++)
    {
        list->Data[i] = i;
        for(j=0;j<10;j++)
        {
            printf("第%d的数字是%d\n",j,list->Data[j]);
        }
    }
    Delete(2,list);
    Insert(100,5,list);
        for(i=0;i<10;i++)
        {
            printf("第%d是%d\n",i,list->Data[i]);
        }
    return 0;
}

