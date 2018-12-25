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

long long a,b,c;

void init()
{
	read(a);	read(b);
	read(c);
}

long long mi(long long b)
{
	if(b==0)
		return 1;
	long long ans;
	if(b%2)
		ans=((a*mi(b/2))%c*mi(b/2))%c;
	else
		ans=(mi(b/2)*mi(b/2))%c;
	return ans;
}

void work()
{
	out(mi(b)%c);
}

int main()
{
	init();
	work();
	return 0;
}
     