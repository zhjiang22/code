#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN=1005;
const int MAXM=1005*1005;
const double eps=1e-4;
int n;

struct Point
{
	int x,y,z;
	double dis(const Point& p)const{
		return sqrt((double)(x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
	}
	int high(const Point& p)const{
		return abs(z-p.z);
	}
}a[MAXN];

double dis[MAXN][MAXN];
int cost[MAXN][MAXN];

void init(){
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			cost[i][j]=cost[j][i]=a[i].high(a[j]);
			dis[i][j]=dis[j][i]=a[i].dis(a[j]);
		}
}

double g[MAXN][MAXN];
double d[MAXN];
int vis[MAXN];

bool prim()
{
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	double ans=0.0;
	d[1]=0;	vis[1]=1;
	for(int i=2;i<=n;i++)	d[i]=g[1][i];
	for(int i=1;i<n;i++){
		int x=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(x==0||d[j]<d[x]))
				x=j;
		vis[x]=1;	ans+=d[x];
		for(int j=1;j<=n;j++)
			if(!vis[j])
				d[j]=min(d[j],g[x][j]);
	}
	return ans<0;
}

bool check(double k)
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			g[i][j]=g[j][i]=cost[i][j]-k*dis[i][j];
	return prim();
}

void work(){
	double l=0,r=1e3;
	while(r-l>eps){
		double mid=(l+r)/2.0;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%.3f\n",l);
}

int main(){
	while(scanf("%d",&n)&&n){
		init();
		work();
	}
	return 0;
}
     