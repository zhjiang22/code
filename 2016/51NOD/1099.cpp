#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
struct P
{
	int w,v;
	int b;
	bool operator<(const P& c)const
	{
		return b>c.b;
	}
}a[MAXN];
int n;
int ans;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].w,&a[i].v),
		a[i].b=a[i].w-a[i].v;
}

int main()
{
	init();
	sort(a+1,a+n+1);
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,cur+a[i].w);
		cur+=a[i].v;
	}
	ans=max(ans,cur);
	cout<<ans<<endl;
	return 0;
}
     