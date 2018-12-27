/*
这题数据太弱了？本来想用来练线段树的但是数据太弱直接枚举就好
我就偷个懒了。。反正我也不咋会线段树，但还是说一句以后有时间再来看看
附个线段树代码吧
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct point {
    int x, y;
} _p[15005];
struct Node {
    int l, mid, r;
    int val;
} q[75000];
struct in {
    int x, y, t;
} p[15005];
int n;
int ans[15005];

bool cmp(point a, point b) {
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    if (a.y < b.y)
        return true;
    else
        return false;
}
void initialization(int node, int l, int r) {
    q[node].l = l;
    q[node].mid = (l + r) / 2;
    q[node].r = r;
    if (l == r)
        return ;
    initialization(node * 2, l, q[node].mid);
    initialization(node * 2 + 1, q[node].mid + 1, r);
}
void add(int node, int lr, int val) {
    if (q[node].r == lr && q[node].l == lr) {        
        q[node].val += val;
        return ;
    }
    if (lr <= q[node].mid) {
        add(node * 2, lr, val);
        q[node].val += val;
    }
    else {
        add(node * 2 + 1, lr, val);
        q[node].val += val;
    }
}
int sum(int node, int l, int r) {
    if (q[node].l == l && q[node].r == r) {
        return q[node].val;
    }
    if (r <= q[node].mid)
        return sum(node * 2, l, r);
    if (l <= q[node].mid && q[node].mid < r)
        return (sum(node * 2, l, q[node].mid) + sum(node * 2 + 1, q[node].mid + 1, r));
    if (q[node].mid <= l)
        return (sum(node * 2 + 1, l, r));
}
int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    int maxy = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &_p[i].x, &_p[i].y);
        if (_p[i].y > maxy)
            maxy = _p[i].y;
    }
    sort(_p + 1, _p + n + 1, cmp);
    initialization(1, 1, maxy);
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        if (_p[i].x != _p[i - 1].x || _p[i].y != _p[i - 1].y) {
            p[++tot].x = _p[i].x;
            p[tot].y = _p[i].y;
            p[tot].t = 1;
        }
        else
            ++p[tot].t;
    }
    for (int i = 1; i <= tot; ++i) {
        add(1, p[i].y, p[i].t);
        ans[sum(1, 1, p[i].y) - 1] += p[i].t;
    }
    for (int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
嗯再来个树状数组的代码
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,ans[15001],a[32001]={0},maxx=0;
struct poi{
    int x,y;
}p[15001];
bool cmp(const poi &a,const poi &b){
    if(a.y!=b.y)return a.y<b.y;
    else return a.x<b.x;
}
int lowbit(int x){
    return x&(-x);
}
void change(int pos){
    for(int i=pos;i<=32000;i+=lowbit(i))
     a[i]++;
}
int findsum(int pos){
    int sum=0;
    for(;pos>0;pos=pos-lowbit(pos))
    sum+=a[pos];
    return sum;
}
int main(){
    int i,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        maxx=max(maxx,p[i].x);
    }
    sort(p+1,p+n+1,cmp);
    for(i=1;i<=n;i++){
        ans[findsum(p[i].x)]++;
        change(p[i].x);
    }
    for(i=0;i<n;i++)printf("%d\n",ans[i]);
    return 0;
}
然后开始写朴素算法了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct node
{
	int x,y;
}a[15005];
int n;
int ans[15005];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	for(int i=1;i<=n;i++)
	{
		int tot=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			else
				if(a[j].x<=a[i].x&&a[j].y<=a[i].y)
					tot++;
		}
		ans[tot]++;
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
