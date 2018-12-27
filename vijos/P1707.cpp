/*
这题坑的可以啊
题目中有说
{
	每个单词可在矩阵中的任何位置朝着任何方向出现，且仅出现一次
}
然而事实证明不止出现一次啊
按照这个来做
最后一个点是过不了的
所以我们不能一找到一个合法的字符串位置就输出
而是应该取所有的k最小的情况~
这样就能A啦
还是蛮基础的题目的~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=110;
int zx[8][2]={{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0}};
char to[9]="DCBAHGFE";
char a[MAXN][MAXN];
string c;
int n,m,k;
int l;

void init()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
}

bool dfs(int x,int y,int k,int cur)
{
	if(cur==l)
		return 1;
	int newx=x+zx[k][0];	int newy=y+zx[k][1];

	if(a[newx][newy]==c[cur])
		return dfs(newx,newy,k,cur+1);
	else
		return 0;
}

void find()
{
	char p=c[0];	l=c.length();
	int mink=100;	int ansi=0,ansj=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==p)
				for(int k=0;k<8;k++)
					if(dfs(i,j,k,1))
					{
						if(k<mink)
						{
							mink=k;	ansi=i;	ansj=j;
						}			
					}
	cout<<ansi<<" "<<ansj<<" "<<to[mink]<<endl;
}

void work()
{
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		find();
	}
}

int main()
{
	init();
	work();
	return 0;
}
     