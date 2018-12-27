/*
好题好题~真心精妙呀~
第一眼看到这道题是懵逼的根本不知道怎么查询
后来还是想到了拓扑排序但还是不会写
最后看了一下题解~恍然大悟
窝们可以这样做
首先因为每个字母矩形顶角都一定是有的
所以我们可以先求出左上和右下角两个顶角~
然后就可以确定下这个矩形的形状了
然后窝们沿着四条边扫描一遍
如果有一个字母c在当前字母k矩阵上面
那么说明c一定是在k上面的
那么肯定有在输出顺序中c要在k后面
等等这让窝们想到了什么
有了确定的x在y前面这样的关系	要找到有可能的情况排列
这不就是拓扑排序~！？
没错我们可以对于满足(c,k)这样条件的两个顶点
从k到c连一条有向边
那么很容易就变成一个求所有拓扑序列的问题了
因为序列要从小到大字典序
而且要输出全部的情况
所以我们考虑dfs即可
dfs还是蛮好写的一个递归然后出口维护还原一下全局变量就好了
即从小到大考虑一个入读为0的点
然后把他删除作为第一个	自然要将他的所有出边对应顶点的入度--
然后继续递归下去~
直到找到了一个完整排列(记得统计一下字母个数就好了)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=32;
char a[MAXN][MAXN];
char ans[MAXN];
int g[MAXN][MAXN];
int in[MAXN];
int h[MAXN];
int n,m;
int cnt;

void dfs(int cur)
{
	if(cur==cnt)
	{
		printf("%s\n",ans);
		return;
	}
	for(int i=0;i<26;i++)
		if(!in[i]&&h[i])
		{
			ans[cur]=i+'A';
			in[i]=-1;
			for(int j=0;j<26;j++)
				if(g[i][j])
					in[j]--;
			dfs(cur+1);
			in[i]=0;
			for(int j=0;j<26;j++)
				if(g[i][j])
					in[j]++;
		}
}

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int k=0;k<26;k++)
	{
		char ch='A'+k;	
		int x1=MAXN;	int y1=MAXN;	int x2=0;	int y2=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]==ch)
					x1=min(x1,i),y1=min(y1,j),
					x2=max(x2,i),y2=max(y2,j);
		if(x1==MAXN||y1==MAXN||x2==0||y2==0)
			continue;
		h[k]=1;
		cnt++;
		for(int i=x1;i<=x2;i++)
			for(int j=y1;j<=y2;j++)
				if(i==x1||i==x2||j==y1||j==y2)
					if(a[i][j]!=ch&&a[i][j]!='.')
					{
						int c=a[i][j]-'A';
						if(!g[k][c])
						{
							g[k][c]=1;
							in[c]++;
						}
					}
	}
	ans[cnt]='\0';
}

int main()
{
	init();
	dfs(0);
	return 0;
}
     