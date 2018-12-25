#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

struct node
{
	int index,low;
	node(int index=-1,int low=-1):index(index),low(low){}
}a[200];
int index=1;
int map[200][200];
int n,m;
int tot;
bool v[1000];
stack<int> s;//应该用下标做标志

void init()
{
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>x>>y,map[x][y]=1;
}

void Tarjan(int x)
{
	a[x].index=index;
	a[x].low=index++;
	s.push(x);
	v[x]=1;

	for(int i=1;i<=n;i++)
		if(map[x][i])
		{
			if(a[i].index==-1)
			{
				Tarjan(i);
				a[x].low=min(a[x].low,a[i].low);
			}
			else if(v[i])
				a[x].low=min(a[x].low,a[i].index);
		}
	if(a[x].index==a[x].low)
	{
		tot++;
		int l;
		do
		{
			l=s.top();
			v[l]=0;
			cout<<l<<endl;
			s.pop();
		}
		while(l!=x);
		cout<<endl;
	}
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		if(a[i].index==-1)
			Tarjan(i);
	cout<<tot<<endl;
	return 0;
}
     