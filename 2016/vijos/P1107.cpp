/*
树上最长链	和直径差不多叭
我就不多说了找了几个挺好的博客的
{
学习了一下求树的最长链的方法
最简单的思路就是两次dfs
两次dfs分别有什么用呢？
第一次dfs，求出某个任意的点能到达的最远的点
第二次dfs，从所搜到的最远的点倒搜回去.
为什么需要两次呢？
其实很容易想通第一遍dfs的起始点或许并不是最长链的起点
从最远的点倒搜到的最长的链就是所求的解
因为最长链一定经过这个最远的点啊...
这里注意题目表述：
假设任意的两个风景点都有且仅有一条路径（无回路）相连。
显然，任意一个风景点都可以作为游览路线的起点或者终点。
这里就保证了题目中只有一个连通块，也就是从可走的任意点开始第一遍dfs都是可行的
}
{
本题是一道简单求最长链问题，题解简单得只有一句话——两次搜索即可。但是怎么证明倒是一个需要想想的问题。
假设任意的两个风景点都有且仅有一条路径（无回路）相连。由此，本题求的就是两个叶子之间的最长链。
对于第一次搜，我们任选一个叶子A。然后找到离它最远的那一片叶子B，再做一次，找到max即可。
证明：
找到A，B后，可得A或B必为最长链的端点。易知不存在最长链CD与AB相交的情况（那样A不会搜索到B）。
假设存在最长链CD与A，B不接触则EB>EF+FD,FD>EF+EB.根据不等式的同向相加性质，EB+FD>EF+EF+EB+FD.所以2EF<0。
显然不符合题意。所以最长链必与A点，或B点相交。
综上所证，此题只需要做两次搜索就解决了。本人真心偷懒，做了个DFS，显然BFS更优。	
}
{
我采用的是两次 DFS 的方法，也就是任意取一个点开始 DFS，找到这次 DFS 时深度最深的点（也就是从所选点开始最长路径的终点），
然后从这一点（可以证明，这一点是最长路径的端点）开始再进行 DFS，这次 DFS 的深度就是要求的路径长度。
算法就是这样了，不过这个算法的正确性我一开始也不太确定，下面来证明一下：
设最长路径为 AB ，一开始任选的点为 P。取路径 PB 上的一点 Q，使得 AQ 与 PQ 只有一个公共点 Q（
也就是使得从 A 走到 Q 再走到 B 不会走回头路）。设 AQ=a，QB=b，QP=s，不妨设 a<b。
要证明这个算法的正确性，也就是要证明从 P 开始的最长路径的终点一定是 A 或 B。
假设从 P 开始的最长路径的终点是 C ，设 CP=c。
由假设知， c>s+b。由于从从 P 开始的最长路径的终点是 C，所以第二次 DFS 将从 C 开始，
所得最长路径为 CB=c+s+b>s+b+s+b，又因为 a<b，故CB>s+b+s+b>s+a+s+b>a+b=AB，这与 AB 是最长路径矛盾，
故假设不成立，命题得证。
时间复杂度 O(CR)，空间复杂度 O(CR)。
}
然后就这样了
我也比较懒
写个dfs滚粗了
一开始直接写了个所有点深搜结果发现sb了
OTZ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[MAXN][MAXN];
bool v[MAXN][MAXN];
int zx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int ans;
int maxx,maxy;

void init()
{
	cin>>m>>n;
	char ch;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='.')
				a[i][j]=1;
		}
}

void dfs(int x,int y,int w)
{
	if(w>ans)
	{
		ans=w;
		maxx=x;
		maxy=y;
	}
	for(int i=0;i<4;i++)
	{

		int newx=x+zx[i][0];	int newy=y+zx[i][1];
		if(a[newx][newy]&&!v[newx][newy])
		{
			v[newx][newy]=1;
			dfs(newx,newy,w+1);
			v[newx][newy]=0;
		}
	}
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j])
			{
				v[i][j]=1;
				dfs(i,j,0);
				v[i][j]=0;
				break;
			}
	v[maxx][maxy]=1;
	dfs(maxx,maxy,0);
	cout<<ans<<endl;
	return 0;
}
