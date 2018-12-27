/*
数学推理题~
当且仅当n和m互质并且n与m奇偶性不同时才可遍历所有点~
即(gcd(n,m)==1&&(n+m)%2==1)
其实可以打个表找规律
弱弱的窝来个数学证明吧
首先我们看到
设马向一个方向跳了x次而另一种非反方向跳法跳了y次
那么有马可到位置的集合S为{(xm+yn),(xn+my)}
如果n,m不是互质的话
设他们的最大公因数为x
那么必然横纵坐标都可以提出一个x
说明马能跳到的地方只有公约数倍数的点
这个很简单
我们再看
如果m n奇偶性相同的话
那么xm+yn和xn+my奇偶性必然也相同~
这样的话就只能跳到横纵坐标奇偶性相同的点上了
所以必然不能遍历所有的点
窝讲的可能不太好
所以还是贴个真神犇的证明叭~
{
如果a,b不互质显然不能完成任务。
如果a,b同奇数，那么它不可能走到坐标(x,y)是一奇一偶的点。
下证明如果a,b不互质，且是一奇一偶那么能遍历完棋盘。
我们构造一种走法。
我们让马按如下方式跳三步：
先跳(a,b)，再跳(-b,a)，再跳(-b,-a)。
此时到达了(a-2b,b)，我们可以把原马(a,b)变成新马(a-2b,b)。
此时|a-2b|<b
因为如果a-2b是正的，且b<a-2b<2b，那么我们再减2b，它就是-b<a-2b-2b<0了。
这时，|a-2b|<b
故此时(a,b)的规模缩小，一直缩小下去，由于数是有限的，最终会缩小到1。
如果是(1,k)的话，由于每次减去的都是偶数，不会影响坐标的奇偶性，故此时还是一奇一偶，即k为偶数。
我们还是可以继续按上面这么做：(1,k)的等价马是(1,k-2)
一直可以到达边界(1,2)这是可以走遍棋盘的。
而如果是(a,b)都是奇数的话，最终的边界就是(1,1)并不能走遍棋盘。
故证完。
}
判断互质直接欧几里得算法辗转相除求出最大公约数
判断是否是1即可
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int k;
int n,m;

int gcd(int n,int m)
{
	return m==0?n:gcd(m,n%m);
}

int main()
{
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&n,&m);
		if(gcd(n,m)==1&&(n+m)%2)
			cout<<'y';
		else
			cout<<'n';
	}
}
     