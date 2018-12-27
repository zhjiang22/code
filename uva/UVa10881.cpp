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

const int MAXN=10005;
struct Ant
{
	int idx;
	int poss;
	int d;
	bool operator <(const Ant& c)const
	{
		return poss<c.poss;
	}
}before[MAXN],after[MAXN];
int order[MAXN];
int T,Case;
int L,t,n;

inline char get_char()
{
	char ch;
	for(;;)
	{
		ch=getchar();
		if(ch=='L'||ch=='R')
			return ch;
	}
}

void init()
{
	read(L);	read(t);	read(n);
	char ch;
	for(int i=1;i<=n;i++)
	{
		read(before[i].poss);
		ch=get_char();
		if(ch=='L')
			before[i].d=-1;
		else
			before[i].d=1;
		before[i].idx=i;
	}
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		after[i].poss=before[i].poss+t*before[i].d;
		after[i].d=before[i].d;
	}
	sort(before+1,before+n+1);
	sort(after+1,after+n+1);
	for(int i=1;i<=n;i++)
		order[before[i].idx]=i;
	for(int i=1;i<=n;i++)
		if(after[i].poss==after[i+1].poss)
			after[i].d=after[i+1].d=0;
	printf("Case #%d:\n",++Case);
	for(int i=1;i<=n;i++)
	{
		int a=order[i];
		if(after[a].poss>L||after[a].poss<0)
		{
			printf("Fell off\n");
			continue;
		}
		out(after[a].poss,0);
		if(after[a].d==-1)
			printf("L\n");
		else	if(after[a].d==1)
			printf("R\n");
		else
			printf("Turning\n");
	}
	printf("\n");
}

int main()
{
	read(T);
	while(T--)
	{
		init();
		work();
	}
}
     