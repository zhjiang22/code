/*
一道神犇好题啊
用单调队列来优化可以直接O(N)解决
然而这道题的数据真水啊
在下实在服了服了
直接O(N^2)当划分型dp做就好了
即定义f[i]表示搬运到第i件物品的时候需要的最小路程
那么我们就很容易有这样的转移方程
f[i]=min(f[i],f[j-1]+sg[i]-sg[j]+g[i]+g[j])	其中s[i]-s[j-1]<=c
其中sg[i]表示从1..2..i这几个点轮着走过需要的距离
g[i]表示(0,0)到第i个点的距离
自己想一下就很容易想清楚这个代价了
但是实际上虽然数据很弱	但是还是会TLE的
(窝闲来无聊试了一下	实际的n最大值达到5万)
这样n^2肯定还是超时的
那么我们看到怎么优化一小点以AC呢？
我们看到
如果我们从i...1枚举j如果已经碰到了一个j
不满足s[i]-s[j-1]<=c
那么前面的j肯定也不满足了
就直接break内层循环就好了
然后就AC了此题
果然窝太弱啦
不会用单调队列啊
唉一个晚上就因为窝输入顺序从x,y,w变成了w,x,y
还神奇地过了样例
然后就傻逼了一晚上
哭了出来QWQ
单调队列的做法在训练指南74页也写的很详细了
这里就直接上代码啦~
vijos神数据
O(N^2)的算法和O(N)的算法时间竟然相差不了多少mdzz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long MAXN=100005;
const long long INF=((long long)1<<60)-1;
struct node
{
	long long x,y,w;
}a[MAXN];
long long sg[MAXN];
long long g[MAXN];
long long f[MAXN];
long long s[MAXN];
int q[MAXN];
int front,rear;
int n,c;

void init()
{
	scanf("%d%d",&c,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].w);
		s[i]=s[i-1]+a[i].w;
		g[i]=(abs(a[i].x)+abs(a[i].y));
		sg[i]=sg[i-1]+abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y);
	}
}

inline long long func(int i)
{
	return f[i]-sg[i+1]+g[i+1];
}

int main()
{
	init();
	front=rear=1;
	for(int i=1;i<=n;i++)
	{
		while(front<=rear&&s[i]-s[q[front]]>c)
			front++;
		f[i]=func(q[front])+sg[i]+g[i];
		long long k=func(i);
		while(front<=rear&&k<=func(q[rear]))
			rear--;
		q[++rear]=i;
	}
	cout<<f[n]<<endl;
	return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long MAXN=10005;
const long long INF=((long long)1<<60)-1;
struct node
{
	long long x,y,w;
}a[MAXN];
long long sg[MAXN];
long long g[MAXN];
long long f[MAXN];
long long s[MAXN];
long long n,c;

inline long long getd(long long i,long long j)
{
	long long x=a[i].x-a[j].x;
	long long y=a[i].y-a[j].y;
	return abs(x)+abs(y);
}

void init()
{
	scanf("%lld%lld",&c,&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].w),s[i]=s[i-1]+a[i].w;
	for(long long i=1;i<=n;i++)
		g[i]=(abs(a[i].x)+abs(a[i].y));
	for(long long i=2;i<=n;i++)
		sg[i]=sg[i-1]+getd(i-1,i);
	for(long long i=1;i<=n;i++)
		f[i]=INF;
}

int main()
{
	init();
	for(long long i=1;i<=n;i++)
		for(long long j=i;j>=1;j--)
			if(s[i]-s[j-1]<=c)
				f[i]=min(f[i],f[j-1]+sg[i]-sg[j]+g[i]+g[j]);
			else
				break;
	cout<<f[n]<<endl;
	return 0;
}
*/   