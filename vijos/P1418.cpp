/*
害怕OTZ
一开始没有看到{员工的编号会大于他的直接上司的编号}
然后傻逼了一波~
我们多叉树转二叉树(其实转不转都挺好做)
再定义f[i][j]表示从第i个节点向下花费j元能取得的最大兴奋指数
我们从根节点(1)向下dp
我们先递归求出左儿子和右兄弟的f[i][]
那么对于这个i点我们很容易有这样的决策
1.分k元到他的子节点去,剩下j-k元分到右兄弟(因为自己不能选了)
2.不给子节点，直接选自己和右兄弟
先考虑1
我们用O(m^2)的时间枚举j和k
然后很容易有转移式
f[i][j]=max(f[i][j],f[g[i][0]][k]+f[g[i][1]][j-k])
转移之后考虑2
我们可以直接看到如果选取了i点
那么对于一个f[i][j]剩下的j-v[i]都只能给它的右兄弟了
则有
f[i][j]=max(f[i][j],f[g[i][1]][j-v[i]]+w[i])
那么最终答案就是f[1][m]
好题~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1030;
const int MAXM=120;
int g[MAXN][2];
int f[MAXN][MAXM];
int w[MAXN],v[MAXN];
int n,m;

void init()
{
	scanf("%d%d",&n,&m);
	int fa;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&fa);
		g[i][1]=g[fa][0];
		g[fa][0]=i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
}

void dfs(int i)
{
	if(i==0)
		return;
	dfs(g[i][0]);	dfs(g[i][1]);
	for(int j=0;j<=m;j++)
		for(int k=0;k<=j;k++)
			f[i][j]=max(f[i][j],f[g[i][0]][k]+f[g[i][1]][j-k]);
	for(int j=m;j>=v[i];j--)//顺推逆推皆可
		f[i][j]=max(f[i][j],f[g[i][1]][j-v[i]]+w[i]);
}

int main()
{
	init();
	dfs(1);
	cout<<f[1][m]<<endl;
	return 0;
}