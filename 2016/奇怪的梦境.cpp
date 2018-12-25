#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

bool map[10005][10005];
int in[10005];
int n,m,ans;
queue<int> q;
stack<int> s;

void topsort()
{
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i),in[i]=-1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		s.push(x);
		for(int i=1;i<=n;i++)
			if(map[x][i]&&in[i]!=-1)
				in[i]--;
		for(int i=1;i<=n;i++)
			if(in[i]==0)
			{
				in[i]=-1;
				q.push(i);
			}
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
		in[y]++;
	}
	topsort();
	int p=s.size();
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}
     