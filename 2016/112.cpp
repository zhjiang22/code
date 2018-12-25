#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=17;
vector<int> v[MAXN];
string a[MAXN];
bool vis[MAXN];
int f[MAXN];
int ans;
int n;

void init()
{
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int l=a[i].length();
		if(a[i][0]=='A')
			v[1].push_back(i);
		else	if(a[i][0]=='E')
			v[2].push_back(i);
		else	if(a[i][0]=='I')
			v[3].push_back(i);
		else	if(a[i][0]=='O')
			v[4].push_back(i);
		else	if(a[i][0]=='U')
			v[5].push_back(i);
	}
}

void dfs(int x,int now)
{
	ans=max(ans,now);
	int l=a[x].length();
	char p=a[x][l-1];
	int k=0;
	if(p=='A')
		k=1;
	else	if(p=='E')
		k=2;
	else	if(p=='I')
		k=3;
	else	if(p=='O')
		k=4;
	else	if(p=='U')
		k=5;
	int d=v[k].size();
	for(int i=0;i<d;i++)
	{
		if(!vis[v[k][i]])
		{
			vis[v[k][i]]=1;
			dfs(v[k][i],now+a[v[k][i]].length());
			vis[v[k][i]]=0;
		}
	}
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		dfs(i,a[i].length());
	}
	cout<<ans<<endl;
	return 0;
}
     