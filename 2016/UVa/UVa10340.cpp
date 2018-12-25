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
char s[MAXN],t[MAXN];
int n,m;

bool check()
{
	n=strlen(s);
	m=strlen(t);
	if(n>m)
		return 0;
	int cur=0;
	for(int i=0;i<m;i++)
	{
		if(cur<n&&s[cur]==t[i])
			cur++;
		if(cur==n)
			return 1;
	}
	if(cur==n)
		return 1;
	return 0;
}

int main()
{
	while(scanf("%s%s",s,t)!=EOF)
	{
		if(check())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
     