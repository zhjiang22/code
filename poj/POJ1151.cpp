#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

const int MAXN=405;
const double eps=1e-9;
struct P
{
	double x,y1,y2;
	int k;
	bool operator<(const P& p)const
	{
		return x<p.x;
	}
}a[MAXN];
struct Node
{
	int cnt;
	double len;
}tree[MAXN<<2];
double _hash[MAXN];
double yy[MAXN];
int c[MAXN];
int Case;
int totyy;
int tot;
int cnt;
int n;

inline double row(int x)
{
	return _hash[x];
}

int get_idx(double x)
{
	return lower_bound(_hash+1,_hash+cnt+1,x)-_hash;
}

void build_tree(int o,int l,int r)
{
	if(l==r)
	{
		tree[o].cnt=0;
		return;
	}
	int mid=(l+r)>>1;
	build_tree(o<<1,l,mid);
	build_tree(o<<1|1,mid+1,r);
	tree[o].cnt=0;
}

void init()
{
	tot=cnt=totyy=0;
	double x1,x2,y1,y2;
	memset(c,0,sizeof(c));
	memset(_hash,0,sizeof(_hash));
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		a[++tot]=(P){x1,y1,y2,1};
		a[++tot]=(P){x2,y1,y2,-1};
		yy[++totyy]=y1;	yy[++totyy]=y2;
	}
	sort(yy+1,yy+totyy+1);
	for(int i=1;i<=totyy;i++)
		if(i==1||fabs(yy[i]-yy[i-1])>eps)
			_hash[++cnt]=yy[i];
	sort(a+1,a+tot+1);
	build_tree(1,1,cnt);
}

void update(int o,int l,int r,int x,int y,int k)
{
	if(x<=l&&y>=r)
	{
		tree[o].cnt+=k;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y,k);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,k);
}

void query(int o,int l,int r)
{
	if(tree[o].cnt>0)
	{
		tree[o].len=(row(r+1)-row(l));
		return;
	}
	if(l==r)
	{
		tree[o].len=0;
		return;
	}
	int mid=(l+r)>>1;
	query(o<<1,l,mid);
	query(o<<1|1,mid+1,r);
	tree[o].len=tree[o<<1].len+tree[o<<1|1].len;
}

void work()
{
	double ans=0;
	for(int i=1;i<tot;i++)
	{
		update(1,1,cnt,get_idx(a[i].y1),get_idx(a[i].y2)-1,a[i].k);
		query(1,1,cnt);
		ans+=(a[i+1].x-a[i].x)*tree[1].len;
	}
	printf("Test case #%d\n",++Case);
	printf("Total explored area: %.2f\n",ans);
	printf("\n");
}

int main()
{
	while(scanf("%d",&n)&&n)
	{
		init();
		work();
	}
	return 0;
}
     