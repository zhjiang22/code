#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int INF=9999999;
int k;
int a[10][10];
string n;

void Floyd()
{
	for(int k=0;k<=9;k++)
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
			{
				if(i==j)
				a[i][j]=0;
				else a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
			}
}

int main()
{
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
		a[i][j]=INF;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=0;
	}
	Floyd();
	long long ans=1;
	for(int i=0;i<n.length();i++)
	{
		int temp=0;
		int now=n[i]-'0';
		
		for(int j=0;j<=9;j++)
			if(a[now][j]==0)
			temp++;
			
		ans*=temp;
	}
	cout<<ans<<endl;
	return 0;
} 