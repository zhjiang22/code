#include<stdio.h>
#include<string.h>
int n,c=0;
char a[100];
int check(int i)
{
int ok=1,b,d;
c=0;
while(i>=n)
{
a[c++]=(i%n);
i/=n;
}
a[c]='/0';
for(b=0;b<(strlen(a)+1)/2;b++)
for(d=c-1;d>=(strlen(a)+1)/2;d--)
if(a[b]!=a[d]) ok=0;
return ok;
}
int main()
{
int i,j,m;
scanf("%d",&n);
for(i=1;i<=300;i++)
{
if(check(m*m))
{
for(i=0;i<c;i++)
printf("%d",a[i]);
}
}
return 0;
}

