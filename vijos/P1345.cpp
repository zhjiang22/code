/*
数独问题用DLX和还是必然更快的
但是搜索算法应该勉强也就够用了吧~
这里我用的是搜索算法
只是加了一个小小的优化
即每次从已有数字多到少一行一行搜索
和NOIP靶形数独是一样哒~
唯一不同就是这里找到一个唯一解就可以直接连环return
而且不用计算分值啦~
记得要每次数独要初始化~
果然每次搜更多的行速度明显提高
试验了一下虽然都可以直接AC
但是时间可以从4500ms优化到1200ms
效率很明显提高了很多~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10;
struct node
{
	int idx,tot;
	bool operator<(const node& b)const
	{
		return tot>b.tot;
	}
}a[MAXN];
int g[MAXN][MAXN];
bool line[MAXN][MAXN];
bool list[MAXN][MAXN];
bool gong[MAXN>>1][MAXN>>1][MAXN];
int n=9;
int T;

void print()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
					cout<<g[i][j];
	cout<<endl;
}

void init()
{
	memset(g,0,sizeof(g));
	memset(line,0,sizeof(line));
	memset(list,0,sizeof(list));
	memset(gong,0,sizeof(gong));
	for(int i=1;i<=n;i++)
	{
		a[i].idx=i;	a[i].tot=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%01d",&g[i][j]);
			if(g[i][j])
			{
				line[i][g[i][j]]=1;	list[j][g[i][j]]=1;
				gong[(i-1)/3][(j-1)/3][g[i][j]]=1;
				a[i].tot++;
			}
		}
	}
}

bool dfs(int cur,int y)
{
	if(cur==n+1)
	{
		print();
		return 1;
	}
	int& x=a[cur].idx;
	if(g[x][y])
	{
		if(y==n)
		{
			if(dfs(cur+1,1))
				return 1;
		}
		else	if(dfs(cur,y+1))
			return 1;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(!line[x][i]&&!list[y][i]&&!gong[(x-1)/3][(y-1)/3][i])
		{
			line[x][i]=1;	list[y][i]=1;
			gong[(x-1)/3][(y-1)/3][i]=1;	g[x][y]=i;
			if(y==n)
			{
				if(dfs(cur+1,1))
					return 1;
			}
			else	if(dfs(cur,y+1))
				return 1;
			line[x][i]=0;	list[y][i]=0;
			gong[(x-1)/3][(y-1)/3][i]=0;	g[x][y]=0;
		}
	return 0;
}

void work()
{
	sort(a+1,a+n+1);
	dfs(1,1);
}

int main()
{
	cin>>T;
	while(T--)
	{
		init();
		work();
	}
	return 0;
}
     