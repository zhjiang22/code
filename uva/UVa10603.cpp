#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

char rd;	int pn;
template<typename Type>
inline void read(Type& v)
{
	pn=1;
	while((rd=getchar())<'0'||rd>'9')
		if(rd=='-')
			pn=-1;
	v=rd-'0';
	while((rd=getchar())>='0'&&rd<='9')
		v=v*10+rd-'0';
	v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1)
{
	if(v==0)
		putchar(48);
	else  
    {
    	if(v<0)
    	{
    		putchar('-');
    		v=-v;
    	}
    	int len=0,dg[20];  
    	while(v>0)
    	{
    		dg[++len]=v%10;
    		v/=10;
    	}  
    	for(int i=len;i>=1;i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}

struct point
{
	int v[3];
	int dist;
	bool operator<(const point& p)const
	{
		return dist>p.dist;
	}
	point(int a,int b,int c,int d)
	{
		v[0]=a;	v[1]=b;	v[2]=c;
		dist=d;
	}
};

const int MAXN=205;
int T,n;
int cap[4];
int a,b,c,d;
priority_queue<point> q;
bool vis[MAXN][MAXN];
int ans[MAXN];

void init()
{
	read(a);	read(b);
	read(c);	read(d);
	cap[0]=a;	cap[1]=b;	cap[2]=c;
	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));
	while(!q.empty())
		q.pop();
}

void change(point u)
{
	for(int i=0;i<3;i++)
	{
		int& d=u.v[i];
		if(ans[d]==-1||u.dist<ans[d])
			ans[d]=u.dist;
	}
}

void update(point u,int i,int j)//从i向j倒水
{
	if(u.v[j]==cap[j])//j满
		return;
	if(u.v[i]==0)//i空
		return;
	int amount=min(u.v[i]+u.v[j],cap[j])-u.v[j];
	//将j瓶倒满如果i瓶水不够则将i倒空
	point v(u.v[0],u.v[1],u.v[2],u.dist);
	v.dist+=amount;
	v.v[i]-=amount;
	v.v[j]+=amount;
	if(!vis[v.v[0]][v.v[1]])
	{
		vis[v.v[0]][v.v[1]]=1;
		q.push(v);
	}
}

void work()
{
	point s(0,0,c,0);
	q.push(s);
	vis[0][0]=1;
	while(!q.empty())
	{
		point u=q.top();	q.pop();
		change(u);
		if(ans[d]>=0)
			break;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(i!=j)
					update(u,i,j);//状态图的扩展
	}
	while(d>=0)
		if(ans[d]>=0)
		{
			printf("%d %d\n",ans[d],d);
			break;
		}
		else
			d--;
}

int main()
{
	read(T);
	while(T--)
	{
		init();
		work();
	}
	return 0;
}
