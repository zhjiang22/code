#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN=105;
struct node
{
	int x,y,step;
	node(int x,int y,int step):x(x),y(y),step(step){}
}
queue<node> q;
bool a[MAXN][MAXN];
int g[MAXN][MAXN][MAXN];
int n,m;
node to;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	int sx,sy;
	cin>>sx>>sy>>to.x>>to.y;
	q.push((node)(sx,sy,0));x
}

int main()
{
	init();
}