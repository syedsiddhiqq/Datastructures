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


int getSize(Stack *sp)
{
  return sp->size;
}

// Push opeation definition
void push(Stack *sp,int val)
{
  // if the top of the stack is equal to the size of the array then we are doubling the size of the array
  if(sp->top == sp->size-1)
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
  if(sp->top==-1)
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
// creating two structure object
Stack s1;
init(&s1,2);

int choice;
int value;
printf("\n1.Push \n2.Pop \n3.Exit");

while(1)
{
  printf("\nEnter the choice");
  scanf("%d",&choice );
  printf("Size of the stack is %d",getSize(&s1));
  switch (choice) {
    case 1:
      printf("\nEnter the element to be pushed" );
      scanf("%d",&value);
      push(&s1,value);
      break;

    case 2:
      value = pop(&s1);
      if(value != -9999)
      {
        printf("\n popped data%d",value);
      }
      break;
    case 3:
      deallocate(&s1);
      exit(0);
    default:
    printf("\n Invalid choice");
  }
}

  return 0;
}
