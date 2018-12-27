/*
一道很经典的bfs了吧~
dfs也可以做但是bfs更优一些~
我们看到这个题目是对于多个状态计算六步之内能否到达全1状态
n可以达到500
那么我们如果对于读入的五百个数据
每次都bfs找到全1的最短路
这样其实是肯定会有很多重复计算的
这样效率必然很低！
那么我们可以逆向思维
和P1029一样的利用离线查找
从全1状态开始逆推6步
再将这些状态全部储存下来~
这样就可以对于读入的500个数据直接查表出解~
效率高了很多s
位运算的一些细节就不多说了
关键是反转的change函数要注意一些细节了~
还是很简单的~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=33554435;
int ans[MAXN];
int n;
int s,t=(1<<25)-1;

void work()
{
	string a;
	s=0;
	for(int i=0;i<5;i++)
	{
		cin>>a;
		for(int j=0;j<5;j++)
			if(a[j]=='1')
				s|=(1<<(i*5+j));
	}
	cout<<ans[s]<<endl;
}

int change(int x,int p)
{
	x^=(1<<p);
	if(p>=5)		x^=(1<<(p-5));
	if(p<20)	x^=(1<<(p+5));
	if(p%5)		x^=(1<<(p-1));
	if(p%5!=4)	x^=(1<<(p+1));
	return x;
}

void bfs()
{
	memset(ans,-1,sizeof(ans));
	queue<int> q;
	q.push(t);	ans[t]=0;
	int p;
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		if(ans[u]>=6)
			return;
		for(int i=0;i<25;i++)
		{
			p=change(u,i);
			if(ans[p]==-1)
			{
				q.push(p);
				ans[p]=ans[u]+1;
			}
		}
	}
	return;
}

int main()
{
	scanf("%d",&n);
	bfs();
	while(n--)
		work();
}
     