/*
醉了醉了~
这题弄了一下午一直只能过样例+第一个点
这是为啥呢
然后才发现INF傻逼一般地打成了int型，然后一改double瞬间AC
悲伤的故事
这是一道痕经典的动规问题吧
lrj紫书上dp一章P269有~
f[ i ][ j ]表示第一个人走到i，第二个人走到j 的最短路径，
要求i<j，且0到j的点都被经过了(因为f[i][j]和f[j][i]等效，所以可以减少枚举)
这样很容易想到，j+1的点不是被第一个人走，就是被第二个人走
考虑到找前驱状态很麻烦~我们就可以找后继状态去刷新他们的值
也就是刷表法了~~
所以有转移方程
f[ i ][ j+1]=min{ f[ i ] [ j ]+d[ j ] [ j +1] } 
f[ j ] [ j+1 ]=min{ f[ i ][ j ]+d[ i ][ j+1 ] }
初值f[0][1]=d[0][1](d[i][j]表示第i个点到第j个点的距离)
即可以发现对于某个状态来说，他可以连锁更新两个状态，
即f[i][j+1],f[j][j+1]
嗯第一个方程应该很好解释了
就是第二个人走到下一个点的情况
第二个方程可以这么理解，
两个人可以指前面一个人，和后面一个人，
当后面的人走到前面，当然就对换过来了，不影响结果
即两个人是不区分的，只是一个前面一个后面，因为是等效的
所以当后面这个人走到j+1位置的时候，那肯定会有原来走的更前的那个人
变成了更后的那个人，即变成了f[j][j+1]
(好好理解一下)
这样就不难操作了，我们先预处理一下数据
对于读进的数，我们按从横坐标从小到大排序
然后预处理距离d[][]，用勾股定理求坐标距离就好了
注意不管是f[][]还是d[][]我们都只需要求f[i][j](i<j)即可
然后再扫描一遍求所有状态的可能情况(不包括终点)
我们的f[][n]表示的是前面那个人走到了n点了
但是后面那个人还没有到n点
如果要完成一个哈密尔
顿回路的话就还差了后面那个人到n点的距离
所以答案就是min{f[i][n]+d[i][n]}
所以遍历一下这n-1种状态就好了>3<
好题~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const double INF=1e30;
const int MAXN=1003;
struct node
{
	double x,y;
	bool operator<(const node&b)const
	{
		return x<b.x;
	}
}a[MAXN];
int n;
double ans=INF;
double f[MAXN][MAXN];
double d[MAXN][MAXN];

double getd(int i,int j)
{
	double x=fabs(a[i].x-a[j].x);
	double y=fabs(a[i].y-a[j].y);
	return sqrt(x*x+y*y);
}

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			d[i][j]=getd(i,j),f[i][j]=INF;
}

void DP()
{
	f[1][2]=d[1][2];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			f[i][j+1]=min(f[i][j+1],f[i][j]+d[j][j+1]);
			f[j][j+1]=min(f[j][j+1],f[i][j]+d[i][j+1]);
		}
	for(int i=1;i<=n-1;i++)  
        ans=min(ans,f[i][n]+d[i][n]);  
	printf("%.2lf\n",ans);
}

int main()
{
	init();
	DP();
}