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

const int MAXN=15005;
const int MAXV=32005;
struct node
{
	int x,y;
	bool operator<(const node& b)const
	{
		if(x==b.x)
			return y<b.y;
		else
			return x<b.x;
	}
}a[MAXN];
int t[MAXV];
int ans[MAXN];
int maxy;
int n;

inline int lowbit(int& x)
{
	return x&(-x);
}

void init()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i].x);	read(a[i].y);
		maxy=max(maxy,a[i].y);
	}
	sort(a+1,a+n+1);
}

int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=t[x];
		x-=lowbit(x);
	}
	return ans;
}

void add(int x,int d)
{
	while(x<=maxy)
	{
		t[x]+=d;
		x+=lowbit(x);
	}
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		ans[sum(a[i].y)]++;
		add(a[i].y,1);
	}
	for(int i=0;i<n;i++)
		out(ans[i]);
}

int main()
{
	init();
	work();
}
     