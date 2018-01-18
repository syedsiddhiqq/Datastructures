#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,k,num,i,result=0,l,c=0;
    char a[30000];
    fgets(a,30000,stdin);
    sscanf(a,"%d %d",&n,&k);
    while(c<n)
    {
        l = fread(a,1,30000, stdin);
        printf("%d",l);

        for(i = 0; i < l ;++i)
        {
            if (a[i] == '\n' )
            {
               c++;
               if((num%k) == 0) ++result;
               num = 0;
            }
            else
                num = num*10 + (a[i] - '0');
        }
    }
    printf("%d\n",result);
    return 0;
}
