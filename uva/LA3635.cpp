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

const int MAXN=10005;
const double PI=acos(-1.0);
double pie[MAXN];
int T,n,f;
double maxp;

void init()
{
	read(n);	read(f);
	maxp=-1;
	int r;
	for(int i=1;i<=n;i++)
	{
		read(r);	pie[i]=PI*r*r;
		maxp=max(maxp,pie[i]);
	}
}

bool check(double x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=floor(pie[i]/x);
	return cnt>=f+1;
}

void work()
{
	double l=0,r=maxp;
	while(r-l>1e-5)
	{
		double mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%.4lf\n",l);
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
     