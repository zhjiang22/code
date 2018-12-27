#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
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

const int MAXN=500005;
int a[MAXN];
int n;
unsigned long long ans;

void init()
{
	for(int i=1;i<=n;i++)
		read(a[i]);
	ans=0;
}

int t[MAXN];

void merge_sort(int l,int r)
{
	if(l>=r)
		return;
	int mid=(l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int p=l,q=mid+1;
	int cur=l;
	while(p<=mid||q<=r)
	{
		if(q>r||((p<=mid)&&a[p]<a[q]))
			t[cur++]=a[p++];
		else
		{
			t[cur++]=a[q++];
			ans+=(mid-p+1);
		}
	}
	for(int i=l;i<=r;i++)
		a[i]=t[i];
}

void work()
{
	merge_sort(1,n);
	out(ans);
}

int main()
{
	while(scanf("%d",&n)&&n)
	{
		init();
		work();
	}
	return 0;
}
     