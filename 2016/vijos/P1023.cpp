/*
问一下这题和P1022有何区别
直接把题解搬过来了...OTZ
这题很明显是一个有向图模型~
同时是要求强连通分量的个数~！
因为n很小	所以完全可以用Floyd预处理
然后统计连通块
用并查集也很方便~
当然也可以写个标准一点的Tarjan统计SCC数量~
这里窝两个都写了一下
*/
/*
方法1:
Floyd判断连通性，最后注意统计连通块的方法：v数组
不再多说~
细节看代码就好
*/
/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

bool a[203][203];
bool v[203];
int n;
int m;
int tot;

void init()
{
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		while(scanf("%d",&x)==1&x)
			a[i][x]=1;
	}
}

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[i][k]&&a[k][j])
					a[i][j]=1;
}

void work()
{
	for(int i=1;i<=n;i++)
		if(!v[i])
		{
			for(int j=1;j<=n;j++)
				if(a[i][j]&&a[j][i]&&!v[j])
					v[j]=1;
			tot++;
			v[i]=1;
		}
	cout<<tot<<endl;
}

int main()
{
	init();
	Floyd();
	work();
	return 0;
}
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int MAXN=205;
const int MAXM=40005;
struct Edge
{
	int to,next;
}e[MAXM];
int fisrt[MAXN];//Edges
int clock_cnt,scc_cnt;
int pre[MAXN],low[MAXN];
int sccno[MAXN];
stack<int> s;
int n,tot;

inline void Add_Edge(int& x,int& y)
{
	e[++tot].to=y;	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	int v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		while(scanf("%d",&v)==1&&v)
			Add_Edge(i,v);
	}
}

void dfs(int u)
{
	pre[u]=low[u]=++clock_cnt;
	s.push(u);
	for(int i=fisrt[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(!pre[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else	if(!sccno[v])
			low[u]=min(low[u],pre[v]);
	}
	if(low[u]==pre[u])
	{
		scc_cnt++;
		int x=0;
		for(;;)
		{
			x=s.top();	s.pop();
			sccno[x]=scc_cnt;
			if(x==u)
				break;
		}
	}
}

void Tarjan()
{
	for(int i=1;i<=n;i++)
		if(!pre[i])
			dfs(i);
	cout<<scc_cnt<<endl;
}

int main()
{
	init();
	Tarjan();
}
