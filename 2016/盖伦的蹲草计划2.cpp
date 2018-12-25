#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
bool m[2000][2000];
struct haha
{
	int x,y;
};
queue<haha> q;
int bfs(int x,int y)
{
	haha a,b;
	a.x=x;  a.y=y;
	q.push(a);
	int ans=1;
	while(q.size())
	{
		a.x=q.front().x;
		a.y=q.front().y;
		m[a.x][a.y]=0;
		q.pop();
		if(m[a.x-1][a.y])
		{
			ans++;
			b.x=a.x-1;
			b.y=a.y;
			q.push(b);
			m[b.x][b.y]=0;
		}
		if(m[a.x+1][a.y])
		{
			ans++;
			b.x=a.x+1;
			b.y=a.y;
			q.push(b);
			m[b.x][b.y]=0;	
		}
		if(m[a.x][a.y+1])
		{
			ans++;
			b.x=a.x;
			b.y=a.y+1;
			q.push(b);
			m[b.x][b.y]=0;	
		}
		if(m[a.x][a.y-1])
		{
			ans++;
			b.x=a.x;
			b.y=a.y-1;
			q.push(b);
			m[b.x][b.y]=0;	
		}
	}
	return ans;
}
int main()
{
	int a,b,c;
	char x;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	for(int j=1;j<=b;j++)
	{
		cin>>x;
		if(x=='*')
			m[i][j]=1;
	}
	int mi=2147483646;
	int s=0,anss=0;
	for(int i=1;i<=a;i++)
	for(int j=1;j<=b;j++)
	{
		if(m[i][j])
		{
			s=bfs(i,j);
			mi=min(mi,s);
			anss+=s;
		}
	}
	if(c<=(anss-mi)*3)
		cout<<"Demacia Win!";
	else
		cout<<"Demacia Lose!";
		return 0;
}
