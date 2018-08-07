#include <stdio.h>
#define MAXSIZE 1000
typedef struct 
{
    int data;
    int cur;

}Component,staticLinkLlist[MAXSIZE];
typedef Component Status;
int  InitList(staticLinkLlist space)
{
   int i ;
   for(i=0;i<MAXSIZE-1;i++)
   {
       space[i].cur = i+1;
   }
       space[MAXSIZE-1].cur=0;
       return 0;
}
