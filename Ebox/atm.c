#include<stdio.h>
#include<stdlib.h>

typedef struct{
  float rs;
  float amount;
}Atm;

int main()
{
  Atm a1;
  scanf("%f%f",&a1.rs,&a1.amount);
  if(((int)a1.rs%5==0) && (a1.rs>0 && a1.rs <=2000) && (a1.amount>0 && a1.amount <= 2000))
  {
    if(a1.rs >= a1.amount -0.50)
    {
      printf("%.2f",a1.amount);
    }
    else
    {
    a1.rs = a1.rs+0.50;
    a1.amount = a1.amount -a1.rs;
    printf("%.2f",a1.amount);
  }
  }
  else
  {
    printf("%.2f",a1.amount);
  }
  return 0;
}
