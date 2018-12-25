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

int n;

void init()
{
	read(n);
}

bool check(int x)
{
	if(x<1000)
	{
		int a=x/100;	int b=(x/10)%10;	int c=x%10;
		if(a*a*a+b*b*b+c*c*c==x)
			return 1;
	}
	else
	{
		int a=x/1000;	int b=(x/100)%10;	int c=(x/10)%10;	int d=x%10;
		if(a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==x)
			return 1;
	}
	return 0;
}

void work()
{
	for(int i=n;;i++)
	{
		if(check(i))
		{
			out(i);
			return;
		}
	}
}

int main()
{
	init();
	work();
}
     