#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1000005;
const int MAXK=105;
const int INF=0x7ffffff;
struct node
{
	int x,c;
}a[MAXN];
int cnt[MAXK];
int n,k;
int tot;
int ans;

inline bool cmp(const node a,const node b)
{
	return a.x<b.x;
}

void init()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].c);
	sort(a+1,a+n+1,cmp);
	ans=INF;
}

int main()
{
	init();
	int l=1,r=0;
	while(r<n)
	{
		while(tot<k&&r<n)
		{
			r++;
			if(!cnt[a[r].c])
				++tot;
			cnt[a[r].c]++;
		}
		if(tot==k)
			ans=min(ans,a[r].x-a[l].x);
		while(tot==k&&l<=r)
		{
			if(--cnt[a[l].c]==0)
				--tot;
			++l;
			if(tot==k)
				ans=min(ans,a[r].x-a[l].x);
		}
	}
	if(ans==INF)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
     