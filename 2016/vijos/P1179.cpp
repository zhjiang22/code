/*
感觉以前的老题还是有的蛮好的~
数据范围n+m<=10那么我们很容易想到直接枚举每一个邮票种类
很明显容易发现根本无法枚举因为面值无上下线
那么我们给它找一个限制范围不就好了？
首先我们保证g[]为递增这样更方便
那么g[1]必然为1	不然连面额1都满足不了
这样我们就可以开始dfs
那怎么判断一种面额方案可以达到的最大连续面额呢？
我们可以用背包dp的思想
注意是完全背包(每种邮票无限多个)
即我们定义f[i]表示在当前邮票面额的安排下
组成i的面额需要的最少邮票数
所以有f[0]=0	f[i]=INF
我们用背包思想递推
对于每一个f[i]枚举每一个邮票g[j]
如果i>=g[j]	那么f[i]=min(f[i],f[i-g[j]]+1)
这个是一个很裸的背包了
注意到这个f[]一定是非降序列～
而且关于题目的要求我们发现只要递推完一个f[i]发现f[i]>n(可以贴的邮票数)
就说明到这里为止就无法达到要求了
那么就可以返回i-1了
这样我们就很容易判断一个邮票序列可以得到的连续最大值了
那么我们枚举怎么枚举下一个数？
首先我们说了必须要是递增的(否则可以被等效)
那么久从当前这个数+1开始枚举
同时对于当前求出来的这个连续最大值x
我们枚举的下一个数必然不能大于x+1
因为如果大于x+1之后必然就无法达到邮票价值x+1了
这是一个很强力的剪枝
这样的话就可以在很快的时间出结果了
注意我们要求的最终答案如果多解需要字典序更大的
因为我们是从小到大枚举
所以先得到的必然是字典序小的方案
所以更新答案的时候只要当前答案x>=ans就要更新(字典序会更大~)
这样就做完了一题啦~
还有一个细节
在dfs过程内我们很容易发现对于一个组合x1 x2 x3...
如果在后面再加上一个邮票价值(递归到下一层)
那么必然不会让解变差
所以最后的答案一定是齐全了m个的
所以*标记处加上一个cur==m也是可以得到正确答案的
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=12;
const int MAXV=505;
int Ans[MAXN],ans,ansl;
int g[MAXN];
int f[MAXV];
int n,m;

void init()
{
	cin>>n>>m;
}

int dp(int l)
{
	memset(f,0x3f,sizeof(f));	f[0]=0;
	int maxw=1;
	for(;;maxw++)
	{
		for(int i=1;i<=l;i++)
			if(maxw>=g[i])
				f[maxw]=min(f[maxw],f[maxw-g[i]]+1);
		if(f[maxw]>n)
			return maxw-1;
	}
}

void dfs(int cur)
{
	int maxw=dp(cur);
	if(maxw>=ans&&cur==m)//*
	{
		ans=maxw;	ansl=cur;
		memcpy(Ans,g,sizeof(int)*(cur+1));
	}
	if(cur==m)
		return;
	for(int i=g[cur]+1;i<=maxw+1;i++)
	{
		g[cur+1]=i;
		dfs(cur+1);
	}
}

void out()
{
	for(int i=1;i<=ansl;i++)
		cout<<Ans[i]<<" ";
	cout<<endl;
	cout<<"MAX="<<ans<<endl;
}

int main()
{
	init();
	g[1]=1; dfs(1);
	out();
}
     