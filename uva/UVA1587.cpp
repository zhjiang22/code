#include<bits/stdc++.h>
using namespace std;

const int MAXN=7;
const int MAXM=10005;
struct P
{
	int x,y;
	bool operator<(const P& p)const
	{
		if(x==p.x)
			return y<p.y;
		return x<p.x;
	}
}a[MAXN];
int n=6;
int xx,yy;
int vis[MAXM];

void init()
{
	memset(vis,0,sizeof(vis));
	if(xx<yy)
		swap(xx,yy);
	a[1].x=xx;	a[1].y=yy;
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x<a[i].y)
			swap(a[i].x,a[i].y);
	}
}

void work()
{
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i+=2)
		if(a[i].x!=a[i+1].x||a[i].y!=a[i+1].y)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
	for(int i=1;i<=n;i++)
		vis[a[i].x]=vis[a[i].y]=1;
	int cnt=0;
	for(int i=1;i<=10000;i++)
		if(vis[i])
			cnt++;
	if(cnt>3)
		printf("IMPOSSIBLE\n");
	else
		printf("POSSIBLE\n");
}

int main()
{
	while(scanf("%d%d",&xx,&yy)==2)
	{
		init();
		work();
	}
	return 0;
}
     