#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;

#define UI unsigned int
const UI MAXN=50;
const UI MAXM=(1<<25);
UI a[MAXN];
UI b[MAXN];
UI C[MAXM];
UI W,n,m;
UI cnt;
UI ans;

inline bool cmp(const int& a,const int& b)
{
	return a>b;
}

void init()
{
	cin>>W>>n;
	m=(n/2);
	for(UI i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(UI i=m+1;i<=n;i++)
		b[i-m]=a[i];
	/*for(UI i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(UI i=1;i<=(n-m);i++)
		scanf("%d",&b[i]);*/
}

void pre_dfs(UI cur,UI s)
{
	C[++cnt]=s;
	if(cur>m)
		return;
	pre_dfs(cur+1,s);
	if(s+a[cur]<=W)
		pre_dfs(cur+1,s+a[cur]);
}

UI binary_find(UI x)
{
	UI l=1,r=cnt;
	while(l<r)
	{
		UI mid=(l+r+1)>>1;
		if(C[mid]<x)
			l=mid;
		else
			r=mid-1;
	}
	return C[l];
}

UI D[MAXM];
int Cnt;

void nxt_dfs(UI cur,UI s)
{
	D[++Cnt]=s;
	if(cur>n-m)
		return;
	if(s+b[n-m]>W)
		return;
	nxt_dfs(cur+1,s);
	if(s+b[cur]<=W)
		nxt_dfs(cur+1,s+b[cur]);
}

void work()
{
	pre_dfs(1,0);
	sort(C+1,C+cnt+1);
	cnt=unique(C+1,C+cnt+1)-(C+1);
	nxt_dfs(1,0);
	Cnt=unique(D+1,D+Cnt+1)-(D+1);
	for(int i=1;i<=Cnt;i++)
	{
		ans=max(ans,D[i]+binary_find(W-D[i]));
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}