//header files

#include<stdio.h>
#include<stdlib.h>

//structure definition
typedef struct{
  int n;
  int *array;
  int difference;
}Pair;

void findpair(Pair *);
void deallocate(Pair *);

void findpair(Pair *sp)
{
  int i,j,count=0;
  scanf("%d",&sp->n);
  sp->array = (int *)malloc(sizeof(int)*sp->n);
  for(i=0;i<sp->n;i++)
  {
    scanf("%d",&sp->array[i]);
  }
  scanf("%d",&sp->difference);

   for(i=0;i<sp->n;i++)
   {
     for(j=i;j<sp->n;j++)
     {
       if((abs(sp->array[i]-sp->array[j])) == sp->difference)
       count++;
     }
   }
   printf("%d",count);
}

void deallocate(Pair *sp)
{
  if(sp->array!= NULL)
  {
    free(sp->array);
  }
}


int main()
{
  Pair p1;
  findpair(&p1);
  deallocate(&p1);

  return 0;
}
