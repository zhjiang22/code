#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXT=4000;
struct node
{
	int t,w,h;
	bool operator <(const node& b)
	{
		return t<b.t;
	}
}a[MAXN];
bool f[MAXT][MAXT];//f[i][j]表示剩余j时间,堆到i高度
int D,W;
int n,d;

void init()
{
	scanf("%d%d",&d,&n);	W=10;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].t,&a[i].w,&a[i].h);
		D+=a[i].h;	W+=a[i].w;
	}
	sort(a+1,a+n+1);
}

void DP()
{
	f[0][10]=1;
	for(int i=1;i<=n;i++)
		for(int j=d-1;j>=0;j--)
			for(int k=W;k>=a[i].t;k--)
				if(f[j][k])
				{
					f[j+a[i].h][k]=1;
					if(j+a[i].h>=d)
					{
						printf("%d\n",a[i].t);
						return;
					}
					f[j][k+a[i].w]=1;
				}
	for(int i=W;i>=1;i--)
		if(f[0][i])
		{
			printf("%d\n",i);
			return;
		}
}

int main()
{
	init();
	DP();
}
     