#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF=999999999;
int a[100][100];
int n,e,cost=0;

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			if(a[i][j]!=-1&&a[j][k]!=-1)
				if(a[i][j]+a[j][k]<a[i][k])
				a[i][k]=a[i][j]+a[j][k];
}

int main()
{
	cin>>n>>e;
	int x,y,v;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=e;i++)
	{
		cin>>x>>y>>v;
		a[x][y]=v;
	}
	cin>>x>>y;
	Floyd();
	cout<<a[x][y]+a[y][x];
	return 0;
}