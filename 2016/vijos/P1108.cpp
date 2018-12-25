/*
差分约束
http://www.cnblogs.com/fraud/p/4304350.html
和区间一起的在论文中有
http://wenku.baidu.com/view/685fbe1e650e52ea5518981a.html?from=related
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=1005;
const int INF=(1<<30)-1;
struct Edge
{
	int to,nxt,w;
	Edge()
	{
		to=nxt=w=-1;
	}
}e[MAXN];
int first[MAXN];
int t,n;
int tot;
int d[MAXN];
int in[MAXN];
int cnt[MAXN];
int R[MAXN];
int num[MAXN];
int inihead[MAXN];
queue<int> q;

void inline Add_Edge(int x,int y,int w)
{
	tot++;
	e[tot].to=y;
	e[tot].w=w;
	e[tot].nxt=first[x];
	first[x]=tot;
}

void init()
{
	int a;
	for(int i=1;i<=24;i++)
		cin>>R[i];
	cin>>n;
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		num[a+1]++;
	}
	tot=0;	memset(first,-1,sizeof(first));
	memset(e,-1,sizeof(-1));
	for(int i=1;i<=24;i++)
	{
		if(i>7)	Add_Edge(i-8,i,R[i]);
		Add_Edge(i,i-1,-num[i]);
		Add_Edge(i-1,i,0);
	}
	for(int i=0;i<25;i++)
		inihead[i]=first[i];
}

bool SPFA(int mid)
{
	for(int i=0;i<=24;i++)
		d[i]=-INF,in[i]=0,cnt[i]=0;
	q.push(0);	in[0]=1;	cnt[0]++;	d[0]=0;
	while(!q.empty())
	{
		int x=q.front();	q.pop();
		in[x]=0;
		for(int i=first[x];i!=-1;i=e[i].nxt)
		{
			int y=e[i].to;	int w=e[i].w;
			if(d[y]<d[x]+w)
			{
				d[y]=d[x]+w;
				if(!in[y])
				{
					q.push(y);
					in[y]=1;
					if(++cnt[y]>25)
						return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	cin>>t;
	while(t--)
	{
		init();
		int l=0,r=n;
		int ans=INF;
		while(l<r)
		{
			int mid=(l+r)/2;
			for(int i=0;i<25;i++)
				 first[i]=inihead[i];
			for(int i=1;i<8;i++)
				Add_Edge(i+16,i,R[i]-mid);
			Add_Edge(0,24,mid);
			if(SPFA(mid))
			{
				r=mid;
				ans=min(ans,mid);
			}
			else
				l=mid+1;
		}
		if(ans>n)
			cout<<"No Solution"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
     