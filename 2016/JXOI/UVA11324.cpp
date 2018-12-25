#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

char rd;	int pn;
template<typename Type>
inline void read(Type& v)
{
	pn=1;
	while((rd=getchar())<'0'||rd>'9')
		if(rd=='-')
			pn=-1;
	v=rd-'0';
	while((rd=getchar())>='0'&&rd<='9')
		v=v*10+rd-'0';
	v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1)
{
	if(v==0)
		putchar(48);
	else  
    {
    	if(v<0)
    	{
    		putchar('-');
    		v=-v;
    	}
    	int len=0,dg[20];  
    	while(v>0)
    	{
    		dg[++len]=v%10;
    		v/=10;
    	}  
    	for(int i=len;i>=1;i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}

const int MAXN=1005;
const int MAXM=50005;
struct Edge
{
	int to,next;
}e[MAXM<<1];
int fisrt[MAXN];
int n,m,tot;
int t;

inline void Add_Edge(int x,int y)
{
	e[++tot].to=y;	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	memset(fisrt,-1,sizeof(fisrt));	tot=0;
	int x,y;
	read(n);	read(m);
	for(int i=1;i<=m;i++)
	{
		read(x);	read(y);
		Add_Edge(x,y);
	}
}

int pre[MAXN],low[MAXN];
int sccno[MAXN];
int sccbig[MAXN];
vector<int> scc[MAXN];
stack<int> s;
int clock_cnt,scc_cnt;

void dfs(int& u)
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
	if(pre[u]==low[u])
	{
		scc_cnt++;
		int x=-1;
		for(;;)
		{
			x=s.top();	s.pop();	sccbig[scc_cnt]++;
			sccno[x]=scc_cnt;	scc[scc_cnt].push_back(x);
			if(u==x)
				break;
		}
	}
}

void find_scc()
{
	memset(pre,0,sizeof(pre));
	memset(low,0,sizeof(low));
	memset(sccno,0,sizeof(sccno));
	memset(sccbig,0,sizeof(sccbig));
	for(int i=1;i<=n;i++)
		scc[i].clear();
	while(!s.empty())
		s.pop();
	clock_cnt=scc_cnt=0;
	for(int i=1;i<=n;i++)
		if(!pre[i])
			dfs(i);
}

int g[MAXN][MAXN];
int f[MAXN];

void getg()
{
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
		for(int j=fisrt[i];j!=-1;j=e[j].next)
		{
			int& v=e[j].to;
			g[sccno[i]][sccno[v]]=1;
		}
	memset(f,-1,sizeof(f));
}

int dp_dfs(int u)
{
	if(f[u]!=-1)
		return f[u];
	f[u]=sccbig[u];
	for(int i=1;i<=scc_cnt;i++)
		if(u!=i&&g[u][i])
			f[u]=max(f[u],dp_dfs(i)+sccbig[u]);
	return f[u];
}

void dp()
{
	int ans=0;
	for(int i=1;i<=scc_cnt;i++)
		ans=max(ans,dp_dfs(i));
	out(ans);
}

int main()
{
	read(t);
	while(t--)
	{
		init();
		find_scc();
		getg();
		dp();
	}
	return 0;
}
     