/*
水题啊
可以用SPFA预处理一下
但是其实直接裸的dfs也是可以的
注意这里是边不能重复而非顶点不能重复
故我们可以用一个vis[x][y]表示x到y的这条路径是否走过即可
注意判断一条边是否走过的时候
vis[x][y]和vis[y][x]都要设为1
傻了一下在这里犯错弄了半天
真是弱的要死
然后dfs用3个形参now,havet,havev
表示当前走到了now点，已经用了havet的时间，花费了havev
然后递归边界就是到达了n点
尝试更新答案就好
坑比较多要细心
邻接矩阵也可以轻松过
但是我闲的无聊写了个邻接表OTZ
窝好弱啊
直接0ms过了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
struct Edge
{
	int to,next,t,v;
	Edge()
	{
		to=next=-1;
		t=v=0;
	}
}e[MAXN<<2];
int g[MAXN][MAXN];
int vis[MAXN][MAXN];
int first[MAXN];
int n,m,t,v;
int tot;
int anst,ansv;

inline void Add_Edge(int x,int y,int t,int v)
{
	tot++;
	e[tot].to=y;	e[tot].t=t;	   e[tot].v=v;
	e[tot].next=first[x];	first[x]=tot;
}

void init()
{
	int x,y,t1,v1;
	memset(first,-1,sizeof(first));
	cin>>n>>m>>t>>v;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>t1>>v1;
		Add_Edge(x,y,t1,v1);
		Add_Edge(y,x,t1,v1);
	}
}

void dfs(int now,int havet,int havev)
{
	if(now==n)
	{
		if(havev>ansv||(havev==ansv&&havet<anst))
			if(havet<=t)
			{
				ansv=havev;
				anst=havet;
			}
		return;
	}
	for(int i=first[now];i!=-1;i=e[i].next)
	{
		int y=e[i].to;	int v1=e[i].v;	int t1=e[i].t;
		if(t1+havet<=t&&havev+v1<=v)
			if(!vis[now][y])
			{
				vis[now][y]=vis[y][now]=1;
				dfs(y,havet+t1,havev+v1);
				vis[now][y]=vis[y][now]=0;
			}
	}
}

int main()
{
	init();
	dfs(1,0,0);
	cout<<anst<<" "<<v-ansv<<endl;
	return 0;
}
     