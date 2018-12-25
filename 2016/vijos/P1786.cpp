/*
发现自己果然是数学不好。想了半天怎么样不会超时
呵呵哒
原来既然是两个数相乘，不要被题目骗了啦~
找大的一定超时，我们找到小的然后除一下大的就出来了
*/
#include <iostream>
#include <cmath>
using namespace std;

int n;

int main()
{
	cin>>n;
	int i;
	for(i=2;i<=sqrt(n)&&n%i!=0;i++);
	cout<<n/i<<endl;
	return 0;
}