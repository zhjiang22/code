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

const int MAXN=400005;
int a[MAXN];
int addv[MAXN];
int n;

int lx,ry;

void update(int o,int l,int r)
{
	if(lx<=l&&ry>=r)
	{
		addv[o]++;
		return;
	}
	int lc=o<<1,rc=o<<1|1;
	int m=l+(r-l)/2;
	if(lx<=m)
		update(lc,l,m);
	if(ry>m)
		update(rc,m+1,r);
}

void init()
{
	memset(addv,0,sizeof(addv));
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		read(lx);	read(ry);
		update(1,1,n);
	}
}

void maintain(int o,int l,int r)
{
	if(addv[o])
		for(int i=l;i<=r;i++)
			a[i]+=addv[o];
	if(l==r)
		return;
	int m=l+(r-l)/2;
	int lc=o<<1,rc=o<<1|1;
	maintain(lc,l,m);
	maintain(rc,m+1,r);
}

void work()
{
	maintain(1,1,n);
	printf("%d",a[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",a[i]);
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
     