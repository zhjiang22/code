/*
好二分图~
看到一个经典无敌的题解~
直接搬上来咯~感谢>3<
来源
Topcoder
————————————我是分割线————————————————————
二分图问题。
看到这道题我们先会想到贪心，就是那个骑士被踩的最多，就先拿哪个。
但是，提交后就只过了5个点，  其实这种贪心策略是不对的
特殊情况
当图G是以最大度数为偶数的点对称的奇阶图时，这种策略就是不对的....
那么要怎么做呢..
我们可以将各个骑士看成点，然后将互相攻击的骑士连边，那么求拿走多少也就是求这个图最小点的覆盖
求一般图的最小点的覆盖时无法在多项式时间里解决的.....
那要怎么办呢  
我们知道二分图的最大匹配就是最小点的覆盖，那我们看看这个图是不是二分图。
这个图就是二分图
证明：
将棋盘黑白二染色，即将A1染成黑色，然后与A1相邻的格子染成白色，然后与白色格子相邻的再染成黑色，依次类推。那么可以发现，两个发生冲突的骑士所在的格子一定是一黑一白。那么，将白色格子的骑士对应的点设为无向图的X部，黑色对应到Y部，那么边就只存在于两部分的点之间。得证。
所以将x部的点向y部的点连边，得到一张二分图，那么求这个二分图的最大匹配就是结果。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=50;
const int MAXM=MAXN*MAXN;
struct Edge
{
	int to,next;
}e[MAXM<<1];
struct point
{
	int x,y;
}a[MAXM];
int fisrt[MAXM];
int vis[MAXN][MAXN];
int zx[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int v[MAXM],Link[MAXM];
int n,m,tot;

inline void Add_Edge(int& x,int& y)
{
	e[++tot].to=y;	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void doit(int& i)
{
	string c;
	cin>>c;	int la=c.length();
	a[i].x=c[0]-'A'+1;
	for(int j=1;j<la;j++)
		a[i].y=a[i].y*10+c[j]-'0';
	vis[a[i].x][a[i].y]=i;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		doit(i);
}

void getG()
{
	int newx,newy;
	for(int i=1;i<=m;i++)
		for(int j=0;j<8;j++)
		{
			newx=a[i].x+zx[j][0];	newy=a[i].y+zx[j][1];
			if(newx<1||newx>n||newy<1||newy>n)
				continue;
			if(vis[newx][newy])
				Add_Edge(i,vis[newx][newy]);
		}
}

bool dfs(int& x)
{
	for(int i=fisrt[x];i!=-1;i=e[i].next)
	{
		int& to=e[i].to;
		if(!v[to])
		{
			v[to]=1;
			if(!Link[to]||dfs(Link[to]))
			{
				Link[to]=x;
				return 1;
			}
		}
	}
	return 0;
}

void Hungary()
{
	int ans=0;
	for(int i=1;i<=m;i++)
		if((a[i].x+a[i].y)&1)
		{
			memset(v,0,sizeof(v));
			if(dfs(i))
				ans++;
		}
	cout<<ans<<endl;
}

int main()
{
	init();
	getG();
	Hungary();
}
     