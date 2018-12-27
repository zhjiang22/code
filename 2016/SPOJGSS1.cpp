#include<bits/stdc++.h>
using namespace std;

const int MAXN=60005;
struct Point
{
	int sum,maxd;
	int lmax,rmax;
}tree[MAXN<<2];
int a[MAXN];
int n,q;

void build_tree(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].sum=tree[o].maxd=tree[o].lmax=tree[o].rmax=a[l];
		return;
	}
	int mid=(l+r)>>1;
	int lc=(o<<1),rc=(o<<1|1);
	build_tree(lc,l,mid);
	build_tree(rc,mid+1,r);
	tree[o].sum=tree[lc].sum+tree[rc].sum;
	tree[o].lmax=max(tree[lc].lmax,tree[lc].sum+tree[rc].lmax);
	tree[o].rmax=max(tree[rc].rmax,tree[rc].sum+tree[lc].rmax);
	tree[o].maxd=max(tree[lc].rmax+tree[rc].lmax,max(tree[lc].maxd,tree[rc].maxd));
}

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build_tree(1,1,n);
}

int ans,ret;

void ask(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
	{
		ans=max(ans,tree[o].maxd);
		if(l==x)
			ret=tree[o].rmax;
		else	if(r==y)
		{
			ret+=tree[o].lmax;
			ans=max(ans,ret);
		}
		else
		{
			ans=max(ans,ret+tree[o].lmax);
			if(ret+tree[o].sum>tree[o].rmax)
				ret+=tree[o].sum;
			else
				ret=tree[o].rmax;
			ans=max(ans,ret);				
		}
		return;
	}
	int lc=(o<<1),rc=(o<<1|1);
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(x<=mid)
		ask(lc,l,mid,x,y);
	if(y>mid)
		ask(rc,mid+1,r,x,y);
}

void work()
{
	int q;
	int x,y;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		ans=-(1<<30);
		ret=0;
		ask(1,1,n,x,y);
		printf("%d\n",ans);
	}
}

int main()
{
	init();
	work();
	return 0;
}
     