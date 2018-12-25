#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
z
int a[100][100];
int visit[100];
int n,e;
queue<int> q;

void bfs(int cur)
{	
  	q.push(cur);
	visit[cur]=1;
	while(!q.empty())
	{
	cout<<q.front();
	q.pop();
	for(int i=1;i<=n;i++)
	if(a[cur][i]&&!visit[i])
	q.push(i);
	}
}

int main()
{
	memset(a,0,sizeof(a));
	memset(visit,0,sizeof(visit));
	cin>>n>>e;
	int x,y;
	for(int i=1;i<=e;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
	}	
	bfs(1);
	return 0;
}