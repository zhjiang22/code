/*
好题~
开阔思路了	第一次这么有成就感
一看到这题想了几分钟
然后就想到是不是可以一遍SPFA就过
怎么这么水？
然后有点怀疑自己是不是想的太简单了
这道题好像备注的难度系数挺高的
然后看了下题解	发现都是枚举治愈点k+1次SPFA的
感觉这样是不是太麻烦了？
感觉我这样也可以做啊？
然后按我的思路写了一遍，一遍AC
然后速度从600ms提到了60ms
嗯瞬间感觉自己的想法还可以的
说说我的思路吧
因为我们很容易知道
到了一个治愈点就相当于已走距离变为0
那么我们很容易想到的思路是
先判断一下1能不能到n，然后枚举这些1可以走到的治愈点
然后以这个点为起点SPFA一下求个最短路(Dijkstra也可以的但是SPFA更适合稀疏图)
然后我们就可以比较一下最小值就好了
但是我们仔细一想
不管从哪个起点出发	最终到达的都是n点
那么我们为什么不反过来想一下呢？
我们从n点出发到所有的治愈点
然后判断一下哪个的距离最近？
因为这是个无向图所以肯定成立啊
这个正确性很容易证明我就不说了
但是我们还要先判断一下1点能不能到n点
我们就直接判断d[1]是不是INF就可以了
然后就从n点一遍SPFA就解决了
如果可以到达1点那么我们就取所有治愈点的最小距离
注意我们在取完所有的最小值以后一定要记得再和d[1]取个最小值
因为从1点开始也是0的喋血值
但是好像不加这句也能AC
但为了严谨性还是加上咯
嗯涨姿势了Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=5005;
const int MAXNE=55005;
const int INF=(2<<30)-1;
struct Edge
{
	int to,nxt,w;
	Edge()
	{
		to=nxt=-1;	w=0;
	}
}e[MAXNE];
int first[MAXN];
int n,m,k;
int tot;
bool v[MAXN];
bool in[MAXN]; 
int a[MAXN];
int d[MAXN];
int ans=INF;
queue<int> q;

void inline Add_Edge(int u,int v,int w)
{
	tot++;
	e[tot].to=v;
	e[tot].w=w;
	e[tot].nxt=first[u];
	first[u]=tot;
}

void init()
{
	int x,y,w;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		Add_Edge(x,y,w);
		Add_Edge(y,x,w);
	}
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		d[i]=INF;
}


void SPFA(int s)
{
	d[s]=0;
	q.push(s);	in[s]=1;
	while(!q.empty())
	{
		int x=q.front();	q.pop();
		in[x]=0;
		for(int i=first[x];i!=-1;i=e[i].nxt)
		{
			int to=e[i].to;	int w=e[i].w;
			if(d[to]>d[x]+w)
			{
				d[to]=d[x]+w;
				if(!in[to])
				{
					q.push(to);
					in[to]=1;
				}
			}
		}
	}
	if(d[1]==INF)
	{
		printf("Oh no!");
		return;
	}
	else
	{
		for(int i=1;i<=k;i++)
			ans=min(ans,d[a[i]]);
		ans=min(ans,d[1]);
	}
	printf("%d\n",ans);
}

int main()
{
	init();
	SPFA(n);
	return 0;
}
     