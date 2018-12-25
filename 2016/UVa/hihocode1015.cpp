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

const int MAXN=1000005;
char a[MAXN];
char b[MAXN];
int f[MAXN];
int n,m;
int T;

void init()
{
	scanf("%s",a);
	scanf("%s",b);
	n=strlen(b);
	m=strlen(a);
}

void get_fail()
{
	f[0]=f[1]=0;
	for(int i=1;i<m;i++)
	{
		int j=f[i];
		while(j&&a[i]!=a[j])
			j=f[j];
		f[i+1]=a[i]==a[j]?j+1:0;
	}
}

void work()
{
	get_fail();
	int j=0,ans=0;
	for(int i=0;i<n;i++)
	{
		while(j&&a[j]!=b[i])
			j=f[j];
		if(a[j]==b[i])
			j++;
		if(j==m)
			ans++;
	}
	out(ans);
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
     