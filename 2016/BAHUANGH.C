#include<stdio.h>
int n,c[10];
void huanghou(int cur)
{
int i,j,ok;
if(cur==n)
{
for(i=0;i<cur;i++)
printf("%d¸ö",c[i]);
printf("\n");
}
else
{
for(i=0;i<n;i++)
{
ok=1;
c[cur]=i;
for(j=0;j<cur;j++)
if(c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j])
{
ok=0;break;
}
if(ok)
huanghou(cur+1);
}
}
}
int main()
{
for(int i=0;i<1000;i++)
c[i]=0;
scanf("%d",&n);
huanghou(0); 
getchar();
return 0;
}
