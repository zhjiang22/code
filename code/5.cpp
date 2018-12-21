#include <bits/stdc++.h>
using namespace std;

const int N=60,M=1100;
const double eps=(double)1e-5,INF=(double)1e9;
int n,m;
queue<int> q;

struct e_node{
	int x,y;
	double d;
	bool bk;
}e[M];
struct node{
	int x,y,next;
	double d;
}a[M];
int al,first[N];
double dis[N],ans[N][N];
bool vis[N];

double minn(double x,double y){return x<y ? x:y;}
double maxx(double x,double y){return x>y ? x:y;}

bool cmp(e_node t0,e_node t1){
	if(t0.x!=t1.x) return t0.x<t1.x;
	if(t0.y!=t1.y) return t0.y<t1.y;
	return t0.d<t1.d;
}

void ins(int x,int y,double d)
{
	a[++al].x=x;a[al].y=y;a[al].d=d;
	a[al].next=first[x];first[x]=al;
}

void spfa(int st,double now)
{
	// for(int i=1;i<=al;i++) printf("%d -- > %d %lf\n",a[i].x,a[i].y,a[i].d);printf("now = %lf\n",now);
	for(int i=1;i<=al;i++) a[i].d-=now;
	// if(now-5.5 <= 0.00000001) 
	 	// for(int i=1;i<=al;i++) printf("%d -- > %d %lf\n",a[i].x,a[i].y,a[i].d);

	while(!q.empty()) q.pop();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) dis[i]=INF;
	q.push(st);
	vis[st]=1;dis[st]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=first[x];i;i=a[i].next)
		{
			int y=a[i].y;
			if(dis[y]>dis[x]+a[i].d)
			{
				dis[y]=dis[x]+a[i].d;
				if(!vis[y])
				{
					vis[y]=1;
					q.push(y);
				}
			}
		}
		vis[x]=0;
	}
	// for(int i=1;i<=n;i++) printf("%lf \n",dis[i]);
	for(int i=1;i<=al;i++) a[i].d+=now;
}

bool check(int x,int y,double now)
{
	spfa(x,now);
	return dis[y] <= eps;
}

int main() {
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	double mnd=INF,mxd=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&e[i].x,&e[i].y,&e[i].d);
		e[i].bk=1;
		mnd=minn(mnd,e[i].d);
		mxd=maxx(mxd,e[i].d);
	}
	sort(e+1,e+1+m,cmp);
	for(int i=2;i<=m;i++)
	{
		if(e[i].x==e[i].y || (e[i].x==e[i-1].x && e[i].y==e[i-1].y)) e[i].bk=0;
	}
	al=0;
	memset(first,0,sizeof(first));
	for(int i=1;i<=m;i++)
	{
		if(e[i].bk) ins(e[i].x,e[i].y,e[i].d);
	}
	// for(int i=1;i<=al;i++) printf("%d -- > %d %lf\n",a[i].x,a[i].y,a[i].d);
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			double l=mnd,r=mxd,mid;
			int cnt=0;
			while(r-l>eps && cnt<25)
			{
				cnt++;
				mid=(l+r)/2;
				if(check(i,j,mid)) r=mid;
				else l=mid;
			}
			if(r-l<=eps && (check(i,j,l) || check(i,j,r))) ans[i][j]=l;
			else ans[i][j]=-1;
		}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(ans[x][y]<0) printf("OMG!\n");
		else printf("%.3lf\n",ans[x][y]);
	}
	return 0;
}