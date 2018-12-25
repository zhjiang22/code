/*
好水的模拟题OTZ
我们可以直接用位运算来做
于是有了高大上写法
而我这种弱弱只能模拟进制转换来做了
唉我好弱啊
注意这里要用unsigned int而不是int
不然会爆负
*/
/*
高大上写法Orz
#include <iostream>
using namespace std;
unsigned long int n;
int main()
{
    cin>>n;
    cout<<((n << 16) | (n >> 16))<<endl;
}
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[33];
unsigned int ans;
int k;
int l;

int main()
{
	cin>>k;
	while(k)
	{
		a[++l]=k%2;
		k/=2;
	}
	for(int i=1;i<=16;i++)
		swap(a[i],a[i+16]);
	for(int i=1;i<=32;i++)
		ans+=(1<<(i-1))*a[i];
	cout<<ans<<endl;
	return 0;
}
     