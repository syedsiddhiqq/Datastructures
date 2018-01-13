#include<stdio.h>
#include<stdlib.h>


//defining the stact structure here
typedef struct{
  int *item;
  int top;
  int size;

}Stack;

//stack opertation declarations
void push(Stack *,int);
int pop(Stack *);
void init(Stack *,int);
void deallocate(Stack *);
int getSize(Stack *);
void decToBinary(unsigned int);
int isUnderFlow(Stack *);
int isOverFlow(Stack *);

void decToBinary(unsigned int n)
{
  Stack s;
  init(&s,10);
  int temp = n;
  int rem;
  while(n>0)
  {
    rem = n%2;
    push(&s,rem);
    n = n/2;
  }
printf("The binary equivalent of %d is ",temp);
while(!isUnderFlow(&s))
{
  printf("%d",pop(&s));
}
deallocate(&s);
}


int isOverFlow(Stack *sp)
{
  return sp->top == sp->size-1;
}

int isUnderFlow(Stack *sp)
{
  return sp->top==-1;
}


int getSize(Stack *sp)
{
  return sp->size;
}





// Push opeation definition
void push(Stack *sp,int val)
{
  // if the top of the stack is equal to the size of the array then we are doubling the size of the array
  if(isOverFlow(&sp))
  {
    //here we are dynamically creating an array
    int *temp = (int *)malloc(sizeof(int)*sp->size * 2);
    int i;
    if(temp == NULL)
    {
      printf("\n Stack Overflow");
    }
    //assigning all the values of item to temp
    for(i=0;i<=sp->top;i++)
  {
    temp[i] = sp->item[i] ;
  }
  // freeing the sizeof the item array
  free(sp->item);
  //returning back the temp array to item array
  sp->item = temp;
  sp->size *=2;
 }
else{
    sp->top++;
    sp->item[sp->top] = val;
}
}




int pop(Stack *sp)
{
  //checking for stack underflow
  if(isUnderFlow(&sp))
  {
    printf("\n Stack underflow" );
    return -9999;
  }
  else
  {

    int value;
    value = sp->item[sp->top];
    sp->top--;
    return value;
  }
}





void init(Stack *sp,int size)
{
sp->top=-1;
sp->item = (int *)malloc(sizeof(int) * size);
if(sp->item == NULL)
{
  printf("\nUnable to allocate memory");
}
sp->size = size;

}




void deallocate(Stack *sp)
{
  if(sp->item != NULL)
  free(sp->item);
}



int main()
{
decToBinary(10);

  return 0;
}
