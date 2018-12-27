#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
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

void work()
{
	priority_queue<int,vector<int>,greater<int>> q;
	int x;
	for(int i=1;i<=n;i++)
	{
		read(x);
		q.push(x);
	}
	int a,b;
	int ans=0;
	for(int i=1;i<n;i++)
	{
		a=q.top();	q.pop();
		b=q.top();	q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	out(ans);
}

int main()
{
	while(scanf("%d",&n)==1&&n)
	{
		work();
	}
	return 0;
}
     