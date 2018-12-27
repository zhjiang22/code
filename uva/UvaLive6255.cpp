#include <bits/stdc++.h>
using namespace std;

const int MAXN=22;
int g[MAXN][MAXN];
int can[MAXN];
int t;
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&g[i][j]);
}

void doit(int x)
{
	bool ok[MAXN];
	memset(ok,0,sizeof(ok));
	for(int i=x;i<=x+n-1;i++)
	{
		int cur=i%(n+1)+1;
		int tot=0;
		for(int j=1;j<=n;j++)
			if(!ok[j])
				tot+=g[cur][j];
		if(tot>0)
			ok[cur]=1;
	}
	int tot=0;
	for(int i=1;i<=n;i++)
		if(!ok[i])
			tot++;
	if(tot==1)
		for(int i=1;i<=n;i++)
			if(!ok[i])
				can[i]=1;
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		doit(i);
	}
	for(int i=1;i<=n;i++)
		if(can[i])
			cout<<i<<" ";
	cout<<endl;
}

int main()
{
	cin>>t;
	while(t--)
	{
		init();
		work();
	}
	return 0;
}