#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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

const int MAXN=50005;
const int MAXQ=10005;
const int MAXLOG=21;
struct Edge
{
	int to,next;
}e[MAXN<<1];
int first[MAXN];
int n,q,tot;
int T,Case;

inline void Add_Edge(int& x,int& y)
{
	e[++tot].to=y;	e[tot].next=first[x];	first[x]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));	tot=0;
	read(n);
	int a,b;
	for(int i=1;i<n;i++)
	{
		read(a);	read(b);
		Add_Edge(a,b);	Add_Edge(b,a);
	}
}

int anc[MAXN][MAXLOG];
int fa[MAXN],L[MAXN];

void dfs(int u,int father)
{
	fa[u]=father;
	for(int i=first[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(v!=father)
		{
			L[v]=L[u]+1;
			dfs(v,u);
		}
	}
}

void press()
{
	memset(anc,-1,sizeof(anc));
	memset(fa,-1,sizeof(fa));
	memset(L,0,sizeof(L));
	dfs(0,-1);
	for(int i=0;i<n;i++)
		anc[i][0]=fa[i];
	for(int j=0;(1<<j)<n;j++)
		for(int i=0;i<n;i++)
			if(anc[i][j-1]!=-1)
			{
				int& a=anc[i][j-1];
				anc[i][j]=anc[a][j-1];
			}
}

int LCA(int p,int q)
{
	if(L[p]>L[q])
		swap(p,q);
	int maxlog=0;
	for(;(1<<maxlog)<=L[q];maxlog++);	maxlog--;
	for(int j=maxlog;j>=0;j--)
		if(L[q]-L[p]>=(1<<j))
			q=anc[q][j];
	if(p==q)
		return p;
	else
		return fa[p];
}

int w[MAXN];

void question()
{
	for(int i=0;i<n;i++)
		out(fa[i]);
	int a,b,c,p;
	memset(w,0,sizeof(w));
	read(q);
	for(int i=1;i<=q;i++)
	{
		read(a);	read(b);	read(c);
		p=LCA(a,b);
		w[a]+=c;	w[b]+=c;	w[p]-=c;
		if(fa[p]!=-1)
			w[fa[p]]-=c;
	}
}

void dfsmark(int u,int father)
{
	for(int i=first[u];i!=-1;i=e[i].next)
	{
		int& v=e[i].to;
		if(v!=father)
		{
			dfsmark(v,u);
			w[u]+=w[v];
		}
	}
}

void work()
{
	dfsmark(0,-1);
	printf("Case #%d:\n",++Case);
	for(int i=0;i<n;i++)
		out(w[i]);
}

int main()
{
	read(T);
	while(T--)
	{
		init();
		press();
		question();
		work();
	}
	return 0;
}
     