/*
一道树形dp，因为每门课的先修课最多只有一节，则说明这是个树结构
对于读入的边，我们先将多叉树建立成二叉树
原则是左儿子右兄弟
然后再定义状态f表示以i课程为父亲结点的子树上选j门课程的最多学分
则有状态转移方程
f[i][j]=max(f[left][j-k-1]+f[right][k]+score[i](0<=k<=j-1),f[right][j])
方程含义：1、取当前i节点，则剩下的j-1们课程，在孩子中选j-k-1门，在兄弟中选k门。
          2、不取当前节点，则只能在兄弟中选j门。
k用来表示的是分别分配在某个节点上的左右子树的选择课程树
注意还有个f[right][j]即表示不选这门课程而选择它的右兄弟
原理上两种情况是根本上相同可合并的但是实际实现中没有那么方便
所以我们可以自顶向下用dfs进行树的遍历递归求解
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=305;
struct node
{
	int l,r,v;
}tree[maxn];
int n,m;
int f[maxn][maxn];

int dfs(int x,int y)
{
	if(!y||x<0)
		return 0;
	if(!x)
		return dfs(tree[x].l,y);
	if(f[x][y])
		return f[x][y];
	f[x][y]=dfs(tree[x].r,y);
	for(int i=0;i<y;i++)
		f[x][y]=max(f[x][y],dfs(tree[x].l,i)+tree[x].v+dfs(tree[x].r,y-i-1));
	return f[x][y];
}

int main()
{
	memset(tree,-1,sizeof(tree));
	cin>>n>>m;
	int fa,v;
	for(int i=1;i<=n;i++)
	{
		cin>>fa>>v;
		tree[i].r=tree[fa].l;
		tree[fa].l=i;
		tree[i].v=v;
	}
	cout<<dfs(0,m)<<endl;//0表示入口，0的子节点表示第一层
	return 0;
}
