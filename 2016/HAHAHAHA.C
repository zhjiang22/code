#include<stdio.h>
#include<string.h>
char a[5000];
int main()
{
int i,j,n;
gets(a);
n=strlen(a);
for(i=n-1;i>=0;i--)
{
if(a[i]==' ')
{
for(j=i+1;j<n;j++)
printf("%c",a[j]);
printf(" ");
n=i;
}
}
for(j=0;j<n;j++)
printf("%c",a[j]);
return 0;
}

