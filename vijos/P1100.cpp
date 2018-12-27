/*
一道披着树形dp的区间dp666666
我们可以用记忆化递归搜索来动态规划一下
我们知道因为该二叉树的中序遍历为1....n
根节点的选取其实有无数种情况
那我们就递归枚举所有可能的根节点比较所能得到的最大值
我们设f[i][j]表示i结点到j结点的加分二叉树所能达到的最大加分值
root[i][j]=k表示该最大加分值是在根节点为k的时候达到的
那么我们就可以得到下面的状态转移方程
f[i][j]=max(f[i][k-1]*f[k+1][j]+d[k],i<=k<=j)
注意边界子树为空时加分值为1
那么我们就记忆化搜索一下就好了
再来考虑一下输出，要输出前序遍历
那么我们想一下怎么输出前序遍历？
对于f[1][n]找到其最优解的时候的根节点root[1][n]
然后再根据这个根节点将树分成二叉树，然后再递归找到根节点输出
边界是子树为空的时候~
问题就解决了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[31];
int f[31][31];
int root[31][31];

int dfs(int l,int r)
{
	int ans=-1;
	int node=-1;
	if(f[l][r]!=-1)
		return f[l][r];
	else	if(l>r)
		return f[l][r]=1;
	else	if(l==r)
	{
		root[l][r]=l;
		return f[l][r]=a[l];
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			int temp=dfs(l,i-1)*dfs(i+1,r)+a[i];
			if(ans<temp)
			{
				ans=temp;
				node=i;
			}
		}
	}
	root[l][r]=node;
	return f[l][r]=ans;
}

void print(int l,int r)
{
	if(l<=r)
	{
		cout<<root[l][r]<<" ";
		print(l,root[l][r]-1);
		print(root[l][r]+1,r);
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(f,-1,sizeof(f));
	memset(root,-1,sizeof(root));
	dfs(1,n);
	cout<<f[1][n]<<endl;
	print(1,n);
	return 0;
}
     