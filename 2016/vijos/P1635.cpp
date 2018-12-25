/*
因为是从1到n结点单源最短路径
所以直接用SPFA就好了
裸的SPFA呀
要记录下最短路的路径并且输出
第一次写这道题的时候还年轻
倒着用fa[]推一遍用另一个数组数组记录
然后再顺着输出
好麻烦的样子
现在想一想写一个递归就好了Orz
然后让我改一改
注释掉原来的就好咯~
果然cin慢了几百ms
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int INF=0x7ffffff;
int w[1002][1002];
int d[1002];
int pre[1002];
int fa[1002]={-1};
int v[1002]={0};
int n;
queue<int> q;

void print(int x)//先递归后输出
{
	if(fa[x]!=-1)
		print(fa[x]);
	cout<<x<<" ";
}

void SPFA()
{
	fa[1]=-1;
	d[1]=0;
	v[1]=1;
	q.push(1);

	while(!q.empty())
	{
		int x=q.front();
		q.pop();

		for(int i=1;i<=n;i++)
			if(d[x]+w[x][i]<d[i])
			{
				d[i]=d[x]+w[x][i];
				fa[i]=x;
				if(!v[i])
					q.push(i),v[i]=1;
			}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		d[i]=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>w[i][j];
			if(w[i][j]==0)
				w[i][j]=INF;
		}
	SPFA();
	/*
	int l=1;
	for(int i=n;i>0;i=fa[i])
		pre[l++]=i;
	for(int i=l-1;i>=1;i--)
		cout<<pre[i]<<" ";
		*/
	print(n);
	cout<<endl;
	cout<<d[n];
	return 0;
}
