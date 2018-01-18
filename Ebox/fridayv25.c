#include<stdio.h>
#include<string.h>
int main()
{
char d[100];
int n ;
scanf("%s",d);
scanf("%d",&n);
if((n>=1)&&(n<=365)&&(strlen(d)<=10))
{
 //   printf("hello");
if((strcmp(d,"SUN")==0)&&(n%7==6))
    printf("YES");
else if((strcmp(d,"MON")==0)&&(n%7==5))
    printf("YES");
else if((strcmp(d,"TUE")==0)&&(n%7==4))
    printf("YES");
else if((strcmp(d,"WED")==0)&&(n%7==3))
    printf("YES");
else if((strcmp(d,"THU")==0)&&(n%7)==2)
    printf("YES");
else if((strcmp(d,"FRI")==0)&&(n%7==1))
    printf("YES");
else if((strcmp(d,"SAT")==0)&&(n%7==0))
    printf("YES");
else if(!((strcmp(d,"SUN")==0)||(strcmp(d,"MON")==0)||(strcmp(d,"TUE")==0)||(strcmp(d,"WED")==0)||(strcmp(d,"THU")==0)||(strcmp(d,"FRI")==0)||(strcmp(d,"SAT")==0)))
    printf("Invalid Input");
else
    printf("NO");
}
else
printf("Invalid Input");
	return 0;
}
