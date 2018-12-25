/*
很明显的线段树区间操作
Orz
弱弱的我线段树并不好
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#define N 200005
using namespace std;
typedef long long LL;
int n, q;
struct node
{
    int l, r, maxl[2][2], len;
}tree[N * 4];
void init()
{
    //freopen("1.in", "r", stdin);
    scanf("%d%d", &n, &q);
}
void build_tree(int th, int l1, int r1)
{
    tree[th].l = l1;
    tree[th].r = r1;
    tree[th].maxl[0][0] = tree[th].maxl[1][0] = 1;
    tree[th].maxl[0][1] = tree[th].maxl[1][1] = 0;
    tree[th].len = 1;
    if(l1 == r1)
        return;
    int mid = (l1 + r1) / 2;
    build_tree(2 * th, l1, mid);
    build_tree(2 * th + 1, mid + 1, r1);
}
void change(int pos, int th)
{
    if(tree[th].l == tree[th].r)
    {
        tree[th].maxl[0][0] = tree[th].maxl[1][0] = 1 - tree[th].maxl[0][0];
        tree[th].maxl[0][1] = tree[th].maxl[1][1] = 1 - tree[th].maxl[0][1];
        return;
    }
    int mid = (tree[th].l + tree[th].r) / 2;
    if(pos <= mid)
        change(pos, 2 * th);
    else
        change(pos, 2 * th + 1);
    int len1 = mid - tree[th].l + 1, len2 = tree[th].r - mid;
    tree[th].maxl[0][0] = tree[2 * th].maxl[0][0];
    if(tree[th].maxl[0][0] == len1)
        tree[th].maxl[0][0] += tree[2 * th + 1].maxl[0][len1 & 1];
    tree[th].maxl[0][1] = tree[2 * th].maxl[0][1];
    if(tree[th].maxl[0][1] == len1)
        tree[th].maxl[0][1] += tree[2 * th + 1].maxl[0][(len1 + 1) & 1];
    tree[th].maxl[1][0] = tree[2 * th + 1].maxl[1][0];
    if(tree[th].maxl[1][0] == len2)
        tree[th].maxl[1][0] += tree[2 * th].maxl[1][len2 & 1];
    tree[th].maxl[1][1] = tree[2 * th + 1].maxl[1][1];
    if(tree[th].maxl[1][1] == len2)
        tree[th].maxl[1][1] += tree[2 * th].maxl[1][(len2 + 1) & 1];
    tree[th].len = max(tree[2 * th].len, tree[2 * th + 1].len);
    int tmp = max(tree[2 * th].maxl[1][0] + tree[2 * th + 1].maxl[0][1], tree[2 * th].maxl[1][1] + tree[2 * th + 1].maxl[0][0]);
    tree[th].len = max(tree[th].len, tmp);
}
void deal()
{
    build_tree(1, 1, n);
    for(int i = 1; i <= q; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        change(tmp, 1);
        printf("%d\n", tree[1].len);
    }
}
int main()
{
    init();
    deal();
    return 0;
}