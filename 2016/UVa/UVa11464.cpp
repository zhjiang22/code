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

const int MAXN=18;
const int INF=0x7fffff;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int kase;
int T,n;

void init()
{
	read(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			read(a[i][j]);
}

int check(int x)
{
	memset(b,0,sizeof(b));
	for(int i=0;i<n;i++)
		if(x&(1<<i))
			b[0][i]=1;
		else	if(a[0][i]==1)
			return INF;
	for(int x=1;x<n;x++)
		for(int y=0;y<n;y++)
		{
			int sum=0;
			if(x>=2)	sum+=b[x-2][y];
			if(y>=1)	sum+=b[x-1][y-1];
			if(y<=n-2)	sum+=b[x-1][y+1];
			b[x][y]=sum%2;
			if(b[x][y]==0&&a[x][y]==1)
				return INF;
		}
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]!=b[i][j])
				cnt++;
	return cnt;
}

void work()
{
	int ans=INF;
	for(int x=0;x<(1<<n);x++)
		ans=min(ans,check(x));
	if(ans==INF)
		printf("Case %d: -1\n",++kase);
	else
		printf("Case %d: %d\n",++kase,ans);
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
     