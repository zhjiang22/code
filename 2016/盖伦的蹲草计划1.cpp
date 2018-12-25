#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int a[1600][1600];

struct node 
{
	int x,y;
};
queue<node> q;

int bfs(int x,int y)
{
	node p,z;
	int ans=1;
	p.x=x,p.y=y;
	q.push(p);
	while(q.size())
	{
		p.x=q.front().x;
		p.y=q.front().y;
		a[p.x][p.y]=0;
		q.pop();
		
		if(a[p.x-1][p.y])
		{
			ans++;
			z.x=p.x-1;
			z.y=p.y;
			q.push(z);
			a[z.x][z.y]=0;
		}		
		if(a[p.x+1][p.y])
		{
			ans++;
			z.x=p.x+1;
			z.y=p.y;
			q.push(z);
			a[z.x][z.y]=0;
		}
		if(a[p.x][p.y+1])
		{
			ans++;
			z.x=p.x;
			z.y=p.y+1;
			q.push(z);
			a[z.x][z.y]=0;
		}
		if(a[p.x][p.y-1])
		{
			ans++;
			z.x=p.x;
			z.y=p.y-1;
			q.push(z);
			a[z.x][z.y]=0;
		}
	}
	return ans;
}

int main()
{
	int mi=9999999999,ans=0;
	memset(a,0,sizeof(a));
	char x;
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			if(x=='*')
			a[i][j]=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(a[i][j])
		{
			int s3=bfs(i,j);
			ans+=s3;
			mi=min(mi,s3);
		}
		if(((ans-mi)*3)>=s)
		cout<<"Demacia Win!";
		else 
		cout<<"Demacia Lose!";
		return 0;
}