/*
Orz一道挺好的最短路的
最短路简单啊
直接裸的SPFA
然而这个字符串处理让我欲仙欲死欲罢不能
WA了2次QAQ
我好弱啊
第一次是因为开锁时间没有处理好
第二次是因为忘记了小时前面没有前导0
QWQ还有多余的秒也是要去掉的233333
唉水题
主要要多注意字符串了
果然邻接表的SPFA快的一逼
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXN=1005;
struct Edge
{
	int from,to,dist;
	Edge(int from,int to,int dist):from(from),to(to),dist(dist){}
};
vector<Edge> e;
vector<int> g[MAXN];
int n,m;
bool in[MAXN];
int d[MAXN];
queue<int> q;
int hour,minute;
int waste;

void inline Add_Edge(int x,int y,int w)
{
	e.push_back(Edge(x,y,w));
	e.push_back(Edge(y,x,w));
	int d=e.size();
	g[x].push_back(d-2);
	g[y].push_back(d-1);
}

void gettime()
{
	char ch;
	while(ch=getchar())
	{
		if(ch==':')
			break;
		hour=hour*10+(ch-'0');
	}
	while(ch=getchar())
	{
		if(ch=='\n')
			break;
		minute=minute*10+(ch-'0');
	}
}

void getwaste()
{
	int t;
   	string type;
    cin>>t>>type;
    if(type[0]=='s')
        waste=t;
    if(type[0]=='m')
        waste=60*t;
    if(type[0]=='h')
        waste=60*60*t;
}

void init()
{
	int x,y,w;
	gettime();
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		if(x==0||y==0)
			continue;
		Add_Edge(x,y,w);
	}
	memset(d,0x3f,sizeof(d));
	getwaste();
}

void SPFA()
{
	d[1]=0;
	in[1]=0;
	q.push(1);

	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		in[x]=0;
		int sz=g[x].size();
		for(int i=0;i<sz;i++)
		{
			int k=e[g[x][i]].to;
			int w=e[g[x][i]].dist;
			if(d[k]>d[x]+w)
			{
				d[k]=d[x]+w;
				if(!in[k])
				{
					q.push(k);
					in[k]=1;
				}
			}
		}
	}
}

void solve()
{
	minute+=d[n];
	minute+=waste/60;
	if(minute>=60)
	{
		hour+=minute/60;
		minute%=60;
	}
	if(hour>=24)
		cout<<"Sad"<<endl;
	else
		printf("%d:%02d\n",hour,minute);
}

int main()
{
	init();
	SPFA();
	solve();
	return 0;
}
     