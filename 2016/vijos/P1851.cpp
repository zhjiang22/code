/*
果然普及组的数据就是弱
见证了文化之旅后又一神数据啊
1000的数据范围一个裸的O(N^3)过了
唉醉了醉了
一个下午就调试了这个程序
原因是因为没看清题目
以为所有的火车都是要从1出发到n的
然后边太多一直循环退不出来~也是醉了
最后向题解投降了	一看自己思路没错啊！
然后发现建图炸了。。百脸懵逼
窝们看一下这道题~可以发现很明显有topo的意味
及区间[s,t]设停靠过的车站为xi,未停靠的为yi
那么必然是会有所有的yi<xi的
因为如果yi>=xi那么他一定要停下来
这就成了一个拓扑排序的约束条件了叭~~
那么窝们对于一个区间[s,t]中所有的没有停靠的点向停靠的点连一条有向边
表示该点的等级要小于有向边终点的等级
然后可以进行topo排序的思想了
怎么统计至少有几个等级呢？
我们每次进行topo删除所有入度为0的点
然后删除所有他的出边~即将出边的顶点的入度in[i]--
这样以此反复
在同一次删除的点必然是在同一等级最优的
那么要删除几次才能删除完就是最少的等级数咯~
这里的代码有点丑~勿喷
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int MAXN=1005;
bool g[MAXN][MAXN];
bool have[MAXN];
int in[MAXN];
int v[MAXN];
stack<int>s;
int n,m;
int tot;
int ans;

void init()
{
	scanf("%d%d",&n,&m);
	int s;
	int a[MAXN];
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		memset(v,0,sizeof(v));
		for(int j=1;j<=s;j++)
		{
			cin>>a[j];
			v[a[j]]=1;
		}
		for(int k=a[1];k<=a[s];k++)
			if(!v[k])
				for(int j=1;j<=s;j++)
					if(!g[k][a[j]])
						g[k][a[j]]=1,in[a[j]]++;
	}
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		if(!in[i])
			in[i]=-1,s.push(i);
	while(1)
	{
		ans++;
		bool ok=1;
		for(int i=1;i<=n;i++)
			if(in[i]!=-1)
				ok=0;
		if(ok)
			break;
		while(!s.empty())
		{
			int u=s.top();	s.pop();
			for(int i=1;i<=n;i++)
				if(g[u][i])
					in[i]--;
		}
		for(int i=1;i<=n;i++)
			if(!in[i])
				in[i]=-1,s.push(i);
	}
	cout<<ans<<endl;
	return 0;
}
  