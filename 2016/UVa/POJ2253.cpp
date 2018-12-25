#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

char rd;	int pn;
template<typename Type>
inline void read(Type& v)
{
	pn=1;
	while((rd=getchar())<'0'||rd>'9')
		if(rd=='-')
			pn=-1;
	v=rd-'0';
	while((rd=getchar())>='0'&&rd<='9')
		v=v*10+rd-'0';
	v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1)
{
	if(v==0)
		putchar(48);
	else  
    {
    	if(v<0)
    	{
    		putchar('-');
    		v=-v;
    	}
    	int len=0,dg[20];  
    	while(v>0)
    	{
    		dg[++len]=v%10;
    		v/=10;
    	}  
    	for(int i=len;i>=1;i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}

const int MAXN=205;
int x[MAXN],y[MAXN];
double g[MAXN][MAXN];
int kase;
int n;

void init()
{
	for(int i=1;i<=n;i++)
	{
		read(x[i]);	read(y[i]);
	}
	for(int i=1;i<=n;i++)
	{
		g[i][i]=0.00;
		for(int j=i+1;j<=n;j++)
			g[i][j]=g[j][i]=sqrt((double)((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
	}
}

void work()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
	printf("Scenario #%d\n",++kase);
	printf("Frog Distance = %.3lf\n",g[1][2]);
	printf("\n");
}

int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		init();
		work();
	}
	return 0;
}
     