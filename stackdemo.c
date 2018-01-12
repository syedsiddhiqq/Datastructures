#include<stdio.h>
#define SIZE 10

//defining the stact structure here
typedef struct{
  int item[SIZE];
  int top;

}Stack;

//stack opertation declarations
void push(Stack *,int);
int pop(Stack *);
void init(Stack *);


// Push opeation definition
void push(Stack *sp,int val)
{
  if(sp->top == SIZE-1)
  {
    printf("\nStact Overflow");
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

void init(Stack *sp)
{
sp->top=-1;


}
int main()
{
// creating two structure object
Stack s1,s2;
init(&s1);
init(&s2);
push(&s1,100);
push(&s1,200);
push(&s2,10);
push(&s2,20);

printf("\nThe element popped is %d", pop(&s1) );
printf("\nThe element popped is %d", pop(&s1) );
printf("\nThe element popped is %d", pop(&s2) );
printf("\nThe element popped is %d", pop(&s2) );

  return 0;
}
