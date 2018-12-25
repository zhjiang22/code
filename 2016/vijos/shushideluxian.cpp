#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=500;
const double INF=999999.0;
struct Edge
{
	int x,y,w;
}e[MAXN*20];
int n,m;
int fa[MAXN];
int s,t;
double ans=INF;
int ans1,ans2;

bool inline cmp(Edge a,Edge b)
{
	return a.w<b.w;
}

void makefather()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
}

int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int gcd(int e,int b)
{
	 return b==0?e:gcd(b,e%b);
}

void Merge(int x,int y)
{
	int fx=find(x);	int fy=find(y);
	if(fx!=fy)
		fa[fx]=fy;
}

void init()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].w;
	cin>>s>>t;
	makefather();
	for(int i=1;i<=m;i++)
		Merge(e[i].x,e[i].y);
	if(find(s)!=find(t))
	{
		cout<<"IMPOSSIBLE"<<endl;
		exit(0);
	}
}

void out()
{
	if(ans1%ans2==0)
		cout<<ans1/ans2<<endl;
	else
	{
		int x=gcd(ans1,ans2);
		cout<<ans1/x<<"/"<<ans2/x<<endl;
	}
}

int main()
{
	init();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)//枚举边的其实选择处
	{
		makefather();
		int k=e[i].w;
		for(int j=i;j<=m;j++)
		{
			Merge(e[j].x,e[j].y);
			if(find(s)==find(t))
			{
				double now=(double)e[j].w/k;
				if(now<ans)
				{
					ans=now;
					ans1=e[j].w;
					ans2=k;
					break;
				}
				break;
			}
		}
	}
	out();
	return 0;
}
     