/*
炒鸡经典的贪心了吧
题目着重说明纸牌总数是n的倍数是有意图的= =
对于一组牌
我们直接先求出平均值来
然后每堆牌都减去这个平均值
就会出现有正有负数
然后我们就相当于要怎么移动这些数
让它们最后和为0
QAQ我们可以想到负数其实也是可以移动的
因为我们将一个负数从左移动到右边
就相当于将一个正数(多余的牌)从右移动到左
等效的只是为了更好理解
然后我们就贪心吧
不用说就像模拟一样
考虑到每一堆牌
就直接不断移到右边使自己变成0就好了
即
为了使每堆纸牌一样多，总和上面的条件，最好的情况当然是每堆都是平均数
然后利用差分思想，ci表示第i堆纸牌数-平均数
由于开头和结尾只能向右传递，所以我们可以贪心的认为每张纸牌都向右传递
ci就利用到了，如果ci没有摆好，那就给后面的纸牌，记录一次
然后就直接解决了
So easy~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[102];
int n,sum=0;

int main()
{
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	int tot=sum/n;
	for(int i=1;i<=n;i++)
		a[i]-=tot;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		{
			a[i+1]+=a[i];
			ans++;
			a[i]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
     