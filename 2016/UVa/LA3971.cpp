#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
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
const int INF=1000000005;
map<string,int> id;
int T,n,b;
int maxq;
int cnt;

struct Computer
{
	int prize;
	int quality;
};
vector<Computer> comp[MAXN];

inline int ID(string s)
{
	if(!id.count(s))
		id[s]=++cnt;
	return id[s];
}

void init()
{
	read(n);	read(b);
	for(int i=1;i<=n;i++)
		comp[i].clear();
	id.clear();
	maxq=0;	cnt=0;
	for(int i=1;i<=n;i++)
	{
		char type[30],name[30];
		int p,q;
		scanf("%s%s",type,name);
		read(p);	read(q);
		maxq=max(maxq,q);
		comp[ID(type)].push_back((Computer){p,q});
	}
}

bool check(int x)
{
	int sumcost=0;
	for(int i=1;i<=cnt;i++)
	{
		int cheepest=b+1;
		int m=comp[i].size();
		for(int j=0;j<m;j++)
			if(comp[i][j].quality>=x)
			{
				cheepest=min(cheepest,comp[i][j].prize);
			}
		if(cheepest==b+1)
				return 0;
		sumcost+=cheepest;
		if(sumcost>b)
			return false;
	}
	return true;
}

void work()
{
	int l=0,r=maxq;
	while(l<r)
	{
		int mid=l+(r-l+1)/2;//注意此处书写，不然TLE
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	out(l);
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
     