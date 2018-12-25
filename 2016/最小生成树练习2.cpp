#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
const int INF=0x7ffff;
int w[1002][1002];
int d[1002];
int n;
int e;

void Prim()
{
	int ans=0;
	for(int i=1;i<=n;i++)
		d[i]=w[1][i];
	d[1]=0;
	for(int i=1;i<n;i++)
	{
		int Min=INF,p=1;
		for(int j=1;j<=n;j++)
		{if(d[j]&&d[j]<Min)
				{
					Min=d[j];
					p=j;
				}}
		d[p]=0,ans+=Min;
		for(int j=1;j<=n;j++)
			if(w[p][j]<d[j])
				d[j]=w[p][j];
	}
	cout<<ans<<endl;
}

int main()
{
	 cin>>n>>e;
	 int x,y,v;
	 for (int i = 1; i <= n; ++i)
	 	for(int j=1;j<=n;j++)
	 		w[i][j]=INF;
	 for (int i = 1; i <= e; ++i)
	 {
	 	cin>>x>>y>>v;
	 	w[x][y]=w[y][x]=v;
	 }
	 Prim();
	 return 0;
}
     