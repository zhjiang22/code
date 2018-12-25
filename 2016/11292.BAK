#include<stdio.h>
int n,m,a[100],b[100];
int main()
{
int i,j,t;
while(scanf("%d %d",&n,&m)==2&&n&&m)
{
int cur=0,count=0;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<m;i++)
scanf("%d",&b[i]);
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(a[i]>a[j])
{ t=a[i]; a[i]=a[j]; a[j]=t; }
for(i=0;i<m;i++)
for(j=i+1;j<m;j++)
if(b[i]>b[j])
{ t=b[i]; b[i]=b[j]; b[j]=t; }
for(i=0;i<n;i++)
{
if(b[i]>=a[cur])
{
cur++;
count+=b[i];
continue;
}
if(cur==m-1)
{
cur++;
break;
}
}
if(cur<n)
printf("Loowater is doomed");
else
printf("%d",count);
}
return 0;
}



