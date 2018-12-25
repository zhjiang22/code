#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=205;
struct point
{
	int x,y;
	bool operator<(const point& powder)
	{
		return x<powder.x;
	}
}p[MAXN];
int y[MAXN];
int on[MAXN],on2[MAXN],Left[MAXN];
int ans;
int n,m;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y),
		y[i]=p[i].y;
	sort(p+1,p+n+1);
	sort(y+1,y+n+1);
}

int solve()
{
	int m=unique(y+1,y+n+1)-y;
	if(m<=2)	return n;
	for(int a=1;a<=m;a++)
		for(int b=a+1;b<=m;b++)
		{
			int ymin=y[a];	int ymax=y[b];
			int k=0;
			for(int i=1;i<=n;i++)
			{
				if(i==1||p[i].x!=p[i-1].x)
				{
					k++;
					on[k]=on2[k]=0;
					Left[k]=k==0?0:Left[k-1]+on2[k-1]-on[k-1];
				}
				if(p[i].y>ymin&&p[i].y<ymax)	on[k]++;
				if(p[i].y>=ymin&&p[i].y<=ymax)	on2[k]++;
			}
			if(k<=2)	return n;
			int maxv=0;
			for(int j=1;j<=k;j++)
				ans=max(ans,Left[j]+on2[j]+maxv),
				maxv=max(maxv,on[j]-Left[j]);
		}
	return ans;
}

int main()
{
	init();
	cout<<solve()<<endl;
	return 0;
}
     