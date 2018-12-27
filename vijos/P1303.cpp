/*
一道再经典不过的LIS了
第一问就不想多说了裸的LIS
第二问其实就是运用了一个定理
即Dilworth定理
最少链划分 = 最长反链长度
最少系统 = 最长导弹高度上升序列长度
所以直接再做一遍LIS就好了
OTZ%%%%%%%%%%%%%%%%%%%%%%%%%%
当然第二问还有贪心的做法
怎么贪?	肯定不是按着LIS去打
这样很明显有反例
而是我们可以先打一个序列中最高的
因为早晚都要打	而且肯定是不能在别的导弹的后面打
打完这个我们打什么？
顺手打一下他后面的最高的导弹
打一定比不打好
以此反复
这就是贪心思路
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[3005];
int f[3005];
int n=1;

int main()
{
	int x,Max=-10,ans=-10;
	while(cin>>x)
		a[n++]=x,getchar();
	n--;
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
			if(a[i]<=a[j])
				f[i]=max(f[i],f[j]+1);
		Max=max(Max,f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
			if(a[i]>=a[j])
				f[i]=max(f[i],f[j]+1);
		ans=max(ans,f[i]);
	}
	cout<<Max<<","<<ans-1<<endl;
	return 0;
}
     