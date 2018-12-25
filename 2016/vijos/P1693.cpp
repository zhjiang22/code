#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[210],b[210];
int map[210][210];
int visit[210];
int Link[210];
int n,m;

bool dfs(int x)
{
	for(int i=1;i<=m;i++)
	{
		if(!visit[i]&&map[x][i])
		{
			visit[i]=1;
			if(!Link[i]||dfs(Link[i]))
			{
				Link[i]=x;
				return true;
			}
		}
	}
	return false;
}

int check(long long x,long long y)
{
	long long w=x+y+1;
	for(long long i=1;i<=w;i<<=1)
		if(w==i)
			return 1;
	return 0;
}

int main()
{
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=m;j++)
		cin>>b[j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(check(a[i],b[j]))
				map[i][j]=1;
	}
	for(int i=1;i<=n;i++)
		{
			memset(visit,0,sizeof(visit));
			if(dfs(i))
					ans++;}
	if(ans)
		cout<<ans<<endl;
	else
		cout<<"I want nobody nobody but you";
	return 0;
}
     