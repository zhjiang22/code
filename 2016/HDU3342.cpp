#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

#define _rep(i,a,b)	for(int i=(a);i<=(b);i++)
const int MAXN=105;
struct Edge
{
	int to,nxt;
}e[MAXN];
int first[MAXN];
int vin[MAXN];
int n,m;
int tot;
int cnt;

inline void Add_Edge(const int& u,const int& v)
{
	e[++tot].to=v;
	e[tot].nxt=first[u];	first[u]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	memset(vin,0,sizeof(vin));
	cnt=0;	tot=0;//tot未每次初a始化，导致TLE？？
	int u,v;
	_rep(i,1,m)
	{
		scanf("%d%d",&u,&v);
		u++;	v++;
		Add_Edge(u,v);	vin[v]++;
	}
}

void work()
{
	queue<int> q;
	_rep(i,1,n)
		if(!vin[i])
		{
			q.push(i);
			cnt++;
		}
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		for(int i=first[u];i!=-1;i=e[i].nxt)
		{
			const int& v=e[i].to;
			vin[v]--;
			if(!vin[v])
			{
				q.push(v);
				cnt++;
			}
		}
	}
	if(cnt==n)
		printf("YES\n");
	else
		printf("NO\n");
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