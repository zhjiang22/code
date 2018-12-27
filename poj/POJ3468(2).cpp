#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

#define LL long long
const int MAXN=100005;
LL a[MAXN];
LL sum[MAXN];
LL addv[MAXN];
int n,m,size;

inline int get_idx(const int& x)
{
	return (x-1)/size+1;
}

inline int get_left(const int& x)
{
	return (x-1)*size+1;
}

inline int get_right(const int& x)
{
	return min(n,x*size);
}

void init()
{
	memset(sum,0,sizeof(sum));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	size=sqrt(n);
	for(int i=1;i<=n;i++)
		sum[get_idx(i)]+=a[i];
}

void change(int x,int y,LL d)
{
	int p=get_idx(x);	int q=get_idx(y);
	if(p==q)
	{
		for(int i=x;i<=y;i++)
			a[i]+=d;
		sum[p]+=(y-x+1)*d;
	}
	else
	{
		int pr=get_right(p);	int ql=get_left(q);
		for(int i=x;i<=pr;i++)
			a[i]+=d;
		sum[p]+=(pr-x+1)*d;
		for(int i=ql;i<=y;i++)
			a[i]+=d;
		sum[q]+=(y-ql+1)*d;
		for(int i=p+1;i<q;i++)
			addv[i]+=d;
	}
}

void query(int x,int y)
{
	LL ans=0;
	int p=get_idx(x);	int q=get_idx(y);
	if(p==q)
	{
		for(int i=x;i<=y;i++)
			ans+=a[i];
		ans+=addv[p]*(y-x+1);
	}
	else
	{
		int pr=get_right(p);	int ql=get_left(q);
		for(int i=x;i<=pr;i++)
			ans+=a[i];
		ans+=(addv[p]*(pr-x+1));
		for(int i=ql;i<=y;i++)
			ans+=a[i];
		ans+=(addv[q]*(y-ql+1));
		for(int i=p+1;i<q;i++)
			ans+=(sum[i]+(get_right(i)-get_left(i)+1)*addv[i]);
	}
	printf("%lld\n",ans);
}

void work()
{
	char c;
	int x,y;
	LL z;
	while(m--)
	{
		cin>>c;
		if(c=='C')
		{
			scanf("%d%d%lld",&x,&y,&z);
			change(x,y,z);
		}
		else
		{
			scanf("%d%d",&x,&y);
			query(x,y);
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}
     	