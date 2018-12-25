/*
好题啊~一个经典的并查集问题~
黑书上是有哒P275
讲一下大概的思路叭
抽象成图
网格交叉点：顶点
正面的线：正边
背面的线：负边
有边相连：连通块
每个连通块分别求
对于某个顶点i
|正边数-负边数|=K>0时
以该顶点为开始或结束的针数>=K
可以恰好为K针
所有K值加起来，除以2（每一针有两个端点）
注意差值为0时，为1针而不是0针
所以直接处理一下就好啦~
细节需要注意OTZ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=202;
int in[MAXN*MAXN];
int fa[MAXN*MAXN];
int b[MAXN*MAXN];
int c[MAXN*MAXN];
int p[MAXN*MAXN];
bool v[MAXN*MAXN];
char g[2][MAXN][MAXN];
int ans,l;
int n,m;

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void init()
{
	cin>>n>>m;
	for(int k=0;k<2;k++)
		for(int i=0;i<n;i++)
			scanf("%s",g[k][i]);
	for(int i=0;i<=(n+1)*(m+1);i++)
		fa[i]=i;
}

void getg()
{
	for(int k=0;k<2;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(g[k][i][j]=='\\'||g[k][i][j]=='X')
				{
					int x=i*(m+1)+j;	int y=(i+1)*(m+1)+j+1;
					int fx=find(x);	int fy=find(y);
					if(fx!=fy)
						fa[fy]=fx;
					in[x]+=(-k*2)+1;	in[y]+=(-k*2)+1;
					v[x]=v[y]=1;
				}
				if(g[k][i][j]=='/'||g[k][i][j]=='X')
				{
					int x=i*(m+1)+j+1;	int y=(i+1)*(m+1)+j;
					int fx=find(x);	int fy=find(y);
					if(fx!=fy)
						fa[fy]=fx;
					in[x]+=(-k*2)+1;	in[y]+=(-k*2)+1;
					v[x]=v[y]=1;
				}
			}
}

void work()
{
	for(int i=0;i<(n+1)*(m+1);i++)
	{
		if(!v[i])	continue;
		int k=find(i);
		if(!p[k]){p[k]=1;c[++l]=k;}
		b[k]+=abs(in[i]);
	}
	for(int i=1;i<=l;i++)
		if(!b[c[i]])
			ans++;
		else
			ans+=b[c[i]]/2;
	cout<<ans<<endl;
}

int main()
{
	init();
	getg();
	work();
	return 0;
}
     