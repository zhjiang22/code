#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
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

struct point
{
	int a,b;
	bool operator<(const point& c)const
	{
		return a<c.a||(a==c.a&&b<c.b);
	}
};
multiset<point> s;
multiset<point>::iterator it;
int T,n;

void init()
{
	read(n);
	s.clear();
}

void work()
{
	int a,b;
	for(int i=1;i<=n;i++)
	{
		read(a);	read(b);
		point P=(point){a,b};
		it=s.lower_bound(P);
		if(it==s.begin()||(--it)->b>b)
		{
			s.insert(P);
			it=s.upper_bound(P);
			while(it!=s.end()&&it->b>=b)
				s.erase(it++);
		}
		out(s.size());
	}
}

int main()
{
	read(T);
	for(int kase=1;kase<=T;kase++)
	{
		if(kase>1)
			printf("\n");
		printf("Case #%d:\n",kase);
		init();
		work();
	}
	return 0;
}
     