/*
一道很明显的bfs咯
注意题目~
{
机器人的形状是一个直径1.6的球
机器人的中心总是在格点上
}
所以机器人是占2*2的格子的
所以建图要重新建立一下这个稍微需要注意一下
还要判断一下起点终点重合的情况
直接裸的bfs+三维v[][][]判重
一个状态对应的表现有横坐标x,纵坐标y,面向z
那么一个单位时间内可以做的有
前进1,2,3个方向(这个我们可以在扩展坐标的时候加上一个*1...2...3)
左转右转两个操作
我们就可以直接写一下
纯粹考验码力了
很傻的在检验是否到达终点的时候
返回的step忘记+1惹
然后调了半天
QWQ细心细心再细心
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=55;
struct node
{
	int x,y,to,step;
};
queue<node> q;
bool v[MAXN][MAXN][5];
int a[MAXN][MAXN];
int n,m;
int sx,sy,tx,ty;
int zx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

void init()
{
	int g[MAXN][MAXN];
	char ch;
	int k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>g[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j]||g[i+1][j+1]||g[i+1][j]||g[i][j+1])
				a[i][j]=1;
	cin>>sx>>sy>>tx>>ty;
	cin>>ch;
	if(ch=='N')
		k=0;
	else	if(ch=='E')
		k=1;

	else	if(ch=='S')
		k=2;
	else
		k=3;
	q.push((node){sx,sy,k,0});
	v[sx][sy][k]=1;
}

int bfs()
{
	if(a[sx][sy]||a[tx][ty])
		return -1;
	if(sx==tx&&sy==ty)
		return 0;
	while(!q.empty())
	{
		node k=q.front();	q.pop();
		int x=k.x;	int y=k.y;	int to=k.to;	int step=k.step;
		for(int i=1;i<=3;i++)
		{
			int newx=x+zx[to][0]*i;
			int newy=y+zx[to][1]*i;
			if(newx<1||newx>n||newy<1||newy>m)
				continue;
			if(a[newx][newy])
				break;
			if(!v[newx][newy][to])
			{
				v[newx][newy][to]=1;
				q.push((node){newx,newy,to,step+1});
				if(newx==tx&&newy==ty)
					return step+1;
			}
		}
		for(int i=1;i<=3;i+=2)
		{
			int newto=(to+i)%4;
			if(!v[x][y][newto])
			{
				v[x][y][newto]=1;
				q.push((node){x,y,newto,step+1});
			}
		}
	}
	return -1;
}

int main()
{
	init();
	cout<<bfs()<<endl;
	return 0;
}
     