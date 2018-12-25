/*
一道搜索题咯
先建立起一个结点之间的连接关系(这里是用邻接矩阵储存)
一层一层处理，枚举所有当前层的点，并删除它递归
因为要求最小值，如果还没有剪到叶节点就已经大于当前最大值了就可以剪枝
总而言之 递归搜索+小小的优化剪枝
详细见代码吧不是很难但是难想到
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF=0x7ffffff;
const int maxn=305;
int son[maxn];
int map[maxn][maxn];
int n,m;
int a,b;
int ans=INF;

void dfs(int tree[maxn],int s,int d,int res)
//四个参数：当前层子节点，结点个数，要删除的点，目前已经感染人数
{
	int son[maxn];//存放下一层子节点数组
	int cur=0;
	for(int i=1;i<=s;i++)//当前层所有子节点
	{
		int &a=tree[i];//取该层一个结点
		if(a==d)	continue;//如果是要删除的点则不操作
		for(int i=1;i<=n;i++)
			if(map[a][i])
				son[++cur]=i;//把当前层所有子节点构造出下一层
	}
		if(!cur)//如果到了叶子结点
			ans=min(ans,res);//更新最小值
		else
		{
			for(int i=1;i<=cur;i++)//下一层所有点
				if(res+cur-1<=ans)//剪枝,如果当前已经比ans大了则没必要继续搜索下去
					dfs(son,cur,son[i],res+cur-1);//感染人数=当前层感染人数+下一层子节点数-删除的一个点
		}
}

int main()
{
	cin>>n>>m;
	int cur=0;
	for(int i=1;i<=m;i++)//建立树节点关系
	{
		cin>>a>>b;
		if(a>b)//小的在前
			swap(a,b);
		map[a][b]=1;//连有向边
		if(a==1)	son[++cur]=b;//记录1(根)的子节点
	}
	for(int i=1;i<=cur;i++)
		dfs(son,cur,son[i],cur);
	cout<<ans<<endl;
	return 0;
}
     