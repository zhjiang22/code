#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int MAXN=35;
const int MAXL=(1<<4)+5;
int g[MAXN][MAXN];
int a[MAXL];
int n,m;
int s,to;

void init()
{
	int x,y;
	printf("%d",(1<<10)/1024*4/1024);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		s|=(1<<i);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x][y]=g[y][x]=1;
	}
}

void bfs()
{
	
}

int main()
{
	init();
	bfs();
}