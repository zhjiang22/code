/*
和P10120一模一样~
重题OTZ...
看那篇题解啦~
又练习了一遍~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
const int MAXM=55;
int have[MAXM],fhave[MAXN];
int need[MAXN];
int sum,s[MAXN];
int m,n;
int mid;
int waste;
int ans;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&have[i]);
		sum+=have[i];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&need[i]);
	sort(have+1,have+n+1);
	sort(need+1,need+m+1);
	for(int i=1;i<=m;i++)
		s[i]=s[i-1]+need[i];
}

bool dfs(int k,int cur)
{
	if(k<=0)
		return 1;
	if(sum-waste<s[mid])
		return 0;
	for(int i=cur;i<=n;i++)
		if(fhave[i]>=need[k])
		{
			fhave[i]-=need[k];
			if(fhave[i]<need[1])
				waste+=fhave[i];
			if(need[k]==need[k-1])
			{
				if(dfs(k-1,i))
					return 1;
			}
			else	if(dfs(k-1,1))
				return 1;
			if(fhave[i]<need[1])
				waste-=fhave[i];
			fhave[i]+=need[k];
		}
	return 0;
}

void work()
{
	while(sum<need[m])
		m--;
	int l=0,r=m;
	while(l<=r)
	{
		waste=0;
		for(int i=1;i<=n;i++)
			fhave[i]=have[i];
		mid=(l+r)>>1;
		if(dfs(mid,1))
			l=mid+1,ans=max(ans,mid);
		else
			r=mid-1;
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
}
     