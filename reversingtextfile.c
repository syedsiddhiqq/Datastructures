#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//defining the stact structure here
typedef struct{
  char *item;
  int top;
  int size;

}Stack;

//stack opertation declarations
void push(Stack *,char);
char pop(Stack *);
void init(Stack *,int);
void deallocate(Stack *);
int getSize(Stack *);
void decToBinary(unsigned int);
int isUnderFlow(Stack *);
int isOverFlow(Stack *);




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
void push(Stack *sp,char val)
{
  // if the top of the stack is equal to the size of the array then we are doubling the size of the array
  if(isOverFlow(sp))
  {
    //here we are dynamically creating an array
    char *temp = (char *)malloc(sizeof(char)*sp->size * 2);
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




char pop(Stack *sp)
{
  //checking for stack underflow
  if(isUnderFlow(sp))
  {
    printf("\n Stack underflow" );
    return '\0';
  }
  else
  {

    char value;
    value = sp->item[sp->top];
    sp->top--;
    return value;
  }
}





void init(Stack *sp,int size)
{
sp->top=-1;
sp->item = (char *)malloc(sizeof(char) * size);
if(sp->item == NULL)
{
  printf("\nUnable to allocate memory");
  exit(1);
}
sp->size = size;

}




void deallocate(Stack *sp)
{
  if(sp->item != NULL)
  free(sp->item);
}

int reverseit(char source[],char destination[])
{
  FILE *fps,*fpd;
  const int SIZE = 50;
  fps = fopen(source,"r");
  if(fps == NULL)
  {
    printf("\nError opening the file");
    return 0;
  }
  fpd = fopen(destination,"w");
  if(fpd == NULL)
  {
    printf("\nError opening the file");
    return 0;
  }
  Stack s;
  init(&s,SIZE);
  char buff;
  buff = fgetc(fps);
  while(!feof(fps))
  {
    push(&s,buff);
    buff = fgetc(fps);
  }
  while(!isUnderFlow(&s))
  {
    fputc(pop(&s),fpd);
  }
  fclose(fps);
  fclose(fpd);
  deallocate(&s);
  return 1;
}


int main()
{

int f = reverseit("/home/godofspeed/Ds/file1.txt","/home/godofspeed/Ds/file2.txt");
if(f)
{
  printf("\nThe file copied successfully");
}
else
{
  printf("\nFailed to copy the file");
}

  return 0;
}
