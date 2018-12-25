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

const int MAXN=100005;
int sum[MAXN];
int add[MAXN];
int a[MAXN];
int n,m;

void build_tree(int o,int l,int r)
{
	if(l==r)
	{
		sum[o]=a[l];
		return;
	}
	int m=l+(r-l)/2;
	int lc=o<<1,rc=o<<1|1;
	build_tree(lc,l,m);
	build_tree(rc,m+1,r);
	sum[o]=sum[lc]+sum[rc];
}

void init()
{
	memset(add,0,sizeof(add));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
		read(a[i]);
	read(m);
	build_tree(1,1,n);
}

void maintain(int o,int l,int r)
{
	int lc=o<<1,rc=o<<1|1;
	sum[o]=0;
	if(r>l)
		sum[o]=sum[lc]+sum[rc];
	sum[o]+=add[o]*(r-l+1);
}

int lx,ry,w;

void update(int o,int l,int r)
{
	int lc=o<<1;	int rc=o<<1|1;
	if(lx<=l&&ry>=r)
		add[o]+=w;
	else
	{
		int m=l+(r-l)/2;
		if(lx<=m)	update(lc,l,m);
		if(ry>m)	update(rc,m+1,r);
	}
	maintain(o,l,r);
}

int _sum;

void query(int o,int l,int r,int addv)
{
	if(lx<=l&&ry>=r)
		_sum+=sum[o]+addv*(r-l+1);
	else
	{
		int m=l+(r-l)/2;
		int lc=o<<1;	int rc=o<<1|1;
		if(lx<=m)	query(lc,l,m,addv+add[o]);
		if(ry>m)	query(rc,m+1,r,addv+add[o]);
	}
}

void work()
{
	int k;
	lx=1,ry=3;
	query(1,1,n,0);
	cout<<_sum<<endl;
	for(int i=1;i<=m;i++)
	{
		read(k);
		if(k==0)
		{
			read(lx);	read(ry);
			_sum=0;
			query(1,1,n,0);
			out(_sum);
		}
		else
		{
			read(lx);	read(ry);	read(w);
			update(1,1,n);
		}
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		init();
		work();
	}
	return 0;
}
     