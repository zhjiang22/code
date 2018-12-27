/*
好题~>3<
%%%%%Orz教主
一看到这题	不是裸的最小生成树吗
然后看到60万的数据这样边能达到120万^2之多
本题即为平面图上的MST，特殊的是只有两排点。
普通的MST算法可以拿到40%的分数。但是由于图的特殊性，有以下推论：
1、MST中不会有线段相交,若AD与BC相交，无论AB有不经过AD、BC路径相连还是CD有不经过AD、BC路径，
改连AC，BD会使得生成树权和更小。
2、若有点A(x1,y1),B(x1,y2),C(x2,y3)，且y1<y2<y3，所以这种情况AC是不可能连边。
即一个钝角三角形的最长边必然是不会连的
这样就可以构出一张边数最多为2(m+n)条的新图，使用Kruskal时间复杂度O((n+m)log(n+m))期望得分为70-100。
有效地减少了不必要运算的边，减少了时间复杂度
距离要开long long不然只有60分
好像有dp水法？太弱不会..
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN=600005;
const int MAXM=2000005;
struct Edge
{
	int u,v;
	double w;
	bool operator<(const Edge& b)const
	{
		return w<b.w;
	}
}e[MAXM<<1];
long long a[MAXN],b[MAXN];
int fa[MAXN<<1];
int n,m,tot;
int x1,x2;
double ans;

inline void Add_Edge(int x,int y,double w)
{
	e[++tot].u=x;	e[tot].v=y;		e[tot].w=w;
}

inline int find(int& x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void init()
{
	long long d;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&x1,&x2);
	double dist=(x1-x2)*(x1-x2);
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&d);
		a[i]=a[i-1]+d;
		Add_Edge(i-1,i,(double)d);
	}
	cin>>b[1];
	for(int i=2;i<=m;i++)
	{
		scanf("%lld",&d);
		b[i]=b[i-1]+d;
		Add_Edge(i+n-1,i+n,(double)d);
	}
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		while(cur<m&&b[cur+1]<a[i])
			cur++;
		Add_Edge(i,cur+n,sqrt(dist+(a[i]-b[cur])*(a[i]-b[cur])));
		if(i==n||b[cur+1]<=a[i+1])
			Add_Edge(i,cur+n+1,sqrt(dist+(a[i]-b[cur+1])*(a[i]-b[cur+1])));
	}
	for(int i=1;i<=n+m;i++)
		fa[i]=i;
}

void Kruskal()
{
	sort(e+1,e+tot+1);
	int c=0;
	for(int i=1;i<=tot;i++)
	{
		int& x=e[i].u;	int& y=e[i].v;	double& w=e[i].w;
		int fx=find(x);	int fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			ans+=w;
			c++;
		}
		if(c>=n+m-1)
			break;
	}
	printf("%.2lf\n",ans);
}

int main()
{
	init();
	Kruskal();
}
