/*
小学奥数？
说啥怕时间不够时限到2s..也是醉了
窝数学差大概说一下思路啦
设f[i]表示切i刀最多能切到多少块
那么有f[1]=1
那么对于f[n]
必然是要在f[n-1]取到最大的情况下再来第n刀
而要分成最多则是要和尽可能多的直线相交~！
那么切第n刀的时候就最多可以与前面n-1条直线相交
两条直线相交可以多出两块
n-1条直线相交可以多出n块
则有f[n]=f[n-1]+n
那么这就是一个直接递推了~
但其实就可以直接用等差数列求和公式了
时间复杂度就直接O(1)
注意n比较大了 n^2肯定就爆int了
所以longlong就好啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

int main()
{
	cin>>n;
	cout<<(long long)n*(n+1)/2+1<<endl;
	return 0;
}
     