#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=50;
int a[MAXN];
int v[MAXN];
int len,cnt;
int sumv;
int n;
int t;

inline bool cmp(const int& a,const int& b)
{
	return a>b;
}

void init()
{
	memset(v,0,sizeof(v));
	sumv=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sumv+=a[i];
	}
	sort(a+1,a+n+1,cmp);
}

bool dfs(int cur,int done,int last)
{
	if(cur>=cnt)
	{
		return 1;
	}
	if(done==len)
		return dfs(cur+1,0,1);
	int fail=0;
	for(int i=last;i<=n;i++)
		if(done+a[i]<=len&&!v[i]&&a[i]!=fail)
		{
			v[i]=1;
			if(dfs(cur,done+a[i],i+1));
				return 1;
			fail=a[i];
			v[i]=0;
			if(!done)
				return 0;
		}
	return 0;
}

void work()
{
	if(sumv%4||a[0]>(sumv/4))
	{
		printf("no\n");
		return;
	}
	cnt=4;
	len=sumv/cnt;
	if(dfs(1,0,1))
		printf("yes\n");
	else
		printf("no\n");
}

int main()
{
	cin>>t;
	while(t--)
	{
		init();
		work();
	}
	return 0;
}