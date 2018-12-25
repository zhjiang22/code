#include<stdio.h>
#include<string.h>
char a[100];
int main()
{
int i=0,t,j,m;
long b;
scanf("%ld",&b);
scanf("%d",&m);
while(b>=10)
{
a[i++]=b%10;
b/=10;
}
a[i++]=b;
a[i]='/0';
j=strlen(a);
if(m==0)
puts(a);
if(m>j)
printf("Error");
if(m>0&&m<=j)
for(t=j-1;t>(j-m);t--)
printf("%d",a[t]);
return 0;
}
