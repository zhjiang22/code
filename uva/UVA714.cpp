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

const int MAXN=505;
const int INF=0x7fffff;
int a[MAXN];
int n,k;
int sum;
int T;


void init()
{
	sum=0;
	read(n);	read(k);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		sum+=a[i];
	}
}

bool check(int x)
{
	int cur=0;
	int tot=0;
	int last=0;
	for(int i=1;i<=n;i++)
	{
		if(cur+a[i]<=x)
		{
			cur+=a[i];
			last=i;	
		}
		else
		{
			cur=a[i];
			tot++;
		}
	}
	if(last!=n)
		tot++;
	return tot<=k;
}

void work()
{
	int l=0,r=sum;
	int ans=INF;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			r=mid,ans=min(ans,mid);
		else
			l=mid+1;
	}
	int cur=0;
	for(int i=1;i<=n;i++)
		if(cur+a[i]<=ans)
		{
			cout<<a[i]<<" ";
			cur+=a[i];
		}
		else
		{
			cout<<"/ ";
			cout<<a[i]<<" ";
			cur=a[i];
		}
	cout<<endl;
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
     