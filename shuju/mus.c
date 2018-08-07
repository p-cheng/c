#include <stdio.h>
#include <stdlib.h>
#define N 13
typedef struct node
{
    int data;
    struct node *next;

}Node, *list;
list Initlist(int n)
{
    int i;
    list head = NULL;
    head = (list)malloc(sizeof(Node));
    head->data = 0;
    head->next= NULL;
    list tail = head;
    for(i=0;i<n-1;i++)
    {
        list Newlist = NULL;
         Newlist = (list)malloc(sizeof(Node));
        Newlist->data = 0;
        Newlist->next = head;
        tail->next = Newlist;
        tail = Newlist;
    }
    return head;
}
void Magician(list head,int n)
{
    list p = NULL;
    p = head;
    p->data =1;
    int i;
    int num = 2;
    while(1)
    {
        for(i=0;i<num;i++)
        {
            p = p->next;
            if(p->data != 0)
            {
                i--;
            }
        }
        if(p->data == 0)
        {
            p->data = num;
            num++;
        }
        if(num==n+1)
        {
            break;
        }
    }
}
void Print(list head, int n)
{
    list p;
    p = head;
    if(head == NULL)
    {
        printf("kong \n");
    }
    int i = 1;
        for(i=1;i<=n;++i)
        {

            printf("第%d个数据 %d\n",i,p->data);
            p = p->next;
        }
    
}
int main()
{
    list l;
 l=    Initlist(13);
    Magician(l,N);
    Print(l,13);
    return 0;
}
