/*
贪心~！
下面给出别人的证明了~
{
贪心法，每次选代价最大的行获列来切。
设已经沿着列割了a刀，沿着行割了b刀。则将所有巧克力块沿
代价为x的列切开的总代价为x(b+1)，沿
代价为y的行切开的总代价为y(a+1)
易知，先切代价较小的行最后得到的总代价一定不会比先切代价较大的行最后得到的总代价小
所以代价较大的行应该先切(列同理)
现在假设代价最大的列代价为x，代价最大的行代价为y。(为了方便先不讨论切割其他行和列的情况)
那么先切x再切y的代价和 S1=x(b+1)+y(a+2)=xb+x+ya+y2
先切y再切x的代价和S2=y(a+1)+x(b+2)=xb+x2+ya+y
S1-S2得到 y-x 所以当y>x时 S1-S2>0 所以 S2的代价较小 也即先切y再切x的代价较小
同理 x>y时 先切x再切y的代价较小
将上面2点统一起来，就是每次都选择代价较大的行、列来切
}
这样我们只需要将行的代价和列的代价分别排序
然后用归并排序一样的方法每次选最大的来切割~
同时维护一个行已经分成了多少块
就可以很轻松AC了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
int a[MAXN],b[MAXN];
int line,list;
long long ans;
int n,m;
int T;

inline bool cmp(const int& a,const int& b)
{
	return a>b;
}

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<m;i++)
		scanf("%d",&b[i]);
	line=list=1;
	ans=0;
}

void work()
{
	sort(a+1,a+n,cmp);
	sort(b+1,b+m,cmp);
	int p=1,q=1;//p为行下标,q为列下标
	while(p<n||q<m)
	{
		if(p>=n&&q<m)
			ans+=b[q++]*line;
		else	if(q>=m&&p<n)
			ans+=a[p++]*list;
		else	if(a[p]>b[q])
		{
			ans+=a[p++]*list;
			line++;
		}
		else
		{
			ans+=b[q++]*line;
			list++;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	cin>>T;
	while(T--)
	{
		init();
		work();
	}
	return 0;
}
     