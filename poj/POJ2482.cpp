#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define LL long long
const int MAXN=20005;
struct Node
{
	LL maxd,addv;
}tree[MAXN<<2];
struct P
{
	LL x,y1,y2,c;//此处也需要开long long
	bool operator<(const P& p)const
	{
		return x<p.x;
	}
}a[MAXN];
LL Hash[MAXN];
LL yy[MAXN];
int tot,cnt;
LL w,h;
int n;

int find_idx(LL x)
{
	return lower_bound(Hash+1,Hash+cnt+1,x)-Hash;
}

void init()
{
	tot=cnt=0;
	LL x,y,c;
	int yk=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&c);
		a[++tot]=(P){x,y,y+h-1,c};
		a[++tot]=(P){x+w,y,y+h-1,-c};
		yy[++yk]=y;	yy[++yk]=y+h-1;
	}
	sort(yy+1,yy+yk+1);
	for(int i=1;i<=yk;i++)
		if(i==1||yy[i]!=yy[i-1])
			Hash[++cnt]=yy[i];
	sort(a+1,a+tot+1);
}

void build_tree(int o,int l,int r)
{
	tree[o].maxd=tree[o].addv=0;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build_tree(o<<1,l,mid);
	build_tree(o<<1|1,mid+1,r);
}

void push_down(int o,int l,int r)
{
	if(!tree[o].addv)
		return;
	int lc=(o<<1),rc=(o<<1|1);
	tree[lc].addv+=tree[o].addv;
	tree[rc].addv+=tree[o].addv;
	tree[lc].maxd+=tree[o].addv;
	tree[rc].maxd+=tree[o].addv;
	tree[o].addv=0;
}

void add(int o,int l,int r,int x,int y,int c)
{
	if(x<=l&&y>=r)
	{
		tree[o].addv+=c;
		tree[o].maxd+=c;
		return;
	}
	push_down(o,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)
		add(o<<1,l,mid,x,y,c);
	if(y>mid)
		add(o<<1|1,mid+1,r,x,y,c);
	tree[o].maxd=max(tree[o<<1].maxd,tree[o<<1|1].maxd);
}

void work()
{
	LL ans=0;
	build_tree(1,1,cnt);
	for(int i=1;i<=tot;i++)
	{
		LL y1=find_idx(a[i].y1);	LL y2=find_idx(a[i].y2);
		add(1,1,cnt,y1,y2,a[i].c);
		ans=max(ans,tree[1].maxd);
	}
	printf("%lld\n",ans);
}

int main()
{
	while(scanf("%d%lld%lld",&n,&w,&h)==3&&n&&w&&h)
	{
		init();
		work();
	}
	return 0;
}
     