/*
好题~Orz
不过感觉和动态规划没有什么关系
如果是单独处理1 0
肯定会很难处理
所以我们可以将读入的0全部转换为-1
则男女生人数相同的条件就是子序列和为0咯
即如果s[i]==s[j]
那么这就是一个满足条件的子序列	长度为j-i
这样一想就会很简单了
但是如果我们枚举所有的子序列
那么复杂度达到了O(n^2)
肯定是会超时的
那么我们怎么优化这个算法呢
我们来看	我们用f数组来记录某个序列和的位置
f[i]表示满足s[k]==i的k的最前的一个位置
因为我们知道
如果在后面找到了一个j	
要在前面找一个位置i满足s[i]==s[j]
构成一个满足条件的子序列
那么我们肯定是选择最前面的最好
这个很容易证明吧
所以我们只用记录每个数值最前面的那个数位置就好了
然后f数组初始化为-1
用来判断是否出现过这个数值
如果第一次出现	就记录下这个数组
如果不是第一次出现	就尝试这个长度能否更新答案
这样扫描一遍就好了
复杂度为O(n)
感觉有点像NOIP选择客栈那道题QAQ
弱逼的我还是这么弱逼
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100009;
int n;
int s[MAXN];
int f[MAXN*2];
int ans;

void init()
{
	cin>>n;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(!x)	
			s[i]=s[i-1]-1;
		else
			s[i]=s[i-1]+1;
	}
}

int main()
{
	init();
	memset(f,-1,sizeof(f));
	for(int i=0;i<=n;i++)
	{
		if(f[s[i]+n]!=-1)
			ans=max(ans,i-f[s[i]+n]);
		else
			f[s[i]+n]=i;
	}
	cout<<ans<<endl;
	return 0;
}
