#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int INF=0x7fffff;
int w[102][102];
int d[102];
int n;

void Prim()
{
	int ans=0;
	for(int i=1;i<=n;i++)
		d[i]=w[1][i];

	for(int i=1;i<n;i++)
	{
		int p;
		int Min=INF;
		for(int j=1;j<=n;j++)
			if(d[j]&&d[j]<Min)
			{
				p=j;
				Min=d[j];
			}
		d[p]=0;
		ans+=Min;
		for(int j=1;j<=n;j++)
			if(w[p][j]<d[j])
				d[j]=w[p][j];
	}
	cout<<ans;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>w[i][j];

	Prim();
	return 0;
}