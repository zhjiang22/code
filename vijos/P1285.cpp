/*
好题，长见识了
一开始一直在想，怎么处理点的权值和边的权值都给出的问题
呼呼后来发现，直接用dijkstra算法，输入的点的权值
即为dist[]数组了
哎做题还是少
然后就开始做了
根据乘法原理，我们知道，如果药水A最优可以由B和C合成
而B有x种合成方法，C有y种合成方法
那A就有x*y种合成方法
而且如果A最优还可以由D,E合成
拿我们就还要再加上D,E方案的乘积
嗯其实挺好理解的，关键是怎么建图处理问题~
首先我们用g[][]来储存图，g[i][j]=k表示i和j可以合成k
注意我是因为习惯了数组从1开始(处女座2333)
Orz但是药水是从0开始编号的
所以在读入a,b,c建图时，我们要写成
g[a+1][b+1]=g[b+1][a+1]=c+1;
一开始很蠢地没有想到这个，然后一直样例WA
过了几分钟才反应过来QAQ我太弱了
用一个s[]来记录dijkstra中的集合思想
s[i]=1表示不在集合内,s[i]=0表示在集合中
用t[]记录方案数
我们每次循环，找到一个dist[]最小的点
将其加入集合
对于每一个新加入集合的点k，尝试用已经在集合中的点i和k点的边来更新路径
注意如果是可以更新出更优值，就要更新dist[]和t[]
不然就还要判断是否是相同优解	如果是	则t[]要加上这种情况
数据会存在环	所以树形dp不是很好做
但是总有大神是能做的	只能说我太弱
因为读入数据有可能有a,b相同情况
所以用邻接矩阵更好一点不用判重
但是好像有个大犇说题目有错？
不知道是真是假我没有试，但是不得不承认我的确没有想过这种情况
强无敌
{
	数据 貌似 有错 啊 ……
不同种 药水 配置的时候：
例如 1号+3号 可以得到 2号， 1号有三种配法 3号有三种配法 ，那么此时 2号 可以 得到 3*3=9 种 配法
但是 同种 配置 的时候：
例如 1号+1号 得到 2 号 ，1号有 三种 配法 ，那么 此时 2号可以 得到 的 配法 数 应为： 
3*（3+1）/2=6种 ，而非 3*3=9种 
我把 这种 情况 考虑进去 ，只有 70分 …… 不考虑 就 秒杀 了 ……
或者 说 我 理解 题意 有误？？……
}
呼呼
再配上大神的树形dp思路，共勉
{
	树状DP
环的处理：对与 1 2 3
2 3 1
数据 欲求药水3的最优值，因为药水3需要用到药水1，药水1需要用到药水3，那么
dp[1]+dp[2]>min(dp[3])即以药水1，2混合得来的绝对不是药水3的最优值。因为
药水1已经包含3的最优值，3包含了3的最优值，这样由1，2的得来的
dp[3]=dp[2]+dp[3]+其他药水最优值，如果去掉DP[2]与其他药水最优值绝对更优
这种环的处理只要加个BOOLEAN判断，在递归求解时对于已经递归的药水不再进行求解（FALSE）！只有（TRUE）再进行递归求解！！！（看不懂我也没办法，第一次写）
}
嗯看代码吧，其实编程难度不高的，主要是算法有点难想到
差点就想用SPFA了，也不知道可不可做
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1100;
const int INF=0x7fffffff;
int g[MAXN][MAXN];
int t[MAXN];
int dist[MAXN];
bool s[MAXN];
int n;

void init()
{
	int a,b,c;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>dist[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			g[i][j]=INF;
			t[i]=s[i]=1;
		}
	while(scanf("%d%d%d",&a,&b,&c)==3)
		g[a+1][b+1]=g[b+1][a+1]=c+1;
}

void dijkstra(int k)
{
	for(int i=1;i<=n;i++)
		if(!s[i]&&g[k][i]!=INF)
			if(dist[g[k][i]]>dist[k]+dist[i])
			{
				dist[g[k][i]]=dist[k]+dist[i];
				t[g[k][i]]=t[k]*t[i];
			}
			else	if(dist[g[k][i]]==dist[k]+dist[i])
				t[g[k][i]]+=t[k]*t[i];
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		int m=INF,k;
		for(int j=1;j<=n;j++)
			if(s[j]&&dist[j]<m)
			{
				m=dist[j];
				k=j;
			}
		if(m==INF)
			break;
		s[k]=false;
		dijkstra(k);
	}
	cout<<dist[1]<<" "<<t[1]<<endl;
	return 0;
}
     