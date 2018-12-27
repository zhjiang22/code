/*
一道很经典的搜索了~
lrj的书上也有类似的(0/1矩阵)
我们会发现
每一行的数字的状态改变会受到
本行,上一行,下一行影响
那么我们可以直接枚举第一行的操作
那么因为第一行没有上一行
所以第一行的翻转没能将本行翻转成黑色的地方
都要下面一行翻转
即枚举完第一行操作后
开始dfs第二行
那么第一行没有改变的格子
必然是要在第二行翻转
而且只能翻转正下方的
那么这就很简单了
以此类推每一行只能翻转上一行还是白的的格子的正下方的格子
这样的话其实第一行的操作已经决定了所有行的操作
只需要递推一下就好了！
这里我是用dfs完成的
同时每一行的操作可以用二进制来枚举表示
更加方便快捷~
同时输出顺序是要求翻转过来递增
其实就是第一行的操作递增
我们只需要在枚举第一行操作的时候递增枚举就好了
同时注意每枚举完一次都要先清零a[]和g[][]
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXM=23;
int g[MAXN][MAXM];
int a[MAXN];
int n,m;
int cnt;

void print()
{
	cnt++;
	if(cnt>10)
		return;
	cout<<cnt<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(a[i]&(1<<j))
				cout<<1<<" ";
			else
				cout<<0<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void change(int i,int j)
{
	g[i][j]^=1;
	if(j>0)	g[i][j-1]^=1;
	if(j<m-1)	g[i][j+1]^=1;
	if(i>0)	g[i-1][j]^=1;
	if(i<n)	g[i+1][j]^=1;
}

void upadate(int i)
{
	for(int j=0;j<m;j++)
		if((1<<j)&a[i])
			change(i,j);
}

void check()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!g[i][j])
				return;
	print();
}

void dfs(int cur)
{
	if(cur==n)
	{
		check();
		return;
	}
	else
	{
		for(int i=0;i<m;i++)
			if(!g[cur-1][i])
			{
				a[cur]|=(1<<i);
				change(cur,i);
			}
		dfs(cur+1);
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<(1<<m);i++)
	{
		memset(a,0,sizeof(a));
		memset(g,0,sizeof(g));
		a[0]=i;
		upadate(0);
		dfs(1);
	}
	cout<<cnt<<endl;
}
	
     