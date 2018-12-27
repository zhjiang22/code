#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int fa[50005];
int Rank[50005];
int n,k,ans;

void init()
{
	for(int i=1;i<=n;i++)
		fa[i]=i,Rank[i]=0;
}

int find(int x)
{
	if(x!=fa[x])
	{
		int t=fa[x];
		fa[x]=find(fa[x]);
		Rank[x]=(Rank[x]+Rank[t])%3;
	}
	return fa[x];
}

void Union(int x,int y,int d)
{
	int xf=find(x);
	int yf=find(y);
	fa[xf]=yf;
	Rank[xf]=(Rank[y]-Rank[x]+3+d)%3;
}

int main()
{
	cin>>n>>k;
	init();
	while(k--)
	{
		int d,x,y;
		cin>>d>>x>>y;
		if(x>n||y>n||(d==2&&x==y))
			ans++;
		else
		{
			int xf=find(x);
			int yf=find(y);
			if(xf==yf)
			{
				if((Rank[x]-Rank[y]+3)%3!=d-1)
					ans++;
			}
			else
				Union(x,y,d-1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
     