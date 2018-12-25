/*
这题是个很好的找规律练习题。。这里说的找规律当然不是人工暴力的去算。。而是先写个DP去找。。
首先我们要明确3根塔和4根塔本质的不同：3根塔时。。由于最下面那个盘子是最大的。。所以可以对上面的盘子进行递推。。4根塔时。。不管怎样挪移。。
最小的盘子所在的那根柱子是无法使用的。。也就是说我们只能使用3根。。所以状态转移很明显了：
f[i]=min(f[j]*2+g)。。其中f[i]表示4根塔的最小移动步数。。g[i]表示3根塔的最小移动步数。。
但是O(n^2)级别显然无妨应付本题数据。。所以去打个n<=10的表吧。。就可以看出规律了。。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int Ca=10000;
int	dp[50001];
int n;

int main()
{
	cin>>n;
	dp[1]=1;
	int d=2,r=2,t=2;
	for(int i=2;i<=n;i++)
	{
		dp[i]=(dp[i-1]+d)%Ca;
		if(r>1)
			r--;
		else
		{
			d=(d<<1)%Ca;
			t++;
			r=t;
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
     