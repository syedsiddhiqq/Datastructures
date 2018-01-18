  //header files
  #include<stdio.h>
  #include<stdlib.h>

  //structure creation

  typedef struct {
    int n;

    int *array;
  }Sort;

void init(Sort *);

void init(Sort *sp)
  {
    // variable Initialization
    int countzero=0,i,lastindex,countindex=0,j,y,x,temp;
    lastindex = sp->n;
    x = sp->n-1;


    //dynamically allocating the array
    sp->array = (int *)malloc(sizeof(int) * sp->n);

    //getting the array elements
    for(i=0;i<sp->n;i +=1)
    {
      scanf("%d",&sp->array[i]);

    }

    //checking if the file 0 is present if yes then incrementing by 1
    for(i=0;i<sp->n;i++)
    {
      if(sp->array[i]==0)
      countzero++;

    }

      if(countzero==0)
      {
        for(i=0;i<sp->n;i++)
        printf("%d",sp->array[i]);
      }
      else
      {
        //checking if the file 0 is in the lastindex
          for(i=0;i<countzero;i++)
          {
            lastindex -= 1;
            if(sp->array[lastindex] != 0)
            countindex++;

          }

          if(countindex == 0)
          {
            for(i=0;i<sp->n;i++)
            printf("%d",sp->array[i]);
          }
          else
          {
              for(i=0;i<countzero;i++)
              {
                for(j=0;j<=x;j++)
                {
                  y = j;
                  if(sp->array[y]==0)
                  {
                    while(y != x)
                    {
                      temp = sp->array[y];
                      sp->array[y] = sp->array[y+1];
                      sp->array[y+1] = temp;
                    y++;
                  }
                  x--;
                }
              }
            }
            for(i=0;i<sp->n;i++)
            printf("%d",sp->array[i]);
          }



  }}



  void deallocate(Sort *sp)
  {
    if(sp->array != NULL)
    free(sp->array);
  }


  int main()
  {
    Sort s1;
    scanf("%d",&s1.n);
    init(&s1);
    deallocate(&s1);



    return 0;
  }
