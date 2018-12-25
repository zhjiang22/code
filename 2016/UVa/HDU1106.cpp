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
char a[MAXN];
int b[MAXN];
int n;

void work()
{
	n=0;
	int l=strlen(a);
	int i=0;
	while(a[i]=='5')
		i++;
	int x=0;
	while(i<l)
	{
		if(a[i]=='5')
		{
			b[++n]=x;
			x=0;
			while(a[i]=='5'&&i<l)
				i++;
		}
		else
		{
			x=(x*10)+(a[i]-'0');
			i++;
		}
	}
	if(a[l-1]!='5')
		b[++n]=x;
	sort(b+1,b+n+1);
	printf("%d",b[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",b[i]);
	printf("\n");
}

int main()
{
	while(scanf("%s",a)!=EOF)
	{
		work();
	}
	return 0;
}
     