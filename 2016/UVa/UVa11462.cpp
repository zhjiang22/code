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

const int MAXN=105;
int a[MAXN];
int n;

void init()
{
	memset(a,0,sizeof(a));
	int x;
	for(int i=1;i<=n;i++)
	{
		read(x);
		a[x]++;
	}
}

void work()
{
	bool fisrt=1;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=a[i];j++)
		{
			if(fisrt)
				fisrt=0;
			else
				putchar(' ');
			printf("%d",i);
		}
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
     