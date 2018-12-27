#include <bits/stdc++.h>
using namespace std;

const int MAXN=805;
struct Point
{
	int x,y,step;
};
int boycan[MAXN][MAXN];
int girlcan[MAXN][MAXN];
int g[MAXN][MAXN];
int n,m;
int T;
Point s,t;
Point z[2];
int Time;

void init()
{
	memset(boycan,0,sizeof(boycan));
	memset(girlcan,0,sizeof(girlcan));
	cin>>n>>m;
	getchar();
	char ch;
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			if(ch=='.')
				g[i][j]=1;
			else	if(ch=='X')
				g[i][j]=-1;
			else	if(ch=='M')
				s.x=i,s.y=j;
			else	if(ch=='G')
				t.x=i,t.y=j;
			else
				z[cur].x=i,z[cur++].y=j;
		}
		getchar();
	}
}

queue<Point> boyq;
queue<Point> girlq;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

inline bool valid(const int& x,const int& y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}

bool bfs_boy()
{
	while(!boyq.empty())
	{
		if(boyq.front().step>Time*3)
		{
			//cout<<endl;
			return 0;
		}
		Point now=boyq.front();	boyq.pop();
		int& x=now.x;	int& y=now.y;
		int& step=now.step;
		//cout<<x<<" "<<y<<" "<<step<<endl;
		if(step==3*Time)
			boycan[x][y]=Time;
		else
			boycan[x][y]=-1;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];	int ny=y+dy[i];
			if(!valid(nx,ny)||boycan[nx][ny]||g[nx][ny]==-1)
				continue;
			bool ok=1;
			for(int k=0;k<2;k++)
				if(abs(z[k].x-nx)+abs(z[k].y-ny)<2*(Time+1))
					ok=0;
			if(!ok)
				continue;
			boyq.push((Point){nx,ny,step+1});		
		}
	}
	return 0;
}

bool bfs_girl()
{
	while(!girlq.empty())
	{
		if(girlq.front().step>Time)
			return 0;
		Point now=girlq.front();	girlq.pop();
		int& x=now.x;	int& y=now.y;
		int& step=now.step;
		girlcan[x][y]=Time;
		if(boycan[x][y]==Time)
		{r
			//cout<<x<<" "<<y<<endl;
			return 1;
		}
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];	int ny=y+dy[i];
			if(!valid(nx,ny)||girlcan[nx][ny]||g[nx][ny]==-1)
				continue;
			bool ok=1;
			for(int k=0;k<2;k++)
				if(abs(z[k].x-nx)+abs(z[k].y-ny)<2*(Time+1))
					ok=0;
			if(!ok)
				continue;
			girlq.push((Point){nx,ny,step+1});
		}
	}
	return 0;
}

void work()
{
	while(!boyq.empty())
		boyq.pop();
	while(!girlq.empty())
		girlq.pop();
	boycan[s.x][s.y]=1;
	girlcan[t.x][t.y]=1;
	boyq.push(s);	girlq.push(t);
	for(Time=1;Time<=n*m;Time++)
	{
		if(bfs_boy())
		{
			cout<<Time<<endl;
			return;
		}
		if(bfs_girl())
		{
			cout<<Time<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}

int main()
{
	cin>>T;
	while(T--)
	{
		init();
		work();
	}
	return 0;
}