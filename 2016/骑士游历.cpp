#include<iostream>
#include<cstring>
using namespace std;

int zx[9]={0,1,1,2,2,-2,-2,-1,-1};
int zy[9]={0,2,-2,1,-1,1,-1,2,-2};
int a[100][100];
int vis[100][100];
int n,m,x,y,tot;

int check(int x,int y)
{
	return (x>=0&&x<=n-1&&y>=0&&y<=m-1&&vis[x][y]==0);
}

void dfs(int x,int y,int cur)
{
	if(cur>=n*m)
	{
		tot++;
		return;
	}
	for(int i=1;i<=8;i++)
	{
		int q=x+zx[i];
		int p=y+zy[i];
		
		if(check(q,p))
		{
			vis[q][p]=1;
			dfs(q,p,cur+1);
			vis[q][p]=0;
		}
	}	
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		tot=0;
		cin>>n>>m>>x>>y;
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		dfs(x,y,1);
		cout<<tot<<endl;
	}
	return 0;
}