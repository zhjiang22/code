/*
一个比较容易想到的搜索题了~
一开始竟然没看懂题目什么意思囧
QWQ看懂了其实很容易想到思路
首先我们看到n*m<=20000
那么如果是强一点的数据可能就有n=1 m=20000这种来卡数组
所以我们只能开一个一维数组然后再压缩
(听说vijos数据好水啊直接a[200][200]就能过?(出题人良心))
那么我们可以先对于女飞贼的位置处理一下
八个对角线在不经过障碍能打到女飞贼的位置标记一下
这样的话只要月如走到任意一个可以打到的位置女飞贼就死啦~
那这样很容易就转换成了一个成求bfs最短路的问题了
预处理的复杂度是O(n*m)我是直接用的dfs来做的方便
所以速度还是很快的
可以轻松秒杀~
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=20005;
struct point
{
	int x,y,step;
};
int zx[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int can[MAXN];
int v[MAXN];
int a[MAXN];
int n,m;
int x1,y1,x2,y2;

inline int ya(int& x,int& y)
{
	return x*m+y;
}

void init()
{
	char ch;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>ch;
			if(ch=='X')
				a[ya(i,j)]=1;
		}
}

void dfs(int x,int y,int k)
{
	can[ya(x,y)]=1;
	int newx=x+zx[k][0];	int newy=y+zx[k][1];
	if(newx<0||newx>=n||newy<0||newy>=m)
		return;
	if(!a[ya(newx,newy)])
		dfs(newx,newy,k);
}

int bfs()
{
	if(can[ya(x1,y1)])
		return 0;
	v[ya(x1,y1)]=1;
	queue<point> q;
	q.push((point){x1,y1,0});
	while(!q.empty())
	{
		point u=q.front();	q.pop();
		int& x=u.x;	int& y=u.y;	int& step=u.step;
		if(can[ya(x,y)])
			return step;
		for(int i=0;i<4;i++)
		{
			int newx=x+zx[i][0];	int newy=y+zx[i][1];
			int c=ya(newx,newy);
			if(newx<0||newx>=n||newy<0||newy>=m)
				continue;
			if(!a[c]&&!v[c])
			{
				v[c]=1;
				q.push((point){newx,newy,step+1});
			}
		}
	}
	return -1;
}

int main()
{
	init();
	while(scanf("%d%d%d%d",&x2,&y2,&x1,&y1)==4)
	{
		if(x1==0||y1==0||x2==0||y2==0)
			break;
		x1--;	y1--;	x2--;	y2--;
		memset(can,0,sizeof(can));
		memset(v,0,sizeof(v));
		for(int i=0;i<8;i++)
			dfs(x2,y2,i);
		int c=bfs();
		if(c==-1)
			printf("Impossible!\n");
		else
			printf("%d\n",c);
	}
}
     