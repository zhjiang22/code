#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;
int cnt[MAXN];
int maxh,minh;
int n,k;

void init()
{
	cin>>n>>k;
	int h;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h);
		cnt[h]++;
		maxh=max(maxh,h);
		minh=i==1?h:min(minh,h);
	}
}

int m;
void work()
{
	int ans=0;
	long long s=0,last=0;
	//last-当前消到这需要累计的量
	//s当前累积的柱子数量
	for(int i=maxh;i>minh;i--)
	{
		if(cnt[i]+s+last<=k)
		{
			last+=s+cnt[i];
			s+=cnt[i];
			continue;
		}
		ans++;
		last=cnt[i]+s;
		s+=cnt[i];
	}
	if(last)
		ans++;
	printf("%d\n",ans);
}

int main()
{
	init();
	work();
	return 0;
}