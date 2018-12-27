/*
真心...阴险的题目
第i行第j列的正整数k代表:第i个人对颜色为k的球的喜爱程度是j
别搞反了...
其实样例说明很良心啊
默默在提示我们贪心的原则
我们看到设一个人对求得喜爱程度从大到小排为
a1 a2 a3 a4.... an
那么如果他选a1很有可能直接被后面的人换走了
这样必然不划算
所以我们可以发现编号为n的人是具有最优主动权的
他一定可以拿到他最喜欢的球
而n-1个人一定是拿到第n个人拿的球以外他最喜欢的球
那么这样贪心策略就出来了
直接从第n个人到第一个人开始贪心
每个人都拿最喜欢的没被选取的求
n只有50直接开个v[]判断是否被拿过就好了
同时发现输入数据时
对于第i个人
输入的球编号一定是对它的喜爱程序从小到大的(喜爱程度为j)
那么就可以直接从后面开始取了
这里我是习惯了用vector实际上数组都一样的
因为n是固定了的
所以这题还是很好写的直接乱搞就好啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=55;
vector<int> g[MAXN];
int ans[MAXN];
int a[MAXN];
int v[MAXN];
int n;

inline bool cmp(const int& a,const int& b)
{
	return a>b;
}

void init()
{
	int k;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>k;
			g[i].push_back(k);
		}
}

int main()
{
	init();
	for(int i=n;i>=1;i--)
	{
		int j=g[i].size()-1;
		while(v[g[i][j]])
			j--;
		ans[i]=g[i][j];
		v[g[i][j]]=1;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
     