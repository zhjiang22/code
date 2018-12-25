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

const int MAXN=255*255;
const int INF=0x7ffffff;
int a[MAXN];
int s[MAXN],g[MAXN],d[MAXN];
int n,p,q;
int T,kase;

void init()
{
	read(n);	read(p);	read(q);
	memset(a,0,sizeof(a));
	memset(d,0,sizeof(d));
	memset(g,0x3f,sizeof(g));
	int x;
	for(int i=1;i<=p+1;i++)
	{
		read(x);
		a[x]=i;
	}
	n=0;
	for(int i=1;i<=q+1;i++)
	{
		read(x);
		if(a[x])
			s[++n]=a[x];
	}
}

void work()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int k=lower_bound(g+1,g+n+1,s[i])-g;
		d[i]=k;
		g[k]=s[i];
		ans=max(ans,k);
	}
	printf("Case %d: %d\n",++kase,ans);
}

int main()
{
	read(T);
	while(T--)
	{
		init();
		work();
	}
	return 0;
}
     