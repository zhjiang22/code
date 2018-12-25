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

const int MAXN=2005;
int c[MAXN][MAXN];
int f[MAXN][MAXN];
int n,m,t,k;

void init()
{
	read(t);	read(k);
}

void work()
{
	for(int i=1;i<=2002;i++)
		c[i][0]=c[i][i]=1;
	for(int i=2;i<=2002;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
	for(int i=1;i<=2002;i++)
	{
		for(int j=1;j<=i;j++)
			if(!c[i][j])
				f[i][j]=f[i][j-1]+1;
			else
				f[i][j]=f[i][j-1];
	}
}

void question()
{
	int ans;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		read(n);	read(m);
		for(int j=1;j<=n;j++)
			ans+=f[j][min(j,m)];
		out(ans);
	}
}

int main()
{
	init();
	work();
	question();
	return 0;
}
     