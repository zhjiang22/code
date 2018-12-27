#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
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
const int INF=0x7ffffFf;
struct event
{
	int l,r,s;
	bool operator<(const event& p)const
	{
		return r>p.r;
	}
}a[MAXN];
int T,n;
int sum;
int L,R;

inline bool cmp(const event& a,const event& b)
{
	return a.l<b.l;
}

void init()
{
	sum=0;
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i].l);	read(a[i].r);
		L=min(L,a[i].l);	R=max(R,a[i].r);
		read(a[i].s);
		sum+=a[i].s;
	}
	sort(a+1,a+n+1,cmp);
}

bool check(int x)
{
	priority_queue<event> q;
	int cur=1;
	event u;
	for(int i=L;i<=R;i++)
	{
		int t=x;
		while(cur<=n&&a[cur].l<i)
			q.push(a[cur++]);
		while(!q.empty()&&t)
		{
			u=q.top();	q.pop();
			if(u.r<i)
				return false;
			if(u.s>t)
			{
				u.s-=t;
				q.push(u);
				break;
			}
			else
				t-=u.s;
		}
	}
	if(q.empty())
		return true;
	else
		return false;
}

void work()
{
	int l=1,r=sum;
	int ans=INF;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=min(ans,mid);
			r=mid-1;
		}
		else
			l=mid+1;
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
     