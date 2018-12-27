/*
这个题目描述窝给满分...
醉了醉了~好长啊看吐血了
但是实际很简单的
首先说明一下每个点的时限其实是2s的(其实这个做法开了map都照样1ms稳过)
我们需要将每个IP地址转换成一个正整数方便解题
那么我们可以用一个hash或者map来解决一下~
映射好之后我们还需要记录一下每个结点对应的ip值便于输出
然后注意读入的时候可能多次读入一个ip
那么还要累加起来
然后读入边了
当且仅当边的两个端点在上面出现过
窝们连一条无向边	权值就是两个顶点的权值之和
那么我们就可以枚举所有的n点
跑一边SPFA
(我们看到输入的n和m的最大范围相等~而且会有无效边，那么稀疏图SPFA更优而且好写)
然后再记录一下这个点到所有点的最短路径长度之和
然后累加	这里如果发现某个点不可达那么可以直接返回-INF
因为要求的点必然到所有点是要连通的
然后排个序就好啦~
细节还是要注意一下的	SPFA写了这么多次还是忘记少写了个in[u]=0然后WA了一发...
好弱啊~NOIP求rp++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

const int MAXN=100005;
const int INF=(1<<30)-1;
struct Edge
{
	int to,w,next;
}e[MAXN<<1];
int fisrt[MAXN];//Edge
struct node
{
	int cost,idx;
	bool operator < (const node&b)const
	{
		return cost>b.cost;
	}
}sco[MAXN];
int n,m,tot;
map<string,int> Hash;
int d[MAXN],in[MAXN];//SPFA
string ip[MAXN];
int w[MAXN];

inline void Add_Edge(int x,int y,int w)
{
	e[++tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	int k,tmp;
	string a,b;
	memset(fisrt,-1,sizeof(fisrt));
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a>>tmp;
		if(Hash[a])
			w[Hash[a]]+=tmp;
		else
		{
			Hash[a]=++n;
			ip[n]=a;
			w[Hash[a]]=tmp;
		}
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a>>b;
		if(Hash[a]&&Hash[b])
			Add_Edge(Hash[a],Hash[b],w[Hash[a]]+w[Hash[b]]),
			Add_Edge(Hash[b],Hash[a],w[Hash[a]]+w[Hash[b]]);
	}
}

int SPFA(int s)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
		d[i]=INF;
	memset(in,0,sizeof(in));
	d[s]=0;	in[s]=1; q.push(s);	
	while(!q.empty())
	{
		int u=q.front();	q.pop();	in[u]=0;
		for(int i=fisrt[u];i!=-1;i=e[i].next)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!in[v])
					in[v]=1,q.push(v);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]==INF)
			return -INF;
		else
			ans+=d[i];
	}
	return ans;
}

void out()
{
	cout<<"The ONLY truth is: it is you, ";
	if(sco[1].cost==-INF||sco[1].cost==sco[2].cost)
		cout<<"222.240.168.135"<<endl;
	else
		cout<<ip[sco[1].idx]<<endl;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		sco[i].cost=SPFA(i);
		sco[i].idx=i;
	}
	sort(sco+1,sco+n+1);
	out();
	return 0;
}
     