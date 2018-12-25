/*
贪心~
我们首先按照惩罚从大到小排个序~
这样我们可以尽可能保证可以让惩罚大的做完
接下来我们用一个v[i]数组表示i时刻是否已经安排了事情
这样的话对于从大到小的每一个事件
我们尽可能地放在满足时间的后面来做
如果被冲突就往前推~
如果全被冲突了
那么久ans+=惩罚
这样一定是最优的~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=505;
struct P
{
	int t,w;
	bool operator<(const P& b)const
	{
		return w>b.w;
	}
}a[MAXN];
bool v[MAXN];
int ans;
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].t);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].w);
}

void work()
{
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		bool ok=0;
		for(int j=a[i].t;j>=1;j--)
			if(!v[j])
			{
				ok=1;	v[j]=1;
				break;
			}
		if(!ok)
			ans+=a[i].w;
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
}
     