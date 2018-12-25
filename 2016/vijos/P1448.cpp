/*
括号大法好QWQ
虽然这道题写树状数组代码少了一半
但还是写了线段树练习OTZ
我们都知道的
使用线段树	根本目的还是维护一个信息
而这里很明显如果直接暴力打线段树直接gg
然后就直接用括号大法好
因为图不能画 发个博客出来QAQ
http://www.cnblogs.com/shadowland/p/5870395.html
其实很好理解
我们对于一个操作种树[L,R]
我们就在L处放下一个 ( R处放下一个 )
这样其实我们就很容易会发现
线段树结点我们只需要用一个liml和limr来储存这个结点的(和)的个数
然后放下一个(或)就可以很容易直接维护了
那么我们怎么来得到查询的答案呢？
查询某个区间树的种类,比如区间[4,10]，
只需统计10之前（包括10）有多少个(，统计4之前有多少个)，（不包括3）
然后差值就是答案
简单的说，就是更新区间[a,b]时，点a记录左括号数，点b记录右括号数，
查询区间[a,b]时，即为b之前（包括b）的左括号数-a之前的右括号数
其实这样子很好理解了建议手画一遍
这里我们要注意了
如果是查询区间[1,x]	因为我们要查询的是[1,l-1]的)个数
这样区间就是[1,0]然后就爆炸了
所以这样要特判断一下
当且仅当l!=1时我们才去查询左端点前的右括号个数
不然就是0我们不查也是一样的OTZ
这样一转换就变成了简单的单点修改问题咯	ORZ
然后就直接乱搞了
PS:(一个月后的窝跑来写树状数组啦~)
果然点修改这种能BIT绝不线段树	线段树有毒~
100+降到了30+OTZ而且常数还更小~~~
BIT真女友！
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=50010;
int c1[MAXN],c2[MAXN];
int n,m;

inline int lowbit(int x){return x&(-x);}

void add(int c[],int x,int d)
{
	while(x<=n)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int c[],int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

int main()
{
	cin>>n>>m;
	int l,r,k;
	for(int i=1;i<=m;i++)
	{
		cin>>k>>l>>r;
		if(k==1)
			add(c1,l,1),add(c2,r,1);
		else
			cout<<sum(c1,r)-sum(c2,l-1)<<endl;
	}
	return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=50010;
struct node
{
	int l,r;
	long long liml,limr;
}tree[MAXN<<2];
int n,m;

void build_tree(int l,int r,int o)
{
	tree[o].l=l;
	tree[o].r=r;
	if(l==r)
		return;
	long long mid=(l+r)>>1;
	build_tree(l,mid,o<<1);
	build_tree(mid+1,r,o<<1|1);
}

void update_left(int w,int o)
{
	if(w==tree[o].l&&w==tree[o].r)
		tree[o].liml++;
	else
	{
		long long mid=(tree[o].l+tree[o].r)>>1;
		if(w>mid)
			update_left(w,o<<1|1);
		else
			update_left(w,o<<1);
		tree[o].liml=tree[o<<1].liml+tree[o<<1|1].liml;
	}
}

void update_right(int w,int o)
{
	if(w==tree[o].l&&w==tree[o].r)
		tree[o].limr++;
	else
	{
		long long mid=(tree[o].l+tree[o].r)>>1;
		if(w>mid)
			update_right(w,o<<1|1);
		else
			update_right(w,o<<1);
		tree[o].limr=tree[o<<1].limr+tree[o<<1|1].limr;
	}
}

long long query_left(int s,int t,int o)
{
	if(s<=tree[o].l&&t>=tree[o].r)
		return tree[o].liml;
	else
	{
		long long mid=(tree[o].l+tree[o].r)>>1;
		if(s>mid)
			return query_left(s,t,o<<1|1);
		else	if(t<=mid)
			return query_left(s,t,o<<1);
		else
			return query_left(s,t,o<<1|1)+query_left(s,t,o<<1);
	}
}

long long query_right(int s,int t,int o)
{
	if(s<=tree[o].l&&t>=tree[o].r)
		return tree[o].limr;
	else
	{
		long long mid=(tree[o].l+tree[o].r)>>1;
		if(s>mid)
			return query_right(s,t,o<<1|1);
		else	if(t<=mid)
			return query_right(s,t,o<<1);
		else
			return query_right(s,t,o<<1|1)+query_right(s,t,o<<1);
	}
}

int main()
{
	int l,r,k;
	cin>>n>>m;
	build_tree(1,n,1);
	while(m--)
	{
		cin>>k>>l>>r;
		if(k==1)
		{
			update_left(l,1);
			update_right(r,1);
		}
		else
		{
			if(l!=1)
				cout<<query_left(1,r,1)-query_right(1,l-1,1)<<endl;
			else
				cout<<query_left(1,r,1)<<endl;
		}
	}
	return 0;
}
*/     