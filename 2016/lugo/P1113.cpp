#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=100005;
vector<int> g[MAXN];
int f[MAXN];
int t[MAXN];
int ans;
int n;

void init()
{
	int x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>t[i];
		while(cin>>x)
		{
			if(x==0)
				break;
			else
				g[i].push_back(x);
		}
	}
	memset(f,-1,sizeof(f));
}

int dp(int x)
{
	if(g[x].size()==0)
		return f[x]=t[x];
	if(f[x]!=-1)
		return f[x];
	int d=g[x].size();
	int ans=0;
	for(int i=0;i<d;i++)
		ans=max(ans,dp(g[x][i]));
	return f[x]=ans+t[x];
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		dp(i);
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}
     