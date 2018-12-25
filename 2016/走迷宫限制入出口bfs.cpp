#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int a[1000][1000];
int x1,x2,y1,y2;
int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
struct node
{
	int x,y,z;
};
queue<node>q;

void bfs()
{
	node p;
	node l;
	node mn={x1,y1,0};
	q.push(mn);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(p.x==x2&&p.y==y2)
		break;
		for(int i=0;i<4;i++)
		{
			int c=p.x+d[i][0];
	 		int v=p.y+d[i][1];
	 		if(a[c][v])
			{
				a[c][v]=0;
			l.x=p.x+d[i][0];
	 		l.y=p.y+d[i][1];
	 		l.z=p.z+1;
	 		q.push(l);
			}
		}
	}
	cout<<p.z;
}

int main()
{
	freopen("D:\\1.txt","r",stdin);
	int n,m;
	char ca;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>ca;
			if(ca=='S')
				{
				a[i][j]=6;
				x1=i;
				y1=j;
				}
			else if(ca=='T')
				{
				a[i][j]=7;
				x2=i;
				y2=j;
				}
			else if(ca=='#')
				a[i][j]=0;
			else a[i][j]=1;
		}	
	bfs();
	return 0;
}