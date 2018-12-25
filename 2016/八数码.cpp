#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<set>
#include<cstdio>
using namespace std;
typedef int stade[10];
struct node
{
	stade x;
	int y;	
};

const int MAXN=99999;
stade goal={1,2,3,8,0,4,7,6,5};
int dist[MAXN];
set<int>vis;
queue<node> q;
stade st;

const int zx[4]={-1,1,0,0};
const int zy[4]={0,0,1,-1};

int Try(node s)
{
	int v=0;
	for(int i=0;i<9;i++)
		v=v*10+s.x[i]-'0';
	if(vis.count(v))
		return 0;
	vis.insert(v);
	return 1;
}

int bfs()
{
	vis.clear();
	node l;
	memcpy(&l.x,&st,sizeof(st));
	l.y=0;
	q.push(l);
	while(!q.empty())
	{
		node &k=q.front();
		if(memcmp(goal,k.x,sizeof(goal))==0)
			return k.y;
		int i=0;
		while(k.x[i]!=0)	i++;
		int x=i/3,y=i%3;
		for(int j=0;j<4;j++)
		{
			int newx=x+zx[j];
			int newy=y+zy[j];
			int newz=newx*3+newy;
			if(newx>=0&&newx<3&&newy>=0&&newy<3)
			{
				node t;
				memcpy(&t.x,&k.x,sizeof(k.x));
				t.y=k.y+1;
				t.x[newz]=k.x[i];
				t.x[i]=k.x[newz];
				if(Try(t))
				q.push(t);
			}
		}
		q.pop();
	}
	return 0;
}

int main()
{
	for(int i=0;i<9;i++)
		scanf("%01d",&st[i]);
	int ans=bfs();
	if(ans)
	cout<<ans;
	else 
	cout<<"-1";
	return 0;
}
