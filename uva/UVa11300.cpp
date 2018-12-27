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

const int MAXN=1000005;
long long a[MAXN];
long long c[MAXN];
int n;

void init()
{
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		sum+=a[i];
	}
	long long m=sum/n;
	c[1]=0;
	for(int i=2;i<=n;i++)
		c[i]=c[i-1]+a[i]-m;
}

void work()
{
	sort(c+1,c+n+1);
	long long d=c[(n+1)/2];
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=abs(c[i]-d);
	out(ans);
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
     