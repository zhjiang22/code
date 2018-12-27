/*
差分约束
看2006国家集训队论文冯威的差分约束
上面有
我也说不清楚啊
我好弱
http://blog.csdn.net/li412302070/article/details/12761499
http://www.cnblogs.com/fraud/p/4304350.html
http://wenku.baidu.com/view/685fbe1e650e52ea5518981a.html?from=related
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=50100;
const int INF=(1<<30)-1;
struct Edge
{
	int to,nxt,w;
	Edge()
	{
		to=nxt=-1;
	}
}e[MAXN*3];//至少3倍
int d[MAXN];
int fisrt[MAXN];
bool in[MAXN];
int n,m,tot;
queue<int> q;

void inline Add_Edge(int x,int y,int w)
{
	tot++;
	e[tot].to=y;	e[tot].w=w;
	e[tot].nxt=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(-1));
	int x,y,w;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>w;
		x++;	y++;//若a=0,d[a-1]会越界,所以就把0-50000改成了1-50001
		m=max(m,x);	m=max(m,y);
		Add_Edge(x-1,y,w);//连一条权值为-C的边也可以反过来从x连到y，然后求最长路
	}
	for(int i=1;i<=m+1;i++)
		Add_Edge(i,i-1,-1),Add_Edge(i-1,i,0);
}

void SPFA()
{
	for(int i=0;i<=m+1;i++)
		d[i]=-INF;
	d[0]=0;	q.push(0);
	while(!q.empty())
	{
		int x=q.front();	q.pop();
		in[x]=0;
		for(int i=fisrt[x];i!=-1;i=e[i].nxt)
		{
			int u=e[i].to;	int w=e[i].w;
			if(d[u]<d[x]+w)
			{
				d[u]=d[x]+w;
				if(!in[u])
					q.push(u),in[u]=1;
			}
		}
	}
	cout<<d[m+1]<<endl;
}

int main()
{
	init();
	SPFA();
	return 0;
}
     