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
int a[MAXN];
int maxw[MAXN<<2],addo[MAXN<<2];
int ql,qr;
int v;
int n,m;

void init()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	read(m);
}

inline void maintain(int& o,int& l,int& r)
{
	if(l<r)
	{
		int x=maxw[o<<1]+addo[o<<1];
		int y=maxw[o<<1|1]+addo[o<<1|1];
		maxw[o]=max(x,y);
	}
}

inline void pushdown(int o,int l,int r)
{
	if(addo[o])
	{
		if(l==r)
		{
			maxw[o]+=addo[o];
			addo[o]=0;
		}
		else
		{
			addo[o<<1]+=addo[o];
			addo[o<<1|1]+=addo[o];
			maxw[o]+=addo[o];
			addo[o]=0;
		}
	}
}

void build_tree(int o,int l,int r)
{
	if(l==r)
	{
		maxw[o]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build_tree(o<<1,l,mid);
	build_tree(o<<1|1,mid+1,r);
	maintain(o,l,r);
}

void update(int o,int l,int r)
{
	if(ql<=l&&qr>=r)
		addo[o]+=v;
	else
	{
		int mid=(l+r)>>1;
		if(ql<=mid)
			update(o<<1,l,mid);
		if(qr>mid)
			update(o<<1|1,mid+1,r);
		maintain(o,l,r);
	}
}

int ans;

void query(int o,int l,int r)
{
	pushdown(o,l,r);
	if(ql<=l&&qr>=r)
		ans=max(ans,maxw[o]);
	else
	{
		int mid=(l+r)>>1;
		if(ql<=mid)
			query(o<<1,l,mid);
		if(qr>mid)
			query(o<<1|1,mid+1,r);
	}
}

void question()
{
	int k;
	for(int i=1;i<=m;i++)
	{
		read(k);	read(ql);	read(qr);
		if(k==1)
		{
			read(v);
			update(1,1,n);
		}
		else
		{
			ans=-(1<<29);
			query(1,1,n);
			out(ans);
		}
	}
}

int main()
{
	init();
	build_tree(1,1,n);
	question();
}