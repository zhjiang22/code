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

const int MAXN=50005;
int a[MAXN];
int t[MAXN];
int ans;
int n;

void init()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
}

void merge_sort(int l,int r)
{
	if(r-l>1)
	{
		int mid=l+(r-l)/2;
		int p=l,q=mid,i=l;
		merge_sort(l,mid);
		merge_sort(mid,r);
		while(p<mid||q<r)
		{
			if(q>=r||(p<mid&&a[p]<=a[q]))
				t[i++]=a[p++];
			else
			{
				t[i++]=a[q++];
				ans+=mid-p;
			}
		}
		for(int i=l;i<r;i++)
			a[i]=t[i];
	}
}

void work()
{
	merge_sort(1,n+1);
	out(ans);
}

int main()
{
	init();
	work();
	return 0;
}
     