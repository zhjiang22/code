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

const int MAXN=2000005;
int max_sub[MAXN];
int max_prefix[MAXN];
int max_suffix[MAXN];
int a[MAXN];
int n,m;

void init()
{
	if(scanf("%d%d",&n,&m)!=2)
		exit(0);
	for(int i=1;i<=n;i++)
		read(a[i]);
}

void build_tree(int o,int l,int r)
{
	if(l==r)
	{
		max_sub[o]=max_suffix[o]=max_prefix[o]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build_tree(o<<1,l,mid);
	build_tree(o<<1|1,mid+1,r);
	
	
}

void init()
{
	
}

int main()
{
	while(1)
	{
		init();
		build_tree(1,1,n);
	}
}
     