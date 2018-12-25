#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
const int INF=0x7fffff;
struct Edge
{
	int to,w,next;
	Edge()
	{
		to=next=-1;
		w=0;
	}
}e[MAXN<<1];
int fisrt[100];
int d[100];
int q[100];
bool inq[100];
int m,tot;
int front,rear;

inline int wap(char x)
{
	if(x<='Z'&&x>='A')
		return x-'A'+1;
	else
		return x-'a'+27;
}

inline void Add_Edge(int x,int y,int w)
{
	tot++;
	e[tot].to=y;	e[tot].w=w;
	e[tot].next=fisrt[x];	fisrt[x]=tot;
}

void init()
{
	char x,y;
	int w;
	memset(fisrt,-1,sizeof(fisrt));
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		int xx=wap(x);	int yy=wap(y);
		Add_Edge(xx,yy,w);
		Add_Edge(yy,xx,w);
	}
	for(int i=1;i<=52;i++)
		d[i]=INF;
}

void SPFA(int s)
{
	int ans=INF;	int cur=-1;
	d[s]=0;	inq[s]=1;	q[rear++]=s;
	while(front!=rear)
	{
		int x=q[front];	front=(front+1)%99;
		inq[x]=0;
		for(int i=fisrt[x];i!=-1;i=e[i].next)
		{
			int &to=e[i].to;	int &w=e[i].w;
			if(d[to]>d[x]+w)
			{
				d[to]=d[x]+w;
				if(!inq[to])
				{
					inq[to]=1;
					q[rear++]=to;	rear%=99;
				}
			}
		}
	}
	for(int i=1;i<=26;i++)
		if(i!=26&&d[i]<ans)
			ans=d[i],cur=i;
	cout<<(char)(cur+'A'-1)<<" "<<ans<<endl;
}

int main()
{
	init();
	SPFA(wap('Z'));
	return 0;
}
     