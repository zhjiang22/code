#include<bits/stdc++.h>
using namespace std;

const int MAXN=25005;
const int MAXM=150005;
const int INF=0x3fffff;
struct Edge
{
	int to,nxt;
	int w;
}e[MAXM];
int first[MAXN];
int tot;
int n,r,p;
int s;

inline void Add_Edge(const int& u,const int& v,const int& w)
{
	e[++tot].to=v;	e[tot].w=w;
	e[tot].nxt=first[u];	first[u]=tot;
}

void init()
{
	memset(first,-1,sizeof(first));
	cin>>n>>r>>p>>s;
	int u,v,w;
	for(int i=1;i<=r;i++)
	{
		cin>>u>>v>>w;
		Add_Edge(u,v,w);	Add_Edge(v,u,w);
	}
	for(int i=1;i<=p;i++)
	{
		cin>>u>>v>>w;
		Add_Edge(u,v,w);
	}
}

bool inq[MAXN];
int d[MAXN];
deque<int> q;

void work()
{
	for(int i=1;i<=n;i++)	d[i]=INF;
	d[s]=0;	q.push_back(s);	inq[s]=1;
	while(!q.empty())
	{
		int u=q.front();	q.pop_front();	inq[u]=0;
		for(int i=first[u];i!=-1;i=e[i].nxt)
		{
			int& v=e[i].to;	int& w=e[i].w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!inq[v])
				{
					inq[v]=1;
					if(q.empty())
						q.push_back(v);
					else	if(d[v]<d[q.front()])
						q.push_front(v);
					else
						q.push_back(v);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(d[i]==INF)
			printf("NO PATH\n");
		else
			printf("%d\n",d[i]);
}

int main()
{
	init();
	work();
	return 0;
}
     