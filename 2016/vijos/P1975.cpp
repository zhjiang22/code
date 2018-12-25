/*
水题啊
直接乱搞不就好了
对于每一个点
我们来直接对于每一个点
就直接搜索一下八个方向个数就好
水题Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int n,m;
int a[MAXN][MAXN];
int zx[8][2]={{-1,0},{-1,-1},{1,1},{0,-1},{1,0},{-1,1},{1,-1},{0,1}};

void init()
{
	char ch;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='*')
				a[i][j]=-1;
		}
}

int gets(int x,int y)
{
	int ans=0;
	for(int i=0;i<8;i++)
	{
		int newx=x+zx[i][0];
		int newy=y+zx[i][1];
		if(newx>n||newy>m||newx<1||newy<1)
			continue;
		if(a[newx][newy]==-1)
			ans++;
	}
	return ans;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]!=-1)
				a[i][j]=gets(i,j);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(a[i][j]==-1)
				cout<<'*';
			else
				cout<<a[i][j];
		cout<<endl;
	}
}
     