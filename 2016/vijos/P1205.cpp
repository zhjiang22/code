/*
有趣的题目Orz
我们先来看第一问	很明显是一个LIS嘛
准确地说就是最长下降子序列咯
然后我们就可以直接O(n^2)裸求第一问
然后我们来考虑第二问了
我们要求的是没有相同方案的最长的方案
这个相同方案就自己理解一下咯
http://www.docin.com/p-647424597.html
看到一个蛮好的题解的
不过感觉讲的有点啰嗦呀
我来说说我的理解吧
我们用f[i]表示以i结尾的最大公共子序列的长度
用p[i]表示以i结尾的最长公共子序列的方案数
这样我们只需要在计算f[i]的时候顺带将p[i]更新就好了
怎么更新呢？
其实炒鸡简单啊
我们先来看一下初值问题
和LIS问题一样我们可以先虚设一个a[0]
有a[0]=INF p[0]=1(这个自己想一想为什么)
当然我们也可以不用设置这个虚点
直接初始化f[i]=1 p[i]=1
然后在从1-i-1寻找一个连接子段来更新f[i]的时候
如果碰到a[i]==a[j]
那么我们就将p[i]先置为0再继续寻找j
这是为了满足题目中的要求的是不同的方案数
我们就拿样例后面的提示中的2 2 1来说
如果在第二个2扫描的时候扫到前面那个2不将p[i]置为0
那么对于最后一个1扫描到前面的两个2
他就会加上两个1了变成了方案数有2
这就错了
意思就是我们对于前面已经有一个相同的数了
所以对于后面扫描的数来说
这两个数都是前面的数	接在两个后面都是等效的(如果两个数的f[]相同)
这样就避免了这样的情况
如果找到满足的j有a[j]>a[i]
说明可以接上去
这个时候分三种情况
如果f[i]==f[j]+1
说明以i结尾的LIS又多了一个接法
所以我们有p[i]+=p[j]
而如果f[i]<f[j]+1
这个时候f[i]被更新了
那么自然p[i]也要被更新为p[j]
然后我们记录下最长子序列的长度
再找到所有i点满足f[i]==ans的点
方案数相加就是答案了
其实挺简单的
对方案数和转移的理解考验了一下
蛮好的题目
蛮弱的窝
OTZ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=3005;
const int INF=0x7fffffff;
const int MOD=10000;
int f[MAXN];
int p[MAXN];
long a[MAXN];
int n,m;
int ans,tot;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		f[i]=1;	p[i]=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]==a[j])
			{
				p[i]=0;
				continue;
			}
			if(a[j]>a[i])
				if(f[i]==f[j]+1)
					p[i]=(p[i]+p[j])%MOD;
				else	if(f[i]<f[j]+1)
					p[i]=p[j],f[i]=f[j]+1;
		}
		if(f[i]>ans)
			ans=f[i];
	}
	for(int i=1;i<=n;i++)
		if(f[i]==ans)
			tot=(tot+p[i])%MOD;
	cout<<ans<<" "<<tot<<endl;
	return 0;
}
     