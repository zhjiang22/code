#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

struct node
{
	int t[16];
	int step;
	int a,b,c,d;
	node(int *x,int p)
	{
		a=b=c=d=-1;
		memcpy(t,x,sizeof(int)*16);
		step=p;
	}
};
queue<int> q;
set<int> s;
int start[16];
int to[16];

void get()
{
	for(int i=0;i<=15;i++)
	{
		start[i]=getchar()-'0';
		if(start[i]==-38)
			i--;
	}
	for(int i=0;i<=15;i++)
	{
		to[i]=getchar()-'0';
		if(to[i]==-38)
			i--;
	}
}

void bfs()
{
	node x(start,0);
	q.push(x);
	while(!q.empty())
	{
		
	}
}

int main()
{
	get();
	bfs();
}
     