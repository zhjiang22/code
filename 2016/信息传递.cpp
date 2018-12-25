#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int INF=0x7ffff;
int w[2000][2000];
int G[2000][2000];
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[i][j]=G[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		G[i][x]=w[i][x]=1;
	}
	int ans=INF;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
			for(int j=i+1;j<k;j++)
				ans=min(G[i][j]+w[i][k]+w[k][j],ans);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	}
	cout<<ans<<endl;
}
     