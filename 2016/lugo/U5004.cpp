#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=90010;
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

long long q_left(int s,int t,int o)
{
	if(s<=tree[o].l&&t>=tree[o].r)
		return tree[o].liml;
	else
	{
		long long mid=(tree[o].l+tree[o].r)>>1;
		if(s>mid)
			return q_left(s,t,o<<1|1);
		else	if(t<=mid)
			return q_left(s,t,o<<1);
		else
			return q_left(s,t,o<<1|1)+q_left(s,t,o<<1);
	}
}

long long q_r(int s,int t,int o)
{
	if(s<=tree[o].l&&t>=tree[o].r)
		return tree[o].limr;
	else
	{
		long long mid=(tree[o].l+tree[o].r)>>1;
		if(s>mid)
			return q_r(s,t,o<<1|1);
		else	if(t<=mid)
			return q_r(s,t,o<<1);
		else
			return q_r(s,t,o<<1|1)+q_r(s,t,o<<1);
	}
}

void qwq()
{
	int l,r;
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r;
		if(l!=1)
			cout<<q_left(1,r,1)-q_r(1,l-1,1)<<endl;
		else
			cout<<q_left(1,r,1)<<endl;
	}
}

void init()
{
	int l,r;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>r;
		if(l>r)
			swap(l,r);
		update_left(l,1);
		update_right(r,1);
	}	
}

int main()
{
	cin>>n>>m;
	build_tree(1,40000,1);
	init();
	qwq();
	return 0;
}
/*
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

int n, m, cnt = 0;
struct Event
{
	int x, p;
}e[1000001];

int cmp(const Event &a, const Event &b)
{
	return a.x < b.x;
}

int s[1000001], t[1000001];

int main()
{
	scanf("%d%d", &n, &m);
	int L, R, x;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &L, &R);
		e[++cnt].x = L;
		e[cnt].p = 1;
		e[++cnt].x = R;
		e[cnt].p = -1;
	}

	sort(e + 1, e + 1 + cnt, cmp);
	L = 1;
	for (int i = 1; i <= cnt; ++i)
	{
		while (L <= e[i].x)
		{
			s[L] += s[L - 1];
			t[L] += t[L - 1];
			++L;
		}
		if (e[i].p == 1)
			s[e[i].x]++;
		else
			t[e[i].x]++;
	}
	while (L <= 1000000)
	{
		s[L] += s[L - 1];
		t[L] += t[L - 1];
		++L;
	}
	while (m--)
	{
		scanf("%d%d", &L, &R);
		printf("%d\n", s[R] - t[L - 1]);
	}
}
*/