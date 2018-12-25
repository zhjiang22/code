#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=205;
struct node
{
	int x,y,step;
	int s;
};
struct point
{
	int x,y;
};
queue<node> q;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
vector<point> cv;
int n,m;
int tot;
int T;
int zx[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
node s,t;

void init()
{
	cin>>n>>m>>tot;
	cv.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='$')
			{
				cv.push_back((point){i,j});
			}
			else	if(a[i][j]=='S')
				s.x=i,s.y=j;
			else	if(a[i][j]=='E')
				a[i][j]='.',t.x=i,t.y=j;
		}
	memset(vis,0,sizeof(vis));
}

bool check(node q)
{
	int cnt=0;
	for(int i=0;i<=4;i++)
	{
		if((q.s>>i)&1)
			cnt++;
	}
	return cnt>=tot;
}

int bfs()
{
	while(!q.empty())
		q.pop();
	q.push(s);
	while(!q.empty())
	{
		node now=q.front();	q.pop();
		int &x=now.x,&y=now.y,&step=now.step,&s=now.s;
		if(x==t.x&&y==t.y&&check(now))
			return step;
		for(int i=0;i<4;i++)
		{
			int newx=x+zx[i][0];	int newy=y+zx[i][1];
			if(newx>n||newy>m||newx<1||newy<1)
				continue;
			if(1)
			{
				if(a[newx][newy]=='.'&&!vis[newx][newy][s])
				{
					q.push((node){newx,newy,step+1,s});
					vis[newx][newy][s]=1;
				}
				else	if(a[newx][newy]=='$')
				{
					for(int i=0;i<cv.size();i++)
					{
						int p1=cv[i].x;	int p2=cv[i].y;
						if(!vis[p1][p2][s])
						{
							q.push((node){p1,p2,step+1,s});
							vis[p1][p2][s]=1;
						}
					}
				}
				else	if(a[newx][newy]<='4'&&a[newx][newy]>='0')
				{
					int news=s|(1<<(a[newx][newy]-'0'));
					if(!vis[newx][newy][news])
					{
						q.push((node){newx,newy,step+1,news});
						vis[newx][newy][news]=1;
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin>>T;
	while(T--)
	{
		init();
		int ans=bfs();
		if(ans==-1)
			cout<<"oop!"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
     