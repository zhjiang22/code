#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=66;
int a[MAXN],s[MAXN];
bool v[MAXN];
int sum,maxl;
int l,tot;
int n;

inline bool cmp(const int& a,const int& b)
{
	return a>b;
}

void init()
{
	int p,x;
	scanf("%d",&p);
	for(int i=1;i<=p;i++)
	{
		scanf("%d",&x);
		if(x>50)	continue;
		a[++n]=x;
		sum+=x;	maxl=max(maxl,x);
	}
	sort(a+1,a+n+1,cmp);
}

void dfs(int cnt,int nowl,int p)//当前考虑的木棒
{
	if(nowl==l)
	{
		nowl=0;
		cnt++;
		p=1;
	}
	if(l-nowl<a[n])
		return;
	if(cnt==tot+1)
	{
		cout<<l<<endl;
		exit(0);
	}
	for(int i=p;i<=n;i++)
		if(!v[i]&&nowl+a[i]<=l)
		{
			if(a[i]==a[i-1]&&!v[i-1])
				continue;
			v[i]=1;
			dfs(cnt,nowl+a[i],i);
			v[i]=0;
			if(s==0)
				return;
		}
}

void work()
{
	for(int i=maxl;i<=sum;i++)
		if(sum%i==0)
		{
			l=i;	tot=sum/i;	v[1]=1;
			dfs(1,a[1],1);
		}
}

int main()
{
	init();
	work();
}
     