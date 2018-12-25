/*
OTZ动态规划？
数据范围实在太小了n在50以内
直接dfs搜索就好了
这题目有点坑的地方就在于题意的理解
{
（1）除非汽车无法用油箱里的汽油达到下一个加油站或目的地，在油箱里还有不少于最大容量一半的汽油时，驾驶员从不在加油站停下来；
（2）在每个停下的加油站总是将油箱加满；	
}
因为是每次将油箱装满所以问题会简单很多
主要我们来看第一个问题
这句话怎么理解？
很坑啊意思就是，如果汽车无法到达下一站，则一定要加油
如果油箱还有一半少的油，那么可以加油也可以不加油(当然前提是只有能到下一站才可能不加油)
那么如果油箱有一半多的油	并且能到下一站就是不能加油的
有点绕自己好好理解(%%%%各位语文学霸)
然后我们就直接dfs一下就好
事实证明	裸的dfs也可以轻轻松松50ms内解决所有的点
但是为了训练一下特地加了个优化
我们用minw[i]表示第i个加油站之后可能达到的最便宜的油费
然后预处理递推一下就好了
当我们发现不管怎么样剩下的距离需要的油钱+当前消费
都会>目前的最优解时	直接剪枝就好了
这只是个粗略的剪枝	其实肯定还可以更好的
但是就懒得再继续写了
超级水的一道题
唉好好的一道动规被你们玩坏了
城市套路深	城里人真会玩
这个程序可以直接秒杀了QWQ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=55;
struct node 
{
	double x,w;
}a[MAXN];
double S,v,W,L;
double minw[MAXN];
double ans=999999.0;
int n;

void init()
{
	cin>>S>>L>>v>>W;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].w;
	a[n+1].x=S;
}

void getshort()
{
	minw[n]=a[n].w;
	for(int i=n-1;i>=1;i--)
		minw[i]=min(minw[i+1],a[i].w);
}

inline void dfs(int x,double l,double waste)
{
	if(x==n+1)
	{
		ans=min(ans,waste);
		return;
	}
	if(waste+max(double(0),(a[n+1].x-a[x].x)/v-l)*minw[x]>=ans)
		return;
	if(l<L/2||l*v<a[x+1].x-a[x].x)
		dfs(x+1,L-(a[x+1].x-a[x].x)/v,waste+(L-l)*a[x].w+20);
	if(l*v>=a[x+1].x-a[x].x)
		dfs(x+1,l-(a[x+1].x-a[x].x)/v,waste);
}

int main()
{
	init();
	getshort();
	dfs(1,L-a[1].x/v,W);
	printf("%.1lf\n",ans);
	return 0;
}
     