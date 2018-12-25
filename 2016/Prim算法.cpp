#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=2001;
const int INF=999999999;
int w[MAXN][MAXN];
int a[MAXN];
int n,e;

void init()
{
	int c,b;
	memset(w,0,sizeof(w));
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>c>>b>>w[c][b];
		w[b][c]=w[c][b];
	}
}

void prim(int s)
{
	int ans=0,Min;
	int k;
	for(int i=1;i<=n;i++)
		a[i]=w[s][i];
	a[s]=0;
	
	for(int i=1;i<n;i++)
	{
		Min=INF;
		for(int j=1;j<=n;j++)
		if(a[j]!=0&&a[j]<Min)
		{
			Min=a[j];
			k=j;
		}
		a[k]=0;
		ans+=Min;
		for(int j=1;j<=n;j++)
			a[j]=min(w[k][j],a[j]);
	}
	cout<<ans;
}

int main()
{
	init();
	prim(1);
	return 0;
}