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

const int MAXN=1500055;
int max_sub[MAXN];//最大连续和
int max_prefix[MAXN];//最大前缀和
int max_suffix[MAXN];//最大后缀和
int sum[MAXN];
int a[MAXN/3];
int n,m;

void init()
{
	for(int i=1;i<=n;i++)
		read(a[i]);
}

void maintain(int o,int l,int r)
{
	int lc=o<<1;	int rc=o<<1|1;
	max_sub[o]=max_sub[lc]+max_prefix[rc];
	max_prefix[o]=max(max_prefix[lc],sum[lc]+max_prefix[rc]);
	max_sub[o]=max(max_sub[rc],max_sub[lc]+sum[rc]);
	sum[o]=sum[lc]+sum[rc];
	return;
}

void build_tree(int o,int l,int r)
{
	int lc=o<<1,rc=o<<1|1;
	if(lc==rc)
	{
		max_sub[o]=max_suffix[o]=max_prefix[o]=a[i];
		sum[o]=a[i];
		return;
	}
	int mid=l+(r-l)/2;
	build_tree(lc,l,mid);
	build_tree(rc,mid+1,r);
	maintain(o,l,r);
}

int lx,ry;

void work()
{
	build_tree(1,1,n);
	for(int i=1;i<=m;i++)
	{
		read(lx);	read(ry);
		out(query(1,1,n));
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		init();
		work();
	}
	return 0;
}
     