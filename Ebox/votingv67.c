#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int n;
  int *array1;
  int *array2;
  int *array3;
}Vote;

void init(Vote *);
void deallocate(Vote *);
void getdata(int *,int);
void findcount(Vote *);

void getdata(int *array,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d",&array[i]);
  }
}
void deallocate(Vote *v)
{
  free(v->array1);
  free(v->array2);
  free(v->array3);
}

void init(Vote *v)
{
  int i;
  scanf("%d",&v->n);
  v->array1 = (int *)malloc(sizeof(int)*v->n);
  v->array2 = (int *)malloc(sizeof(int)*v->n);
  v->array3 = (int *)malloc(sizeof(int)*v->n);
  getdata(&v->array1[0],v->n);
  getdata(&v->array2[0],v->n);
  getdata(&v->array3[0],v->n);
}

void findcount(Vote *v)
{
  int i,j,count1 = 0,count2 = 0;
  for(i=0;i<v->n;i++)
  {
    if(v->array1[i]==v->array3[i])
    count1++;
  }
  for(i=0;i<v->n;i++)
  {
    if(v->array2[i] == v->array3[i])
    count2++;
  }

  if(count1 > v->n/2 && count2 > v->n/2)
  {
    printf("Both the ministers are satisfied");
  }
  else if(count1 > v->n/2 || count2 > v->n/2)
  {
    printf("One minister is satisfied");
  }
else
{
    printf("Both the ministers are unsatisfied");
}




}

int main()
{
  Vote v1;
  init(&v1);


  deallocate(&v1);
  return 0;
}
