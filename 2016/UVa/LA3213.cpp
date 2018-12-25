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
char a[MAXN],b[MAXN];
int p[30],q[30];
int n;

bool check()
{
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	n=strlen(a);
	for(int i=0;i<n;i++)
	{
		p[a[i]-'A'+1]++;
		q[b[i]-'A'+1]++;
	}
	sort(p+1,p+26+1);
	sort(q+1,q+26+1);
	for(int i=1;i<=26;i++)
		if(p[i]!=q[i])
			return 0;
	return 1;
}

int main()
{
	while(scanf("%s%s",a,b)==2)
	{
		if(check())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
     