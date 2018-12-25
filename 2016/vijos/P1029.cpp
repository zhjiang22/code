/*
看到这题	可能第一思路就是
对于输入的每一个数据	我们跑一边bfs找出最短操作
先不说时间复杂度	我们的目标序列有八个(手算一下就知道了)
就算是判断到达也麻烦啊虽然可以函数解决
有没有更好更快捷的方法呢？
当然是有的
我们发现其实把这个矩阵按顺序展开之后
其实就是一个1-9的全排列
所以所有的情况也不是非常多(9!=362880种)
那么与其在线查找我们不如离线查找
所以我们可以直接将八个目标状态丢进队列中
让他扩展完将所有情况的最小距离的找出来
然后读入之后直接查找就好了
这样我们只要手写一个数组模拟链表hash就好了
还是蛮简单的~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=4;
const int MOD=30000007;
struct node
{
	int x;
	int step;
	int nxt;
};
queue<node> q;
node Hash[MOD+1];
int g[MAXN][MAXN];
int first[MOD+1];
int step=-1,tot;

int Hash_search(int x)
{
	int p=x%MOD;
	for(int i=first[p];i!=-1;i=Hash[i].nxt)
		if(Hash[i].x==x)
			return Hash[i].step;
	return -1;
}

void Hash_insert(int x)
{
	int p=x%MOD;
	tot++;	Hash[tot].x=x;	Hash[tot].step=step+1;
	Hash[tot].nxt=first[p];	first[p]=tot;
	q.push(Hash[tot]);
}

void init()
{
	q.push((node){816357492,0,-1});q.push((node){438951276,0,-1});
	q.push((node){294753618,0,-1});q.push((node){672159834,0,-1});
	q.push((node){618753294,0,-1});q.push((node){276951438,0,-1});
	q.push((node){492357816,0,-1});q.push((node){834159672,0,-1});
	memset(first,-1,sizeof(first));
	Hash_insert(816357492);	Hash_insert(438951276);
	Hash_insert(294753618);	Hash_insert(672159834);
	Hash_insert(618753294);	Hash_insert(276951438);
	Hash_insert(492357816);	Hash_insert(834159672);
}

int yait()
{
	int ans=0;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			ans=ans*10+g[i][j];
	return ans;
}

void doit(int x)
{
	for(int i=3;i>0;i--)
		for(int j=3;j>0;j--)
		{
			g[i][j]=x%10;
			x/=10;
		}
}

void work(int x1,int y1,int x2,int y2)
{
	swap(g[x1][y1],g[x2][y2]);
	if(Hash_search(yait())==-1)
		Hash_insert(yait());
	swap(g[x1][y1],g[x2][y2]);
}

void bfs()
{
	while(!q.empty())
	{
		node u=q.front();	q.pop();
		doit(u.x);	step=u.step;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				if(i!=3)
					work(i,j,i+1,j);
				if(j!=3)
					work(i,j,i,j+1);
			}
	}
}

void out()
{
	int ans,x;
	while(scanf("%d",&ans)==1)
	{
		for(int i=1;i<=8;i++)
		{
			cin>>x;
			ans=(ans*10)+x;
		}
		cout<<Hash_search(ans)<<endl;
	}
}

int main()
{
	init();
	bfs();
	out();
	return 0;
}
     