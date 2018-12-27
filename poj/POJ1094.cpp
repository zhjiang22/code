#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

const int MAXN=50;
struct Edge
{
	int to,nxt;
}e[MAXN*MAXN];
int first[MAXN];
int cnt[MAXN];
char ans[MAXN];
int tot;
int Cnt;
int n,m;
map<char,int> Map;
char Hash[MAXN];

int get_idx(const char& x)
{
	if(Map[x])
		return Map[x];
	Map[x]=++Cnt;
	Hash[Cnt]=x;
	return Cnt;
}

char get_char(const int& x)
{
	return Hash[x];
}

inline void Add_Edge(const int& u,const int& v)
{
	e[++tot].nxt=first[u];	first[u]=tot;	e[tot].to=v;
}

bool vis[MAXN];

int top_sort()
{
	queue<int> q;
	int in[MAXN];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		in[i]=cnt[i];
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	int p=0;
	int ret=2;
	while(!q.empty())
	{
		if(q.size()>1)
			ret=0;
		int u=q.front();	q.pop();	vis[u]=1;
		ans[p++]=get_char(u);
		for(int i=first[u];i!=-1;i=e[i].nxt)
		{
			in[e[i].to]--;
			if(!in[e[i].to])
				q.push(e[i].to);
		}
	}
	if(p<n)
		return 1;
	ans[p]='\0';
	return ret;
}

void work()
{
	memset(first,-1,sizeof(first));
	memset(cnt,0,sizeof(cnt));
	Cnt=0;
	Map.clear();
	char c1,c2;
	int u,v;
	getchar();
	int i;
	for(i=1;i<=m;i++)
	{
		scanf("%c<%c\n",&c1,&c2);
		u=get_idx(c1);	v=get_idx(c2);
		Add_Edge(u,v);
		cnt[v]++;
		int k=top_sort();
		if(k==1)
		{
			printf("Inconsistency found after %d relations.\n",i);
			break;
		}
		else	if(k==2)
		{
			printf("Sorted sequence determined after %d relations: %s.\n",i,ans);
			break;
		}
	}
	if(i==m+1)
		printf("Sorted sequence cannot be determined.\n");
	else	for(i=i+1;i<=m;i++)
		scanf("%c<%c\n",&c1,&c2);
}

int main()
{
	while(scanf("%d%d",&n,&m)==2&&(n||m))
		work();
	return 0;
}