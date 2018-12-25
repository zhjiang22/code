/*
水题啊	如果一个月前的窝来做这题
一定会蠢纸一样的用个map或者手写hash来做
但是其实这道题有一个很巧妙的性质
即异或的性质有a^a=0
所以如果一个数在数列中出现了两次
那么必然会有经过异或后变为0
那么没有变为0的就必然就是奇数次出现的数了
这个性质很奇妙很好用啊	见到两次了~
那么这道题就很好解决咯~~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long x;
int n;

int main()
{
	cin>>n;
	long long k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		x^=k;
	}
	cout<<x<<endl;
	return 0;
}
     