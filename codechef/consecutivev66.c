#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int n;
  int *array;
}Con;

void find(Con *);
void deallocate(Con *);

void find(Con *sp)
{
  int i,j,count = 0;
  scanf("%d",&sp->n);
  sp->array = (int *)malloc(sizeof(int)*sp->n);
  for(i = 0;i<sp->n;i++)
  {
    scanf("%d",&sp->array[i]);
  }
  for(i=0;i<sp->n;i++)
  {
    for(j=i+1;j<sp->n;j++)
    {
      
    }
  }
}

int main()
{
  Con c1;
  find(&c1);
  deallocate(&c1);
  return 0;
}
