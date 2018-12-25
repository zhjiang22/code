#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=78;
const int MOD=1000007;
const int INF=(1<<30)-1;
struct node
{
	int x,y,step;
	int to;
	bool operator<(const node&b)const
	{
		return step>b.step;
	}
};
struct hashnode
{
	int x,y,step,to;
	int next;
};
int a[MAXN+2][MAXN+2];
int fisrt[50000];
int d[MAXN][MAXN][4];
hashnode Hash[MOD+2];
int zx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
queue<node> q;
int fx,fy,tx,ty;
int cnt,tot;
int n,m;
int htot;

void init()
{
	char ch;
	memset(a,0,sizeof(a));
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			if(ch=='X')
				a[i][j]=1;
			else
				a[i][j]=0;
		}
		getchar();
	}
	cnt=0;
	htot=0;
}

void hash_insert(int x,int y,int to)
{
	int h=(x+y+to)%MOD;
	htot++;
	Hash[htot].x=x;	Hash[htot].y=y;	Hash[htot].to=to;
	Hash[htot].next=fisrt[h];	fisrt[h]=htot;
}

bool hash_search(int x,int y,int to)
{
	int h=(x+y+to)%MOD;
	int cur=fisrt[h];
	while(cur!=-1)
	{
		if(Hash[cur].x==x&&Hash[cur].y==y&&Hash[cur].to==to)
			return 1;
		cur=Hash[cur].next;
	}
	return 0;
}

void out()
{
	cout<<"d"<<endl;
	while(!q.empty())
		q.pop();
	memset(fisrt,-1,sizeof(fisrt));
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			for(int k=0;k<=3;k++)
				d[i][j][k]=INF;
	q.push((node){fx,fy,1,0});
	q.push((node){fx,fy,1,1});
	q.push((node){fx,fy,1,2});
	q.push((node){fx,fy,1,3});
	//hash_insert(fx,fy,0);
	//hash_insert(fx,fy,1);
	//hash_insert(fx,fy,2);
	//hash_insert(fx,fy,3);
	while(!q.empty())
	{
		node u=q.front();	q.pop();
		int &x=u.x;	int &y=u.y;	int &step=u.step;	int &to=u.to;
		for(int i=0;i<4;i++)
		{
			int newx=x+zx[i][0];	int newy=y+zx[i][1];
			if(newx<0||newx>n+1||newy<0||newy>m+1)
				continue;
			if(!a[newx][newy])
			{
				if(i==to&&(d[newx][newy][to]=INF||step<d[newx][newy][to]))
				{
					q.push((node){newx,newy,step,to});
					d[newx][newy][to]=step;
				}
				else	if((d[newx][newy][i]=INF||step+1<d[newx][newy][i]))
				{
					q.push((node){newx,newy,step+1,i});
					d[newx][newy][i]=step+1;
				}
			}
		}
	}
	int ans=max(d[tx][ty][0],max(d[tx][ty][1],max(d[tx][ty][2],d[tx][ty][3])));
	cout<<d[tx][ty][0]<<" "<<d[tx][ty][1]<<" "<<d[tx][ty][2]<<" "<<d[tx][ty][3]<<endl;
	if(ans==0)
		printf("Pair %d: impossible.\n",++cnt);
	else
	{
		ans=min(d[tx][ty][0],min(d[tx][ty][1],min(d[tx][ty][2],d[tx][ty][3])));
		printf("Pair %d: %d segments.\n",++cnt,ans);
	}
}

int main()
{
	while(scanf("%d%d",&m,&n)==2)
	{
		if(n==0||m==0)
			break;
		printf("Board #%d:\n",++tot);
		init();
		while(scanf("%d%d%d%d",&fy,&fx,&ty,&tx)==4)
		{
			if(fx==0||fy==0||tx==0||ty==0)
				break;
			out();
		}
	}
	return 0;
}
     