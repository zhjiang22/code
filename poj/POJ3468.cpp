#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define LL long long
const int MAXN=100005;
struct Node
{
	LL sum,addv;
}tree[MAXN<<2];
int n,m;

void build_tree(int o,int l,int r)
{
	if(l==r)
	{
		int x;	scanf("%d",&x);
		tree[o].sum=x;
		return;
	}
	int mid=(l+r)>>1;
	build_tree(o<<1,l,mid);
	build_tree(o<<1|1,mid+1,r);
	tree[o].sum=tree[o<<1].sum+tree[o<<1|1].sum;
}

void push_down(int o,int l,int r)
{
	if(!tree[o].addv)
		return;
	int lc=(o<<1),rc=(o<<1|1);
	int mid=(l+r)>>1;
	tree[lc].addv+=tree[o].addv;
	tree[rc].addv+=tree[o].addv;
	tree[lc].sum+=tree[o].addv*(mid-l+1);
	tree[rc].sum+=tree[o].addv*(r-mid);
	tree[o].addv=0;
}

LL query(int o,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
		return tree[o].sum;
	push_down(o,l,r);
	LL ans=0;
	int mid=(l+r)>>1;
	if(x<=mid)
		ans+=query(o<<1,l,mid,x,y);
	if(y>mid)
		ans+=query(o<<1|1,mid+1,r,x,y);
	return ans;
}

void change(int o,int l,int r,int x,int y,int p)
{
	if(x<=l&&y>=r)
	{
		tree[o].sum+=(LL)(r-l+1)*p;
		tree[o].addv+=p;
		return;
	}
	push_down(o,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)
		change(o<<1,l,mid,x,y,p);
	if(y>mid)
		change(o<<1|1,mid+1,r,x,y,p);
	tree[o].sum=tree[o<<1].sum+tree[o<<1|1].sum;
}

void init()
{
	cin>>n>>m;
	build_tree(1,1,n);
}

void work()
{
	char k;
	int x,y,z;
	while(m--)
	{
		cin>>k;
		if(k=='Q')
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(1,1,n,x,y));
		}
		else
		{
			scanf("%d%d%d",&x,&y,&z);
			change(1,1,n,x,y,z);
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}
     