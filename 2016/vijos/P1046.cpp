/*
嗯典型的最小环问题
因为n很小可以直接Floyd求最小环
注意最小环ans更新的位置
每次枚举k为下家更新点
应该先尝试更新ans再更新i,j之间的最短路
我们用g[i][j]来记录i,j之间最短路径
而w[i][j]用来保存i,j之间的原始路径长度
因为我们知道i,j要构成一个最小环
肯定要有两条路可走
1.直接从i到j。
2.从i经过某个中途点k到达j
即对于每一个k	我们先尝试从这个k点对于所有的i,j点能不能得到最小环
然后我们再用这个k点尝试更新路径
该算法的证明:
一个环中的最大结点为K（编号最大），与其相连的两个点为i,j ，
这个环的最短长度为： g[i][k] + g[k][j] + i到j的路径中所有结点编号都不大于k的最短路径长度，
根据floyd的原理，在最外层循环做一个k-1次之后，
g[i][j] 则代表了i到j的路径中所有结点的编号都不大于k的最短路径。
所以我们枚举的i,j要有
1<=i<k,i<j<k
再换一种说法吧
比普通Floyd多出来的部分,主要利用到的原理是当处理到k时,
所有以1 到k - 1为中间结点的最短路径都已经确定，
则这时候的环为（i到j(1 < i, j <= k - 1)的最短路径） + 边（i, k） + 边（k, j）
遍历所有的i, j找到上述式子的最小值即位k下的最小代价环  
这样总能懂了吧QAQ
*/
/*
路径的求法：
用一个pre[i][j]记录j前面的一个顶点， 初始化为i，当出现需要更新的时候则将pre[i][j] = pre[k][j];
若i== j的时候则表示找全了路径，最后将k点加入路径中 
核心代码：
While(i ！= j)
{  
	if (i != j) 
	{  
		Path[len++] = j;
	 	J = pre[i][j]; 
	}  
	 Path[len++] = i;
}
http://wenku.baidu.com/view/c6382a41a8956bec0975e3c0.html?from=related
http://blog.csdn.net/youngyangyang04/article/details/7054931
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF=1e8;
int w[102][102],g[102][102];
int n,e;

void init()
{
	int x,y,v;
	for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j]=g[i][j]=INF;
	for(int i=1;i<=e;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		w[x][y]=w[y][x]=g[x][y]=g[y][x]=v;
	}
}

void work()
{
	int ans=INF;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)//最小环
			for(int j=i+1;j<k;j++)//为了避免一条边计算两次并且i == j时因为权重会出错 
				ans=min(ans,g[i][j]+w[i][k]+w[k][j]);
		for(int i=1;i<=n;i++)//Floyd
			for(int j=1;j<=n;j++)
				if(i!=j)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	}
	if(ans==INF)
		cout<<"No solution."<<endl;
	else
		cout<<ans<<endl;
}

int main()
{
	while(scanf("%d%d",&n,&e)!=EOF)
	{
		init();
		work();
	}
}