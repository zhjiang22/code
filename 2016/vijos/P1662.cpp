/*
很裸的贪心了
我们知道的
如果要使差值最大	必然是要让最小的和最大的匹配
所以我们可以直接把a b排个序
每次拿a的最大的和b的最小的	或者b的最大的和a的最小的
两个差值一比取更优者
以此反复直到选到k次
WA了一次原因是ans没有开到Long long
OTZ害怕啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
int a[MAXN],b[MAXN];
int n,k;
long long ans;

inline bool cmp(const int& a,const int& b)
{
	return a>b;
}

void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
}

int main()
{
	init();
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	int l=1,r=n;
	while(k--)
	{
		if(abs(a[l]-b[l])>=abs(a[r]-b[r]))
		{
			ans+=abs(a[l]-b[l]);
			l++;
		}
		else
		{
			ans+=abs(a[r]-b[r]);
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
     