#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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

const int MAXN=10005;
const int INF=0x7fffff;
int a[MAXN];
int g1[MAXN],d1[MAXN];
int g2[MAXN],d2[MAXN];
int n;

void LIS()
{
	for(int i=1;i<=n;i++)
	{
		int k=lower_bound(g1+1,g1+n+1,a[i])-g1;
		d1[i]=k;
		g1[k]=a[i];
	}
	for(int i=n;i>=1;i--)
	{
		int k=lower_bound(g2+1,g2+n+1,a[i])-g2;
		d2[i]=k;
		g2[k]=a[i];
	}
}

void work()
{
	LIS();
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,(min(d1[i],d2[i])*2-1));
	out(ans);
}

void init()
{
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=n;i++)
		g1[i]=g2[i]=INF;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		init();
		work();
	}
	return 0;
}
