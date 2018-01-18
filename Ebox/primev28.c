#include<stdio.h>
int main()
{
    int number,a[5],x,i,count=1,j,counter,z=0;
    scanf("%d",&number);
   x= number%10;
	for(i=0;number>=10;i++)
	{
	    number = number/10;
	    a[i] = number%10;
	    count++;

	}
    if(count==4)
    {a[3] = x;

      for(i=0;i<4;i++)

        {
             counter=0;

            for(j=2;j<a[i];j++)
                {
                    if(a[i]%j==0)
                         {
                             counter=1;
                            break;
                         }
                 }
                 if(counter==0 && a[i]!=0 && a[i]!=1)
                {
                a[i]=1;
               // printf("%d",a[i]);
                 }
                 else
                 {
                     a[i]=0;
                 }

        }

        for(i=0;i<4;i++)
        {
            if(a[i]==1)
            z++;
            //printf("%d",a[i]);
        }

        if(z==2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    else
    {
        printf("Invalid Input\n");
    }
	return 0;
}
