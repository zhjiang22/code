#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=200005;
struct Edge
{
	int to,w,nxt;
	Edge()
	{
		to=nxt=-1;
		w=0;
	}
}e[MAXN<<1];
int n;
int in[MAXN];
int maxw[MAXN];
int fisrt[MAXN];
int tot;
int ans;
int sum;

void inline Add_Edge(int x,int y,int w)
{
	tot++;
	e[tot].to=y;
	e[tot].w=w;
	e[tot].nxt=fisrt[x];
	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	int x,y,w;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		Add_Edge(x,y,w);
		Add_Edge(y,x,w);
		in[x]++;	in[y]++;
		maxw[x]=max(maxw[x],w);
		maxw[y]=max(maxw[y],w);
	}
}

int main()
{
	init();
	
	return 0;
}
     