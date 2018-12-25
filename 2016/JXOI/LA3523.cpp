#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
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
int dg[20];
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
    	int len=0;  
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
const int MAXM=1000005;
struct Edge
{
	int from,to,next;
}e[MAXM];
int first[MAXN];
int kill[MAXN][MAXN];
int n,m,tot;

inline void Add_Edge(int& x,int& y)
{
	e[++tot].from=x;	e[tot].to=y;
	e[tot].next=first[x];	first[x]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	int x,y;
	read(n);	read(m);	tot=0;
	if(n==0&&m==0)
		exit(0);
	for(int i=1;i<=m;i++)
	{
		read(x);	read(y);
		kill[x][y]=kill[y][x]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!kill[i][j])
			{
				Add_Edge(i,j);	Add_Edge(j,i);
			}
}

bool iscut[MAXN];
int pre[MAXN],low[MAXN];
int bccno[MAXN];
int clock_cnt;
int bcc_cnt;
stack<Edge> s;
vector<int> bcc[MAXN];

void dfs(int u,int father)
{
	pre[u]=low[u]=++clock_cnt;
	int child_cnt=0;
	for(int i=first[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(!pre[v])
		{
			s.push(e[i]);	child_cnt++;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=pre[u])
			{
				iscut[u]=true;	bcc_cnt++;
				for(;;)
				{
					Edge c=s.top();	s.pop();
					int& x=c.from;	int& y=c.to;
					if(bccno[x]!=bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x);	bccno[x]=bcc_cnt;
					}
					if(bccno[y]!=bcc_cnt)
					{
						bcc[bcc_cnt].push_back(y);	bccno[y]=bcc_cnt;
					}
					if(x==u&&y==v)
						break;
				}
			}
		}
		else	if(pre[v]<pre[u]&&v!=father)
		{
			s.push(e[i]);
			low[u]=min(low[u],pre[v]);
		}
	}
	if(father<0&&child_cnt==1)
		iscut[u]=0;
}

void find_bcc()
{
	memset(pre,0,sizeof(pre));
	memset(low,0,sizeof(low));
	memset(bccno,0,sizeof(bccno));
	memset(iscut,0,sizeof(iscut));
	while(!s.empty())
		s.pop();
	for(int i=1;i<=n;i++)
		bcc[i].clear();
	for(int i=1;i<=n;i++)
		if(!pre[i])
			dfs(i,-1);
}

int color[MAXN];
bool odd[MAXN];

bool dfs_color(int u,int b)
{
	for(int i=first[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(bccno[v]!=b)	
			continue;
		if(color[v]&&color[v]==color[u])\
			return false;
		if(!color[v])
		{
			color[v]=3-color[u];
			if(!dfs_color(v,b))
				return false;
		}
	}
	return true;
}

void work()
{
	memset(odd,0,sizeof(odd));
	for(int i=1;i<=bcc_cnt;i++)
	{
		memset(color,0,sizeof(color));
		int l=bcc[i].size();
		for(int j=0;j<l;j++)
			bccno[bcc[i][j]]=i;
		int& u=bcc[i][0];
		color[u]=1;
		if(!dfs_color(u,i))
			for(int j=0;j<l;j++)
				odd[bcc[i][j]]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!odd[i])
			ans++;
	out(ans);
}

int main()
{
	for(;;)
	{
		init();
		find_bcc();
		work();
	}
	return 0;
}
     