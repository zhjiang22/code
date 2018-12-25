/*
好题啊~>3<
一道巧妙地0/1背包变形~
我们可以看出这个题目的求解的最优问题是满足动规的几个特性的
同时我们看到每棵树都有选或者不选两个决策
首先这道题的亮点是采摘树要按果子数量要升序排列
那么我们肯定可以想到先按照果子数量从小到大排序
这样我们转移的时候就可以直接用前面的来转移到后面这里~
当然因为两棵树的距离是固定了位置的
所以我们在排序的时候必然还要记录下原先这棵树的固定位置
这样才能正确地得到某两棵树的距离时间
那么很容易发现树就是物品	时间就是容量	价值就是果子的价值咯
我们可以定义出状态
f[i][j]表示当前最后采的是第i棵树,花费了j时间所能达到的最大价值
状态转移方程就是
f[i][j]=max(f[i][j],f[k][j-(g[t[k].idx][t[i].idx]+t[i].w)]+t[i].v);
其中k是满足条件的左边的树(注意我们还是要判断t[i].a和t[k].a的关系的，因为有可能有相等的)
这样我们就会发现
我们可以从0...i-1转移到当前状态
从第k棵树到这棵树的代价就是g[t[k].idx][t[i].idx]+t[i].w
其中idx是用来记录当前第i棵树原先的位置
然后我们就可以直接进行转移了
复杂度O(n^2*m)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXM=1005;
struct node
{
	int a,v,w;
	int idx;
}t[MAXN];
int g[MAXN][MAXN];
int f[MAXN][MAXM];
int n,m;
int ans;

inline bool cmp(node x,node y)
{
	return x.a<y.a;
}

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].a>>t[i].v>>t[i].w;
		t[i].idx=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>g[i][j];
	sort(t+1,t+n+1,cmp);
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--)
			for(int k=0;k<i;k++)
				if(j-(g[t[k].idx][t[i].idx]+t[i].w)>=0&&t[i].a>t[k].a)//会有相等的情况！
					f[i][j]=max(f[i][j],f[k][j-(g[t[k].idx][t[i].idx]+t[i].w)]+t[i].v);
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i][m]);
	cout<<ans<<endl;
	return 0;
}
     