/*
水题啊	高精度都不用Orz
longlong 就够了
关于 ans:=a*b+a+b
:如果大家都只能一次移一格
那么将所有的x要想右移（b+1）格 和将所有y 左移（a+1）格后 便得到目标状态
这花费了 a*(b+1)+b*(a+1) 次
而实际上是可以一次移两格的不需要这么多次的 
对于每一对x、y 要么x跳过y 要么y跳过x 所以一共跳了a*b次
a*(b+1)+b*(a+1)-a*b=a*b+a+b
*/
#include <iostream>
using namespace std;

int main()
{
	long long a,b;
	cin>>a>>b;
	cout<<a*b+a+b;
	return 0;
}