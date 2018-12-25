#include<stdio.h>
int main()
{
long n;
int i=1;
scanf("%ld",&n);
while(n>=10)
{
n/=10;
i++;
}
printf("%d",i);
return 0;
}