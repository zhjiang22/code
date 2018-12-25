#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
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

const int MAXN=55;
const int MAXM=1026;
int s[MAXM];
int cake[MAXN],fcake[MAXN];
int mouth[MAXM];
int n,m;
int sum;
int waste,mid;
int ans;

void init()
{
	read(n);	
	cout<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		read(cake[i]);
		sum+=cake[i];
	}
	read(m);
	for(int i=1;i<=m;i++)
		read(mouth[i]);
	sort(mouth+1,mouth+m+1);
	for(int i=1;i<=m;i++)
		s[i]=s[i-1]+mouth[i];
}

void first_init()
{
	waste=0;
	for(int i=1;i<=n;i++)
		fcake[i]=cake[i];
}

bool dfs(int k,int cur)
{
	if(k<=0)
		return 1;
	if(sum-waste<s[mid])
		return 0;
	for(int i=cur;i<=n;i++)
		if(fcake[i]>=mouth[k])
		{
			fcake[i]-=mouth[k];
			if(fcake[i]<mouth[1])
				waste+=fcake[i];
			if(mouth[k]==mouth[k-1])
			{
				if(dfs(k-1,i))
					return 1;
			}
			else	if(dfs(k-1,1))
				return 1;
			if(fcake[i]<mouth[1])
				waste-=fcake[i];
			fcake[i]+=mouth[k];
		}
	return 1;
}

void work()
{
	while(sum<s[m])
		m--;
	int l=0,r=m;
	while(l<=r)
	{
		first_init();
		mid=(l+r)>>1;
		if(dfs(mid,1))
		{
			l=mid+1;
			ans=max(ans,mid);
		}
		else
			r=mid-1;
	}
	out(ans);
	system("pause");
	exit(0);
}

int main()
{
	init();
	work();
}
     