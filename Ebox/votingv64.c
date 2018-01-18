#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int n;
  char array;
}Vote;

void calculate(Vote *);
void deallocate(Vote *);

void calculate(Vote *sp)
{
  int i ,bill=0,nobill=0;
  float total;
  scanf("%d",&sp->n);
  sp->array = (char )malloc(sizeof(char));
  for(i =0;i<sp->n;i++)
  {
   scanf("%s",sp->array);
   if(sp->array[i]=='1')
   bill++;
   else if(sp->array[i]== '0')
   nobill++;
  }
  total = nobill+bill;
  total = (2*total)/3;
  if(bill>=total)
  printf("Passed");
  else
  printf("Rejected");
}
void deallocate(Vote *sp)
{
  if(sp->array==NULL)
  {
    free(sp->array);
  }
}
int main()
{
  Vote v1;
  calculate(&v1);
  deallocate(&v1);
  return 0;
}
