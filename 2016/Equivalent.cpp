#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXN 
struct P
{
	int nxt,pre;
}a[1000];
int n,m;
int t;

void init()
{
	scanf("%d%d",&n,&m);	
	for(int i=1;i<=n;i++)
	{
		a[i].pre=i-1;
		a[i].nxt=i+1;
	}
}

void del(int x)
{
	a[a[x].pre].nxt=a[x].nxt;
	a[a[x].nxt].pre=a[x].pre;
}

void work()
{
	int k,x,y;
	while(m--)
	{
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)
		{
			del(x);
			a[x].nxt=y;	a[x].pre=a[y].pre;
			a[a[y].pre].nxt=x;	a[y].pre=x;
		}
		else
		{
			del(x);
			a[x].pre=y;	a[x].nxt=a[y].nxt;
			a[a[y].nxt].pre=x;	a[y].nxt=x;
		}
	}
	int cur=a[0].nxt;
	while(n--)
	{
		printf("%d ",cur);
		cur=a[cur].nxt;
	}
	printf("\n");
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		init();
		work();
	}
	return 0;
}