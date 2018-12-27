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

const int MAXN=1005;
bool can[MAXN][MAXN];
char c[MAXN];
int f[MAXN];
int T,n;

bool is_true(int l,int r)
{
	while(l<=r)
	{
		if(c[l]!=c[r])
			return false;
		l++;	r--;
	}
	return true;
}

void init()
{
	memset(can,0,sizeof(can));
	gets(c);
	n=strlen(c);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(is_true(i-1,j-1))
				can[i][j]=1;
}

void work()
{
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			if(can[j][i])
				f[i]=min(f[i],f[j-1]+1);
	}
	out(f[n]);
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
     