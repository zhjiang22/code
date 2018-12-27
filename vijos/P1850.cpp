/*
怎么现在普及组的题目坑点这么多
一开始写了个常规递推了
然后莫名TLE4个点是smg
不服啊没改程序重新交一次就WA两个点了QAQ
后来才知道数据很大需要每步取模(超long long也是哭了)
考虑到这个答案要么是第一个小朋友要么是最后一个
(如果全部都是负的那么必然不如不要就是第一个，
否则如果有一个正的那么必然可以递推使得最后一个最大)
即除了第一个小朋友外剩下的小朋友的分数值是不下降的。
所以对于一个小朋友他的分数只有两种情况
1.如果他的前一个小朋友的特征值大于0，
那他的分数就为前一个小朋友的分数加上前一个小朋友的特征值。更新当前最大值
2.如果他的前一个小朋友的特征值小于0，
那他的分数就为第二个小朋友的分数。 
首先我们判断一下答案是最后一个还是第一个
即从a[2]+...+a[n-1]看是否能有>=0的段(==0)
这样就可以先判断出答案是最后一个还是第一个了
如果是第一个直接先输出~
如果是最后一个我们可以直接从c[3]开始递推就好了
递推的时候可以步步取模就不会溢出了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define LL long long
const int MAXN=1000005;
LL a[MAXN];
LL b[MAXN],c[MAXN];
LL ans=-(1<<21);
int n,p;

void init()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
}

int main()
{
	init();
	LL now=max(a[1],0LL);
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		now+=a[i];
		b[i]=max(b[i-1],now);
		now=max(now,0LL);
	}
	c[1]=b[1];	c[2]=c[1]+b[1];
	LL tmp=c[1];
	bool ok=0;
	for(int i=2;i<n;i++)
	{
		tmp+=max(b[i],0LL);
		if(tmp>=0)
		{
			ok=1;
			break;
		}
	}
	if(!ok)
	{
		printf("%d\n",int(c[1]%p));
		return 0;
	}
	for(int i=3;i<=n;i++)
		c[i]=(c[i-1]+max(b[i-1],0LL))%p;
	printf("%d\n",int(c[n]));
	return 0;
}