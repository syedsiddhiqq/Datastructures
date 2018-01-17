#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int n;
  int *array;
  int *array2;
}Con;

void find(Con *);
void deallocate(Con *);

void find(Con *sp)
{
  int i,j,count = 0,temp,difference=5;
  scanf("%d",&sp->n);
  sp->array = (int *)malloc(sizeof(int)*sp->n);
  sp->array2 = (int *)malloc(sizeof(int)*sp->n);
  for(i = 0;i<sp->n;i++)
  {
    scanf("%d",&sp->array[i]);
  }

difference = abs(sp->array[0]-sp->array[1]); // finding the difference between two indices and assigning to difference
  for(i=0;i<sp->n;i++)
{
  for(j=i+1;j<sp->n;j++)
  {
    if(difference>abs(sp->array[i]-sp->array[j]))//checking if the difference is lesser than the assigned one if yes then replace
    {
      difference = abs(sp->array[i] - sp->array[j]);
    }
  }
}
printf("%d",difference - 1);
}

void deallocate(Con *sp)
{
  free(sp->array);
  free(sp->array2);
}

int main()
{
  Con c1;
  find(&c1);
  deallocate(&c1);
  return 0;
}
