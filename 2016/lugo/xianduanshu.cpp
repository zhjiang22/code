#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=200005;
struct node
{
	int l,r,sum;
	int tag;
}tree[MAXN<<2];
int a[MAXN];
int n,q;

inline void push_down(int o)
{
	int &w=tree[o].tag;
	tree[o<<1].tag+=w;
	tree[o<<1|1].tag+=w;
	tree[o<<1].sum+=w;
	tree[o<<1|1].sum+=w;
	w=0;
}

void build_tree(int o,int l,int r)
{
	tree[o].l=l;	tree[o].r=r;
	if(l==r)
	{
		tree[o].sum=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build_tree(o<<1,l,mid);
	build_tree(o<<1|1,mid+1,r);
	tree[o].sum=tree[o<<1].sum+tree[o<<1|1].sum;
}

void update(int o,int l,int r,int c)
{
	int x=tree[o].l;	int y=tree[o].r;
	if(x==l&&y==r)
	{
		tree[o].tag+=c;
		tree[o].sum+=c;
		return;
	}
	if(tree[o].tag)
		push_down(o);
	int mid=(x+y)>>1;
	if(r<=mid)
		update(o<<1,l,r,c);
	else	if(l>mid)
		update(o<<1|1,l,r,c);
	else
		update(o<<1,l,mid,c),update(o<<1|1,mid+1,r,c);
	tree[o].sum=tree[o<<1].sum+tree[o<<1|1].sum;
}

int query(int o,int l,int r)
{
	int x=tree[o].l;	int y=tree[o].r;
	if(l==x&&r==y)
	{
		return tree[o].sum;
	}
	if(tree[o].tag)
		push_down(o);
	int mid=(x+y)>>1;
	if(r<=mid)
		return query(o<<1,l,r);
	else	if(l>mid)
		return query(o<<1|1,l,r);
	else
		return query(o<<1,l,mid)+query(o<<1|1,mid+1,r);
}

void work()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build_tree(1,1,n);
	cin>>q;
	int x,y,k,v;
	for(int i=1;i<=q;i++)
	{
		cin>>k;
		if(k==1)
		{
			cin>>x>>y>>v;
			update(1,x,y,v);
		}
		else
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<endl;
		}
	}
}

int main()
{
	work();
}
     