#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN=40005;
const int MAXT=10005;
int zhongshu[MAXT][MAXT];
struct P
{
	int idx;
	int x;
	int se;
}a[MAXN];
int n,m;
int T,size;

int Hash[MAXN];
int b[MAXN];
int Back[MAXN];
int cnt;

inline bool cmp1(const P& a,const P& b)	{return a.x<b.x;}

inline bool cmp2(const P& a,const P& b)	{return a.idx<b.idx;}

void discretization()
{
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		a[i].se=a[i-1].se;
		if(a[i].x!=a[i-1].x)
			a[i].se++;
		b[a[i].se]=a[i].x;
	}
	sort(a+1,a+n+1,cmp2);
}

int Count[MAXN];

inline int get_T(const int& x)
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

std::vector<int> v[MAXN];

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);
		a[i].idx=i;
	}
	discretization();
	T=sqrt(m*log(n));
	size=n%T?n/T+1:n/T;
	for(int i=1;i<=T;i++)
	{
		int lastzhongshu=0;
		memset(Count,0,sizeof(Count));
		for(int j=i;j<=T;j++)
		{
			for(int k=get_left(j);k<=get_right(j);k++)
			{
				Count[a[k].se]++;
			}
			for(int k=get_left(j);k<=get_right(j);k++)
			{
				if(lastzhongshu==0)
					lastzhongshu=k;
				else	if((Count[a[k].se]>Count[a[lastzhongshu].se])
					||(Count[a[k].se]==Count[a[lastzhongshu].se]&&a[k].x<a[lastzhongshu].x))
					lastzhongshu=k;
			}
			zhongshu[i][j]=lastzhongshu;
		}
	}
	for(int i=1;i<=n;i++)
		v[a[i].se].push_back(i);

}

int get_count(int x,int l,int r)
{
	return upper_bound(v[x].begin(),v[x].end(),r)-lower_bound(v[x].begin(),v[x].end(),l);
}

int query(int l,int r)
{
	int p=get_T(l);	int q=get_T(r);
	if(q-p<=1)
	{
		int maxd=0;
		int ans=0;
		for(int i=l;i<=r;i++)
		{
			int k=get_count(a[i].se,l,r);
			if(k>maxd||(k==maxd&&a[i].x<ans))
			{
				maxd=k;
				ans=a[i].x;
			}
		}
		return ans;
	}
	else
	{
		int x=zhongshu[p+1][q-1];
		int pr=get_right(p);	int ql=get_left(q);
		int maxd=0;
		int ans=0; 
		for(int i=l;i<=pr;i++)
		{
			int k=get_count(a[i].se,l,r);
			if(k>maxd||(k==maxd&&a[i].x<ans))
			{
				maxd=k;
				ans=a[i].x;
			}
		}
		for(int i=ql;i<=r;i++)
		{
			int k=get_count(a[i].se,l,r);
			if(k>maxd||(k==maxd&&a[i].x<ans))
			{
				maxd=k;
				ans=a[i].x;
			}
		}
		int k=get_count(a[x].se,l,r);
		if(k>maxd||(k==maxd&&a[x].x<ans))
			{
				maxd=k;
				ans=a[x].x;
			}
		return ans;
	}
}

void work()
{
	int x=0;
	int l,r;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		l=(l+x-1)%n+1;	r=(r+x-1)%n+1;
		if(l>r)	swap(l,r);
		printf("%d\n",x=query(l,r));
	}
}

int main()
{
/*	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);*/
	init();
	work();
	return 0;
}
     