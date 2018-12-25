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
int a[MAXN];
int n,m;
int kase;

void init()
{
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+n+1);
}

int find(int x)
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+(r-l)/2);
		if(a[mid]==x)
			return mid;
		else	if(a[mid]<x)
			l=mid+1;
		else
			r=mid-1;
	}
	if(a[l]==x)
		return l;
	if(a[r]==x)
		return r;
	return -1;
}

void work()
{
	int x;
	printf("CASE# %d:\n",++kase);
	for(int i=1;i<=m;i++)
	{
		read(x);
		int p=lower_bound(a+1,a+n+1,x)-a;
		if(a[p]==x)
			printf("%d found at %d\n",x,p);
		else
			printf("%d not found\n",x);
		/*if(p==-1)
			printf("%d not found\n",x);
		else
			printf("%d found at %d\n",x,p);*/
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)==2&&n&&m)
	{
		init();
		work();
	}
	return 0;
}
     