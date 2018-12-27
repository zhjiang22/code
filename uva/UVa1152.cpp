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

const int MAXN=4005;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int T,n;

void init()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);	read(b[i]);
		read(c[i]);	read(d[i]);
	}
}

int s[MAXN*MAXN],t[MAXN*MAXN];

void work()
{
	int l=n*n;
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			s[(i-1)*n+j]=a[i]+b[j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			t[(i-1)*n+j]=-c[i]-d[j];
	sort(t+1,t+l+1);
	for(int i=1;i<=l;i++)
		ans+=(upper_bound(t+1,t+l+1,s[i])-lower_bound(t+1,t+l+1,s[i]));
	out(ans);
	if(T)
		printf("\n");
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
     