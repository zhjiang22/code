/*
这是一道经典的贪心算法题目了~
看完题目仔细想一想，其实输入的点中横坐标并没有啥用，真正决定距离的就是纵坐标
所以我们输入的时候可以直接跳过横坐标接受纵坐标就好啦
那么接下来我们按纵坐标从小到大排序
1.如果n为偶数，那么在a[n/2]和a[n/2+1]范围中(包括这两个位置)其实都可以得到最优解
2.如果n为奇数，那么必然要选取中间的这条线了，即a[(n+1)/2]
为了编程方便咯，那我们可以合并这两种情况
不管n的奇偶性，我们都选取a[(n+1)/2](利用自动取整)即可
然后循环累加和即可
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int a[10005];
int n,ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%*d%d",&a[i]);
	sort(a+1,a+n+1);
	int x=a[(n+1)/2];
	for(int i=1;i<=n;i++)
		ans+=abs(a[i]-x);
	cout<<ans<<endl;
	return 0;
}
     