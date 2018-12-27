#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN = 50005;
struct Node
{
	LL lmax, rmax;
	LL sum, maxd;
} tree[MAXN << 2];
int a[MAXN];
int n, q;

void Update(int o, int l, int r)
{
	int lc = (o << 1), rc = (o << 1 | 1);
	tree[o].sum = tree[lc].sum + tree[rc].sum;
	tree[o].lmax = max(tree[lc].lmax, tree[rc].lmax + tree[lc].sum);
	tree[o].rmax = max(tree[rc].rmax, tree[lc].rmax + tree[rc].sum);
	tree[o].maxd = max(tree[lc].rmax + tree[rc].lmax, max(tree[lc].maxd, tree[rc].maxd));
}

void build(int o, int l, int r)
{
	if (l == r)
	{
		tree[o].lmax = tree[o].rmax = tree[o].sum = tree[o].maxd = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	int lc = (o << 1), rc = (o << 1 | 1);
	build(lc, l, mid);
	build(rc, mid + 1, r);
	Update(o, l, r);
}

void update(int o, int l, int r, int p, int x)
{
	if (l == r && l == p)
	{
		tree[o].lmax = tree[o].rmax = tree[o].sum = tree[o].maxd = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (p <= mid)
		update(o << 1, l, mid, p, x);
	else
		update(o << 1 | 1, mid + 1, r, p, x);
	Update(o, l, r);
}

LL ans, ret;

void query(int o, int l, int r, int x, int y)
{
	if (l >= x && r <= y)
	{
		ans = max(ans, tree[o].maxd);
		if (l == x)
			ret = tree[o].rmax;
		else if (r == y)
		{
			ret += tree[o].lmax;
			ans = max(ans, ret);
		}
		else
		{
			ans = max(ans, ret + tree[o].lmax);
			if (ret + tree[o].sum > tree[o].rmax)
				ret += tree[o].sum;
			else
				ret = tree[o].rmax;
			ans = max(ans, ret);
		}
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
		query(o << 1, l, mid, x, y);
	if (y > mid)
		query(o << 1 | 1, mid + 1, r, x, y);
}

void init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
}

void work()
{
	cin >> q;
	int k, x, y;
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d%d", &k, &x, &y);
		if (k == 0)
		{
			update(1, 1, n, x, y);
		}
		else
		{
			ans = -(1 << 30);
			ret = 0;
			query(1, 1, n, x, y);
			printf("%lld\n", ans);
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}