/*
看到这道题的时候有木有感觉看到了一种数字三角形的感觉？
其实就是一个变形了
只不过是把向前的三种走法变成了同一行的左右不走三种走法
所以我们先来考虑第二问
不可能接到的礼物这里需要注意有两种情况
首先是H%v!=0	这样的话它不可能在某个整秒时间恰好落在格点上自然也不可能取到
还有就是abs(r-P)>t+(H/v)	意思就是下落距离太大了哪怕一直向那个方向走也赶不上
然后我们建立价值图
w[i][j]表示在第i时间在第j格所能取到的价值
那么我们注意单独处理每个物品的时候
我们先判断有没有可能取到
如果可以取到的话我们就可以加入价值中去
w[t+H/v][r]+=s同时记录下所有可以接到的物品的最大时间
注意了我们这里的物品的时间
应该是开始下落的时间+到达底部的时间
不要一不小心漏写了t就好啦
然后定义状态f[i][j]表示第i秒在第j格所能取到的最大值
那么我们很容易有状态转移方程
f[i][j]=max(f[i-1][j],max(f[i-1][j-1],f[i-1][j+1]))+w[i][j];
转移的时候i从1到我们记录的最大时间值maxt
初值为f[0][P]=0	其他设为-INF
然后就随便像数字三角形一样随便转移两下就好了
最后我们取最大值应该遍历所有的
f[maxt][i]即最后一秒所处的所有可能的位置可能达到的最大值
就水出了这道题目
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=3005;
int w[MAXN][MAXN];
int f[MAXN][MAXN];
int W,P,H,n;
int nans;
int maxt;
int ans=-0x7ffff;

void init()
{
	int t,r,s,v;
	cin>>W>>P>>H>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t>>r>>v>>s;
		if(H%v!=0||abs(r-P)>t+(H/v))
			nans+=s;
		else
			w[t+H/v][r]+=s,maxt=max(maxt,t+H/v);
	}
	memset(f,-0x3f,sizeof(f));
	f[0][P]=0;
}

int main()
{
	init();
	for(int i=1;i<=maxt;i++)
		for(int j=1;j<=W;j++)
			f[i][j]=max(f[i-1][j],max(f[i-1][j-1],f[i-1][j+1]))+w[i][j];
	for(int i=1;i<=W;i++)
		ans=max(ans,f[maxt][i]);
	cout<<ans<<endl;
	cout<<nans<<endl;
	return 0;
}
     