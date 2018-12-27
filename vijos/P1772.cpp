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

const int MAXN=12;
int d[MAXN];

void work()
{
	for(int a=123;a<333;a++)
	{
		int b=a*2;	int c=a*3;
		d[1]=a/100;	d[2]=(a/10)%10;	d[3]=a%10;
		d[4]=b/100;	d[5]=(b/10)%10;	d[6]=b%10;
		d[7]=c/100;	d[8]=(c/10)%10;	d[9]=c%10;
		sort(d+1,d+10);
		bool ok=1;
		for(int i=1;i<=9;i++)
			if(d[i]==d[i+1]||d[i]==0)
				ok=0;
		if(ok)
			cout<<a<<" "<<b<<" "<<c<<endl;
		else
			continue;
	}
}

int main()
{
	work();
	return 0;
}
     