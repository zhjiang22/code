#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

queue<int> q;
int in[100];
bool w[100][100];
int n,e;

void AOV()
{
	for(int i=1;i<=n;i++)
	if(in[i]==0)
	{
		q.push(i);
		in[i]=-1;
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(int i=1;i<=n;i++)
			if(w[x][i]&&in[i]!=-1)
				in[i]--;
		for(int i=1;i<=n;i++)
		if(in[i]==0)
		{
			q.push(i);
			in[i]=-1;
		}
	}
}

int main()
{
	cin>>n>>e;
	memset(w,false,sizeof(w));
	memset(in,0,sizeof(in));
	for(int i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		in[y]++;
		w[x][y]=true;
	}
	AOV();
	return 0;
}