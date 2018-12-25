#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=505;
const int INF=(1<<30)-1;
struct node
{
	int l,r;
	node()
	{
		l=0;	r=INF;
	}
	bool operator<(const node& b)
	{
		return l<b.l;
	}
};
node g[MAXN];
int a[MAXN][MAXN];
bool v[MAXN][MAXN];
bool can[MAXN];
int zx[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int ans;
int n,m;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		a[i][0]=a[i][m+1]=INF;
	for(int i=1;i<=m;i++)
		a[0][i]=a[n+1][i]=INF;
	ans=m;
}

void dfs(int x,int y,int n_clock)
{
	if(x==n)
	{
		if(!can[y])
		{
			can[y]=1;
			ans--;
		}
		g[n_clock].l=max(g[n_clock].l,y);
		g[n_clock].r=min(g[n_clock].r,y);
	}
	v[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int newx=x+zx[i][0];	int newy=y+zx[i][1];
		if(v[newx][newy]||newx>n||newx<1||newy>m||newy<1)
			continue;
		if(a[newx][newy]<a[x][y])
			dfs(newx,newy,n_clock);
	}
}

int solve()
{
	sort(g+1,g+m+1);
	int L=1,cnt=0,k=1;
	while(L<=m)
	{
		cnt++;
		int R=L;
		for(;k<=m&&a[k].l<=L;k++)
			R=max(R,a[k].r);
		L=R+1;
	}
	return cnt;
}

int main()
{
	init();
	for(int i=1;i<=m;i++)
	{
		memset(v,0,sizeof(v));
		dfs(1,i,i);
	}
	if(ans)
		cout<<0<<endl<<ans<<endl;
	else
		cout<<1<<endl<<solve()<<endl;
	return 0;
}
     