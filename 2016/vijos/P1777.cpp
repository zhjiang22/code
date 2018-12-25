/*
好题啊~看到这样的流水问题
第一眼很容易想到floodfill惹~所以就可以直接先dfs一下(比bfs好写啦)
所以我们可以这样来做~
首先对于第一行的每个点进行一边dfs
预处理出每个点开始dfs后可以在n行造成多少个地方可以建立水电设施
这里就有一个很关键的证明了
如果问题有解(最后一行可以全部建立)
那么必然有第一行某个点开始dfs造成的效应一定是连续的一行
如果不是连续的一行的话
那么必然是无解的(可以证明)
其实就是有一个区间断开来了
设中间断开的点为x那么有x会比左右上的都更高
那么必然无解
也可以这样想
如果其它点如果能到中间断开的那一段的话，那个点引出的路径和这个点引出的路径必有交点，
则这个点引出的路径也可以沿这个交点走下去
所以不可能成立
那么有了这个性质之后就很容易做了
我们首先用一个判断一下能否全部建成(这个很简单了)
然后对于m个第一行开始可以dfs出效应的区间
要用最小的区间数来拼接成一个完整的[1,m]的区间
这样就变成了区间覆盖问题了
lrj的算法竞赛入门经典中也有
窝们可以O(nlogn)排序+O(n)的贪心或者直接O(n^2)的dp咯
窝是直接写的贪心会更好一点啦~~~
就是窝们将区间按照左端点从小到大排序~
对于一个当前要满足的区间[x,]肯定是选取以x为起点的所有区间中最长的
这样必然会更优	设选取的区间右端点为y
选取了这个区间后问题就变成了覆盖[y,]的问题了
以此类推直到选完覆盖所有区间~
这个是比较朴素的做法了	在vijos上勉强能过(一个点960ms)
在洛谷上T一个点
还有更好的做法可以自己探究咯~
害怕
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=505;
const int INF=(1<<30)-1;
struct node
{
	int l,r;
	node()
	{
		l=INF;	r=0;
	}
};
node g[MAXN];
int a[MAXN][MAXN];
bool v[MAXN][MAXN];
bool can[MAXN];
int zx[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int ans;
int n,m;

inline bool cmp(const node&a,const node&b)
{
	return a.l<b.l;
}

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	ans=m;
}

void dfs(int x,int y,int n_clock)
{
	if(x==n)
	{
		if(!can[y])
		{
			can[y]=1;
			ans--;
		}
		g[n_clock].l=min(g[n_clock].l,y);
		g[n_clock].r=max(g[n_clock].r,y);
	}
	v[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int newx=x+zx[i][0];	int newy=y+zx[i][1];
		if(v[newx][newy]||newx>n||newx<1||newy>m||newy<1)
			continue;
		if(a[newx][newy]<a[x][y])
			dfs(newx,newy,n_clock);
	}
}

int solve()
{
	sort(g+1,g+m+1,cmp);
	int L=1,cnt=0,k=1;
	while(L<=m)
	{
		cnt++;
		int R=L;
		for(;k<=m&&g[k].l<=L;k++)
			R=max(R,g[k].r);
		L=R+1;
	}
	return cnt;
}

int main()
{
	init();
	for(int i=1;i<=m;i++)
	{
		memset(v,0,sizeof(v));
		dfs(1,i,i);
	}
	if(ans)
		cout<<0<<endl<<ans<<endl;
	else
		cout<<1<<endl<<solve()<<endl;
	return 0;
}
     