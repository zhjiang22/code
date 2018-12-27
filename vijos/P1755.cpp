/*
一个很经典的dfs问题啦~
数独游戏而已~	只不过在找到一个可行解之后要统计一下分数来更新ans
但是如果直接裸的dfs的话会TLE部分点的
只能有80分(事实证明NOIP部分分太多了。。)
所以窝们可以稍微优化一下dfs啦~
首先这题肯定是可以用二进制位运算来做	但是窝比较懒啦
就没有用咯~也能很快出解
窝们只需要在搜索的时候加入一点贪心的思想
反正都是把整个数度填满
那我们为什么不从已经填了更多数字的地方开始填呢？
如果从一个最多的行开始填
那么只有更少的情况来填	及dfs树的分叉更多
然后窝们可以继续填填过第二少的行~
以此类推
事实证明效果是非常好的
可以很快时间出解(总时间从11037ms++到了1360ms)
具体实现的时候可以额外开一个结构体数据
里面记录行号和已经填了的个数
然后快排时就可以保存这个行号了
dfs时就从填的数最多的行(快排后的第一个行号)开始dfs
九宫格也很好处理~是一个小技巧可以学习一下~
涨姿势了~果然搜索也是要讲技巧哒~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=12;
const int n=9;
struct node
{
	int tot,idx;
}a[MAXN];
int p[MAXN][MAXN]= 
{
	{0,0,0,0,0,0,0,0,0,0,0},
	{0,6,6,6,6,6,6,6,6,6,0},
    {0,6,7,7,7,7,7,7,7,6,0},
    {0,6,7,8,8,8,8,8,7,6,0},
    {0,6,7,8,9,9,9,8,7,6,0},
    {0,6,7,8,9,10,9,8,7,6,0},
    {0,6,7,8,9,9,9,8,7,6,0},
    {0,6,7,8,8,8,8,8,7,6,0},
    {0,6,7,7,7,7,7,7,7,6,0},
    {0,6,6,6,6,6,6,6,6,6,0},
    {0,0,0,0,0,0,0,0,0,0,0}
};
int g[MAXN][MAXN];
bool line[MAXN][MAXN];
bool list[MAXN][MAXN];
bool fang[MAXN>>1][MAXN>>1][MAXN];
int ans=-1;

inline bool cmp(const node&a,const node&b){return a.tot>b.tot;}

void init()
{
	for(int i=1;i<=n;i++)
	{
		a[i].idx=i;
		for(int j=1;j<=n;j++)
		{
			cin>>g[i][j];
			if(g[i][j])
				a[i].tot++;
			line[i][g[i][j]]=1;	list[j][g[i][j]]=1;
			fang[(i-1)/3][(j-1)/3][g[i][j]]=1;
		}
	}
	sort(a+1,a+n+1,cmp);
}

int getans()
{
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum+=g[i][j]*p[i][j];
	return sum;
}

void dfs(int x,int y)
{
	if(x>9)
	{
		ans=max(ans,getans());
		return;
	}
	if(y>9)
		dfs(x+1,1);
	else	if(!g[a[x].idx][y])
	{
		int zx=(a[x].idx-1)/3;	int zy=(y-1)/3;
		for(int k=1;k<=9;k++)
			if(!line[a[x].idx][k]&&!list[y][k]&&!fang[zx][zy][k])
			{
				g[a[x].idx][y]=k;
				line[a[x].idx][k]=list[y][k]=fang[zx][zy][k]=1;
				dfs(x,y+1);
				g[a[x].idx][y]=0;
				line[a[x].idx][k]=list[y][k]=fang[zx][zy][k]=0;
			}
	}
	else
		dfs(x,y+1);
}

int main()
{
	init();
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}
     