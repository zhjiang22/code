#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define LL long long
const int MAXN=100005;
struct node
{
	int l,r;
	LL sum;
}tree[MAXN<<2];
LL add[MAXN];
LL a[MAXN];
int n,q;
int v;
LL _sum;

void init()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

void maintain(int& o)
{
	int& l=tree[o].l;	int& r=tree[o].r;
	if(r>l)
		tree[o].sum=tree[o<<1].sum+tree[o<<1|1].sum;
	tree[o].sum+=add[o]*(r-l+1);
} 

void build_tree(int o,int x,int y)
{
	tree[o].l=x;	tree[o].r=y;
	if(x==y)
	{
		tree[o].sum=a[x];
		return;
	}
	int lc=o<<1;	int rc=o<<1|1;
	int mid=(x+y)>>1;
	build_tree(lc,x,mid);
	build_tree(rc,mid+1,y);
	tree[o].sum=tree[lc].sum+tree[rc].sum;
}

void update(int o,int x,int y)
{
	int& l=tree[o].l;	int& r=tree[o].r;
	if(x<=l&&y>=r)
		add[o]+=v;
	else
	{
		int lc=o<<1;	int rc=o<<1|1;
		int mid=(l+r)>>1;
		if(x<=mid)
			update(lc,x,y);
		if(y>mid)
			update(rc,x,y);
	}
	maintain(o);
}

void query(int o,int x,int y,int _add)
{
	int& l=tree[o].l;	int& r=tree[o].r;
	if(l>=x&&r<=y)
		_sum+=tree[o].sum+_add*(r-l+1);
	else
	{
		int lc=o<<1;	int rc=o<<1|1;
		int mid=(l+r)>>1;
		if(x<=mid)
			query(lc,x,y,_add+add[o]);
		if(y>mid)
			query(rc,x,y,_add+add[o]);
	}
}

void question()
{
	char ch;	int a,b;
	for(int i=1;i<=q;i++)
	{
		cin>>ch;
		if(ch=='Q')
		{
			scanf("%d%d",&a,&b);
			_sum=0;	query(1,a,b,0);
			printf("%d\n",_sum);
		}
		else
		{
			scanf("%d%d%d",&a,&b,&v);
			update(1,a,b);
		}
	}
}

int main()
{
	init();
	build_tree(1,1,n);
	question();
}
     