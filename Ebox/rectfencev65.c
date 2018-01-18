#include<stdio.h>
#include<stdlib.h>
typedef struct {
  int n;
  int *array1;
  int *array2;
  int rate;
}Rect;
void calculate(Rect *);
void deallocate(Rect *);

void calculate(Rect  *sp)
{
  int i,j,mina,maxa,minb,maxb,x,y,val;
  scanf("%d",&sp->n);
  sp->array1 = (int *)malloc(sizeof(int)*sp->n);
  sp->array2 = (int *)malloc(sizeof(int)*sp->n);
  for(i=0;i<sp->n;i++)
  {
    scanf("%d%d",&sp->array1[i],&sp->array2[i]);
  }
  scanf("%d",&sp->rate);
  mina = sp->array1[0];
  maxa = sp->array1[0];
  minb = sp->array2[0];
  maxb = sp->array2[0];
  for(i=0;i<sp->n;i++)
  {
    if(mina>sp->array1[i])
    mina = sp->array1[i];
    if(maxa<sp->array1[i])
    maxa = sp->array1[i];
    if(minb>sp->array2[i])
    minb = sp->array2[i];
    if(maxb<sp->array2[i])
    maxb = sp->array2[i];
  }
  x = (maxa - mina)+10;
  y = (maxb - minb)+10;
  val = 2*(x+y);
  printf("%d",(y*sp->rate));

}

void deallocate(Rect *sp)
{
  if(sp->array1 != NULL && sp->array2 != NULL)
  free(sp->array1);
  free(sp->array2);
}

int main()
{
  Rect r1;
  calculate(&r1);
  deallocate(&r1);
  return 0;
}
