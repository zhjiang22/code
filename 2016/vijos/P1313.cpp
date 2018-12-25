/*
经典的有依赖背包问题~
两个月前的窝表示完全一脸懵逼根本看不懂
现在发现特别水的dp了..
我们看到题目有一个很关键的限制条件！
每个主件可以有0个、1个或2个附件
这一共就三种情况了~
那么对于附件我们直接先忽略掉
因为只要在处理它的主件的同时处理它就好了
那么对于一个主件(准确的说是非附件)
我们可以有这么几种决策
1.不选这个主件
2.选了这个主件
{
	a.再选第一个附件(如果有的话)
	b.再选第二个附件(如果有的话)
	c.一二个附件一起选(如果有的话)
}
那么我们就可以按照该主件的附件数量进行转移了
转移和0/1背包是一模一样的很方便
同时考虑到都是10的正整数倍那么我们就可以处理花费和总价格的时候都除以个10
这样可以减小一些空间开销
对于主件附件的关系可以用vector和邻接表来写
窝偷懒就直接vector咯
同时还要记录一下一个物品是否有它的依赖的主件
代码有点丑~
但是领悟到了意思就很好写啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=65;
const int MAXV=3205;
vector<int> g[MAXN];
int w[MAXN],v[MAXN];
bool child[MAXN];
int f[MAXV];
int n,V;

void init()
{
	cin>>V>>n;	V/=10;
	int fa;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>w[i]>>fa;
		v[i]/=10;
		if(fa)
		{
			g[fa].push_back(i);
			child[i]=1;
		}
	}
}

void DP()
{
	for(int i=1;i<=n;i++)
	{
		if(child[i])
			continue;
		for(int j=V;j>=v[i];j--)
		{
			f[j]=max(f[j],f[j-v[i]]+v[i]*w[i]);
			if(g[i].size()==2)
			{
				if(j-v[i]-v[g[i][0]]-v[g[i][1]]>=0)
					f[j]=max(f[j],f[j-v[i]-v[g[i][0]]-v[g[i][1]]]+v[i]*w[i]+v[g[i][0]]*w[g[i][0]]+v[g[i][1]]*w[g[i][1]]);
				if(j-v[i]-v[g[i][1]]>=0)
					f[j]=max(f[j],f[j-v[i]-v[g[i][1]]]+v[i]*w[i]+v[g[i][1]]*w[g[i][1]]);
			}
			if(g[i].size()>=1)
				if(j-v[i]-v[g[i][0]]>=0)
					f[j]=max(f[j],f[j-v[i]-v[g[i][0]]]+v[i]*w[i]+v[g[i][0]]*w[g[i][0]]);		
		}
	}
	cout<<f[V]*10<<endl;
}

int main()
{
	init();
	DP();
	return 0;
}
     