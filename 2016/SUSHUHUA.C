#include<stdio.h>
#include<string.h>

int n,ok;
int vis[10000],a[100],b[1000];

int prime(int c)
{
int i;
for(i=2;i<(c/2);i++)
{
if(c%i==0) return 0;
}
return 1;
}

void huan(int cur)
{
int i,j;
if(cur==n&&vis[a[0]+a[cur-1]])
{
for(i=0;i<n;i++)
printf("%d",a[i]);
printf("\n");
}
else
{
for(i=2;i<=n;i++)
{
ok=1;
if(vis[i+a[cur-1]]&&!b[i])
{
a[cur]=i;
b[i]=1;
huan(cur+1);
b[i]=0;
}
}
}
}

int main()
{
int o;
scanf("%d",&n);
a[0]=1;
memset(vis,0,sizeof(vis));
memset(b,0,sizeof(b));
for(o=1;o<n*n;o++)
vis[o]=prime(o);
huan(1);
return 0;
}

