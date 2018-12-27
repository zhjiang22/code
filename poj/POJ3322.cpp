#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN=505;
struct PK
{
	int x,y;
	int lie;//lie==0 is zhile  1 is hengfang  2 is shufang
	int step;
	bool operator==(const PK& p)const
	{
		return p.x==x&&p.y==y&&p.lie==lie;
	}
};
bool vis[MAXN][MAXN][4];
int g[MAXN][MAXN];
int n,m;

void init()
{
	getchar();
	char ch;
	memset(vis,0,sizeof(vis));
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			if(ch=='.')
				g[i][j]=0;
			else	if(ch=='#')
				g[i][j]=-1;
			else	if(ch=='E')
				g[i][j]=1;
			else	if(ch=='X')
				g[i][j]=2;
			else	if(ch=='O')
				g[i][j]=3;
		}
		getchar();
	}
}

PK ed,st;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

inline bool valid(const int& x,const int& y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}

void pre_work()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j]==3)
			{
				ed.x=i;	ed.y=j;	ed.lie=0;
				g[i][j]=0;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(g[i][j]==2)
			{
				for(int k=0;k<4;k++)
				{
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(valid(nx,ny)&&g[nx][ny]==2)
					{
						st.x=min(i,nx);	st.y=min(j,ny);
						if(i==nx)
							st.lie=1;
						else
							st.lie=2;
						g[i][j]=g[nx][ny]=0;
						st.step=0;
						return;
					}
				}
				if(g[i][j])
				{
					st.x=i;	st.y=j;
					st.lie=0;
					g[i][j]=0;
					st.step=0;
				}
			}
}

queue<PK> q;
int change_x[3][4]={{0,0,-2,1},{0,0,-1,1},{0,0,-1,2}};
int change_y[3][4]={{1,-2,0,0},{2,-1,0,0},{1,-1,0,0}};
int next_lie[3][4]={{1,1,2,2},{0,0,1,1},{2,2,0,0}};

bool ok(const PK& now)
{
	if(!valid(now.x,now.y))
		return 0;
	if(now.lie==0)
		return g[now.x][now.y]==0;
	else	if(now.lie==1)
	{
		if(g[now.x][now.y]==-1||g[now.x][now.y+1]==-1)
			return 0;
		else	
			return 1;
	}
	else
	{
		if(g[now.x][now.y]==-1||g[now.x+1][now.y]==-1)
			return 0;
		else	
			return 1;
	}
}

void bfs()
{
	while(!q.empty())
		q.pop();
	q.push(st);
	vis[st.x][st.y][st.lie]=1;
	while(!q.empty())
	{
		PK now=q.front();	q.pop();
		PK to;
		for(int i=0;i<4;i++)
		{
			to.x=now.x+change_x[now.lie][i];
			to.y=now.y+change_y[now.lie][i];
			to.lie=next_lie[now.lie][i];
			if(!ok(to))
				continue;
			if(vis[to.x][to.y][to.lie])
				continue;
			vis[to.x][to.y][to.lie]=1;
			to.step=now.step+1;
			if(to==ed)
			{
				printf("%d\n",to.step);
				return;
			}
			q.push(to);
		}
	}
	printf("Impossible\n");
}

void work()
{
	pre_work();
	bfs();
}

int main()
{
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		init();
		work();
	}
	return 0;
}