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

const int MAXN=500005;
int T,n;
struct P
{
	int x,d;
	bool operator<(const P& o)const
	{
		return x<o.x;
	}
}a[MAXN];

void init()
{
	read(n);
	int c;
	for(int i=1;i<=n;i++)
	{
		read(c);
		a[i].x=abs(c);
		a[i].d=(c<0);
	}
	sort(a+1,a+n+1);
}

void work()
{
	int cnt=1;
	int nxt=1-a[1].d;
	for(int i=2;i<=n;i++)
	{
		if(a[i].d==nxt)
		{
			cnt++;
			nxt=1-a[i].d;
		}
	}
	out(cnt);
}

int main()
{
	read(T);
	while(T--)
	{
		init();
		work();
	}
}
     