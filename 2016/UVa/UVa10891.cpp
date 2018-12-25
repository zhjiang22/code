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
const int INF=0x7fffff;
int f[MAXN][MAXN];
int s[MAXN];
int a[MAXN];
int n;

void init()
{
	s[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=INF;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		s[i]=s[i-1]+a[i];
	}
}

int dp(int i,int j)
{
	if(f[i][j]!=INF)
		return f[i][j];
	int m=0;
	for(int k=i+1;k<=j;k++)
		m=min(m,dp(k,j));
	for(int k=i;k<j;k++)
		m=min(m,dp(i,k));
	f[i][j]=s[j]-s[i-1]-m;
	return f[i][j];
}

void work()
{
	int ans=2*dp(1,n)-s[n];
	printf("%d\n",ans);
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
     