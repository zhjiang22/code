#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=2005;
struct node
{
	int a,b,s;
}p[MAXN];
int c1,c2,c3;
int ans;
int n;

inline bool cmp(const node&a,const node&b)
{
	return a.s<b.s;
}

void init()
{
	scanf("%d",&n);
	scanf("%d%d%d",&c1,&c2,&c3);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].a,&p[i].b);
		p[i].s=p[i].a*c1+p[i].b*c2;
	}
}

int main()
{
	init();
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int a0=p[i].a;	int b0=p[i].b;	int cur=i;
		int tot=0;
		while(p[cur++].s<=c1*a0+c2*b0+c3&&cur<=n)
			tot++;
		ans=max(ans,tot);
	}
	cout<<ans<<endl;
	return 0;
}
     