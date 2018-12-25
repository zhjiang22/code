#include<iostream>
#include <cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

struct node
{
	int x,y;
	int color;
}q[100];
int cost=0;
int d[102];
int v[102];
int f[500][500];
int vexn=0,color=0;
int w[52][52];
int n,m,road=0;
int z[8][2]={{1,0},{0,1},{-1,0},{0,-1},{-1,1},{1,1},{-1,-1},{1,-1}};

void bfs(int x,int y)
{
	int rear=vexn+1,head=vexn;
	q[head].x=x;
	q[head].y=y;
	q[head].color=color;

	while(head<rear)
	{
		for(int i=0;i<8;i++)
		{
			int newx=q[head].x+z[i][0];
			int newy=q[head].y+z[i][1];
			if(newx>=1&&newx<=n&&newy>=1&&newy<=m&&w[newx][newy])
			{
				q[rear].x=newx;
				q[rear].y=newy;
				q[rear].color=color;
				rear++;
				w[newx][newy]=0;
			}
		}
		head++;
	}
	vexn=rear;
}

void Prim(int s)
{

	for(int i=1;i<=n;i++)
		d[i]=w[s][i],v[i]=1;
	d[s]=0;
	for(int i=2;i<=n;i++)
	{	
		int Min=INF,p;
		for(int j=2;j<=n;j++)
			if(v[j]&&d[j]<Min)
			{
				Min=d[j];
				p=j;
			}
		v[p]=0;
		cost+=Min;
		d[p]=0;
		for(int j=2;j<=n;j++)
			if(w[p][j]<d[j])
				d[j]=w[p][j];
	}

}

int main()
{
	cin>>n>>m;
	char xz;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>xz;
			if(xz=='#')
				w[i][j]=1;
			else 
				w[i][j]=0;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(w[i][j])
				++color,bfs(i,j);
	for(int i=1;i<=vexn;i++)
			for(int j=i;j<=vexn;j++)
			{
				int d;
				if(q[i].color!=q[j].color)
				{
					int dx=abs(q[i].x-q[j].x);
					int dy=abs(q[i].y-q[j].y);
					if(dx>1&&dy>1)	continue;
					if(dx<=1)	d=dy-1;
					else	d=dx-1;
					if(d<f[q[i].color][q[j].color])
						f[q[i].color][q[j].color]=d,
						f[q[j].color][q[i].color]=d,
						road++;
				}
			}
	if(!road)
	{
		cout<<color<<endl<<"0 0";
		return 0;
	}
	Prim(1);
	cout<<color<<endl;
	cout<<road-1<<" "<<cost;
	return 0;
}