#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <queue>
using namespace std;

struct node
{
	int v[3],dist;
	bool operator < (const node &s) const
	{
		return dist>s.dist;
	}
};
const int MAXN=205;
int vis[MAXN][MAXN],cap[3],ans[MAXN];
int a,b,c,d;
priority_queue<node> q;

void up(const node & a)
{
	for(int i=0;i<3;i++)
	{
		int d=a.v[i];
		if(ans[d]<0||a.dist<ans[d])
			ans[d]=a.dist;
	}
}

void solve()
{
	node start;
	start.dist=0;
	start.v[0]=0,start.v[1]=0,start.v[2]=c;
	vis[0][0]=1;
	q.push(start);

	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		cout<<x.dist<<endl;
		up(start);
		if(ans[d]>=0)	break;

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{	
				if(i==j||x.v[i]==0||x.v[j]==cap[j])	continue;
						int amout=min(cap[j],x.v[i]+x.v[j])-x.v[j];
						node newx;
						memcpy(&newx,&x,sizeof(x));
						newx.dist=x.dist+amout;
						newx.v[i]-=amout;
						newx.v[j]+=amout;
						if(!vis[newx.v[0]][newx.v[1]])
						{
							vis[newx.v[0]][newx.v[1]]=1;
							q.push(newx);
						}
			}
		}
	}

	while(d>=0)
	{
		if(ans[d]>=0)
		{
			cout<<ans[d]<<" "<<d<<endl;
			return;
		}
		d--;
	}
}

int main()
{
	cin>>a>>b>>c>>d;
	cap[0]=a,cap[1]=b,cap[2]=c;
	memset(vis,0,sizeof(vis));
	memset(ans,-1,sizeof(ans));
	solve();
	return 0;
}
     