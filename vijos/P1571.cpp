/*
一个LIS双重单调性dp，加了一个限制条件：
被抽取出来的导弹奇数位置的编号大于其前一个的编号，偶数位置的编号小于其前一个的编号
还是可以一样做的，同样具有最优子结构性质
我们可以反着思考，题目条件可以等价于
对于奇数位置的编号大于其后一个的编号，偶数位置小于后一个位置的编号
我们定义状态f[i]表示以i结尾的最长的长度-1
所以默认初值为0
那么我们直接推一下就好，因为递归的j是要接在i后面的所以从i开始递推就行了
详细见代码咯
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10010;
int f[MAXN];
int h[MAXN];
int n;
int ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)//j从i向后推
		{
			if(f[i]%2==0)//枚举所有的j尝试能否接上i，f[i]为偶数实际上是奇数位置
 			{
  				if(h[j]<h[i])//下一个位置就是偶数，则有h[j]要小于h[i]
  					f[j]=max(f[i]+1,f[j]);//可以将j接在f[i]对应序列上，所以尝试更新f[j]
 			}
			else if(f[i]%2==1)//同理偶数位置
			{
 			 	if(h[j]>h[i])//j为奇数位置，要比h[i]大
 			 		f[j]=max(f[i]+1,f[j]);//可以接在后面
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i]);//找出所有的最大值
	cout<<ans+1<<endl;//注意f[]初值为0即第一个元素没有算上，所以ans+1
	return 0;
}
     