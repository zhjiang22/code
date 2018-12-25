#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
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

const int MAXN=20005;
const int MAXC=100005;
int T;
int a[MAXN];
int c[MAXC];
int d[MAXC];
int q[MAXN],p[MAXN];
long long ans;
int maxw;
int n;

inline int lowbit(int x)
{
	return x&(-x);
}

void init()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		maxw=max(maxw,a[i]);
	}
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
}

void add(int o[],int x,int d)
{
	while(x<=maxw)
	{
		o[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int o[],int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=o[x];
		x-=lowbit(x);
	}
	return ret;
}

void work()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		p[i]=sum(c,a[i]);
		add(c,a[i],1);
	}
	for(int i=n;i>=1;i--)
	{
		q[i]=sum(d,a[i]);
		add(d,a[i],1);
	}
	for(int i=1;i<=n;i++)
		ans+=p[i]*(n-i-q[i])+q[i]*(i-p[i]-1);
	out(ans);
}

int main()
{
	read(T);
	for(int k=1;k<=T;k++)
	{
		init();
		work();
	}
}
     