#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct node
{
	double x,y,v;
}a[1003];
struct vode
{
	double x,y;
}b[1003];
int r,n,t;
int visit[1002]={0};
int Link[1002]={0};
int map[1002][1002]={0};

bool dfs(int x)
{
	for(int i=1;i<=n;i++)
		if(!visit[i]&&map[x][i])
		{
			visit[i]=1;
			if(!Link[i]||dfs(Link[i]))
			{
				Link[i]=x;
				return true;
			}
		}
	return false;
}

int main()
{
	int ans=0;
	cin>>r>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>b[i].x>>b[i].y;
	for(int i=1;i<=r;i++)
		cin>>a[i].x>>a[i].y>>a[i].v;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=n;j++)
		{
			if((a[i].v*t)*(a[i].v*t)>=((a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y)))
				map[i][j]=1;
		}
	for(int i=1;i<=r;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))
				ans++;
	}
	cout<<ans<<endl;
	return 0;
}
     