#include<iostream>
using namespace std;
int f[1005][1005]={0};
int pa[1005];
int n,m;

int getfather(int x)
{
	return pa[x]==x?x:pa[x]=getfather(pa[x]);
}

void Union(int x,int y)
{
	pa[getfather(x)]=getfather(y);
}

int main()
{
	int x,y,ans=0;
	char z;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		pa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>z>>x>>y;
		if(z=='F')
		Union(x,y);
		else
		f[x][y]=f[y][x]=1;
	}	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			if(f[i][j]==1&&f[j][k]==1)
			Union(i,k);
	
	for(int i=1;i<=n;i++)
		if(pa[i]==i)
		ans++;
	cout<<ans<<endl;
	return 0;
}