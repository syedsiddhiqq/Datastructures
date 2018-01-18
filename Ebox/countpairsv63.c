#include<stdio.h>
#include<stdlib.h>

//structure definition
typedef struct{
  int n;
  int *array;
  int number;
}Pair;

void sortarray(Pair *);
void deallocate(Pair *);
void count(Pair *);

void sortarray(Pair *sp)
{
  int i,j,count = 0,temp,sum=0;
  scanf("%d",&sp->n);
  sp->array = (int *)malloc(sizeof(int)*sp->n);
  for(i=0;i<sp->n;i++)
  {
    scanf("%d",&sp->array[i]);
  }
  scanf("%d",&sp->number);
  for(i=0;i<sp->n;i++)
  {
    for(j=i+1;j<sp->n;j++)
    {
      if(sp->array[i]>sp->array[j])
      {
        temp = sp->array[i];
        sp->array[i] = sp->array[j];
        sp->array[j] =  temp;
      }
    }
  }
  for(i=0;i<sp->n;i++)
  {
    /*
    if(sum<=sp->number)
    {
      sum = sum+sp->array[i];
      count++;
    }
    */
    if(sp->number>=sp->array[i])
    {
      sp->number -= sp->array[i];
      count++;
    }
  }
  printf("%d",count);
}

void deallocate(Pair *sp)
{
  if(sp->array != NULL)
  {
    free(sp->array);
  }
}
int main()
{
  Pair p1;
  sortarray(&p1);
  deallocate(&p1);
  return 0;
}
