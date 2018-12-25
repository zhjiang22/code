#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int c[MAXN];
int d[MAXN];
int n,m;
int ans=999999999;

void dfs(int now,int day,int w)
{
	if(now==n)
	{
		ans=min(w,ans);
		return;
	}
	if(day==m+1)
		return;
	dfs(now,day+1,w);
	dfs(now+1,day+1,w+c[day]*d[now+1]);
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	dfs(0,1,0);
	cout<<ans<<endl;
	return 0;
}
     