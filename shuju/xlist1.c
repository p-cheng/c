#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef struct sqList *List;
 struct sqList
{
    int data[MAXSIZE];
    int length;
}L;
List makelist()
{
    List list;
    list = (List)malloc(sizeof(struct sqList));
    list->length = 0;
    return list;
   
}

int find(int x,List list)
{
    int i = 0;
    while(i<list->length  && list->data[i] != x)
    {
        i++;
    }
    if(i>=list->length)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

void insert(int x,int i,List list)
{
    int j;
    if(list->length == MAXSIZE)
    {
        printf("full\n");
        return;
        
    }
    if(i<1 || i>list->length+1)
    {
        printf("error\n");
        return;
    }
    for(j=list->length-1;j>=i;j--)
    {
        list->data[j+1] = list->data[j];
    }
    list->data[i-1] = x;
    list->length++;
    return;

}
void delent(int i,List list)
{
    int j;
    if(i<1 || i>list->length)
    {
        printf("error\n");
        return;
    }
    for(j=i;j<list->length;j++)
    {
        list->data[j-1] = list->data[j];
    }
    list->length--;
    return;
}

int main()
{
    List list;
    list = makelist();
    int i;
    list->length =10;
    for(i=0;i<10;i++)
    {
        list->data[i] = i;
        for(i=0;i<10;i++)
        {
            printf("di%dgesguzi  shi%d\n",i,i);
        }
    }
    return 0;
}
