#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=505;
int f[MAXN][MAXN];
int a[MAXN];
int b[MAXN];
int n,m;
int ans,res;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
}

void print(int s,int t)
{
	if(t==0||s==0)
		return;
	if(a[s]!=b[t])
		print(s,t-1);
	else
	{
		int cur=0,p=0;
		for(int k=1;k<s;k++)
			if(a[k]<a[s]&&cur<f[k][t-1])
			{
				cur=f[k][t-1];
				p=k;
			}
		if(cur!=0)
			print(p,t-1);
		cout<<a[s]<<" ";
	}
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]!=b[j])
				f[i][j]=f[i][j-1];
			else
			{
				for(int k=1;k<i;k++)
					if(a[k]<a[i])
						f[i][j]=max(f[i][j],f[k][j-1]);
				f[i][j]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(ans<f[i][m])
		{
			ans=f[i][m];
			res=i;
		}
	cout<<ans<<endl;
	if(ans!=0)
		print(res,m);
	return 0;
}
     