#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

struct node
{
	int index,low;
}a[100];
bool map[100][100];
bool v[100];
int n,m,index;
int Count;
stack<int> s;

void Tarjan(int x)
{
	a[x].index=++index;
	a[x].low=index;
	s.push(x);
	v[x]=1;
	
	for(int i=1;i<=n;i++)
		if(map[x][i])
		{
			if(a[i].index==0)
			{
				Tarjan(i);
				a[x].low=min(a[x].low,a[i].low);
			}
			else	if(v[i])
				a[x].low=min(a[x].low,a[i].index);
		}

	if(a[x].index==a[x].low)
	{
		int k;
		Count++;
		do
		{
			k=s.top();
			v[k]=0;
			cout<<k<<endl;
			s.pop();
		}
		while(k!=x);
		cout<<endl;
	}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		map[x][y]=1;
	}
	for(int i=1;i<=n;i++)
		if(a[i].index==0)
			Tarjan(i);
	cout<<Count<<endl;
	return 0;
}
     