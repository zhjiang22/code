#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
const int INF=(1<<30)-1;
struct node
{
	int l,r;
	int minw,maxw,sum;
}tree[MAXN<<2];
int a[MAXN];
int n,q;
int _minw,_maxw,_sum;

void init()
{
	scanf("%d",&n);
	scanf("%d",&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

void maintain(int& o)
{
	int lc=o<<1;	int rc=o<<1|1;
	tree[o].maxw=max(tree[lc].maxw,tree[rc].maxw);
	tree[o].minw=min(tree[lc].minw,tree[rc].minw);
	tree[o].sum=tree[lc].sum+tree[rc].sum;
}

void build_tree(int o,int x,int y)
{
	tree[o].l=x;	tree[o].r=y;
	if(x==y)
	{
		tree[o].minw=tree[o].maxw=tree[o].sum=a[x];
		return;
	}
	int mid=(x+y)>>1;
	int lc=o<<1;	int rc=o<<1|1;
	build_tree(lc,x,mid);
	build_tree(rc,mid+1,y);
	maintain(o);
}

void update(int o,int x,int p)
{
	if(tree[o].l==tree[o].r)
	{
		tree[o].minw=tree[o].maxw=tree[o].sum=p;
		return;
	}
	int& l=tree[o].l;	int& r=tree[o].r;
	int mid=(l+r)>>1;
	if(x<=mid)	update(o<<1,x,p);
	else	update(o<<1|1,x,p);
	maintain(o);
}

void query(int o,int L,int R)
{
	int& l=tree[o].l;	int& r=tree[o].r;
	int mid=(l+r)>>1;
	if(l<=L&&r>=R)
	{
		_minw=min(_minw,tree[o].minw);
		_maxw=max(_maxw,tree[o].maxw);
		_sum+=tree[o].sum;
		return;
	}
	if(L<=mid)	query(o<<1,L,R);
	if(r>mid)	query(o<<1|1,L,R);
}

void question()
{
	int k,x,y;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)
			update(1,x,y);
		else
		{
			_minw=INF;	_maxw=0;	_sum=0;
			query(1,x,y);
			printf("%d %d %d\n",_minw,_maxw,_sum);
		}
	}
}

int main()
{
	init();
	build_tree(1,1,n);
	question();
}
     