/*
数据还是很水的.....
直接暴力朴素做法就可以A了~
我们来看到这个亲和数的定义
我们很容易想到直接暴力枚举x
然后再求出他的所以非自身因子的总和
如果这个总和k<=i那么直接说明不可行结束这次i循环
然后我们对于这个因子和k肯定就是对应的y了
那么我们判断一下y可不可以满足对x的条件了
还是直接暴力枚举因子
(注意枚举的时候最好不要把sqrt放在循环中去而是直接算出来或者用j*j<=k
这样的话可以提高一定的效率)
然后判断一下总和加起来可行与否~
其实感觉用素数筛法会更快？但是好像有人说并没有更快...
反正数据水直接暴力就行啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a,b;
int ans;

int main()
{
	cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		int k=1;
		for(int j=2;j*j<=i;j++)
			if(i%j==0)
				k+=i/j+j;
		if(k<=i)	continue;
		int p=1;
		for(int j=2;j*j<=k;j++)
			if(k%j==0)
				p+=j+k/j;
		if(p==i)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
     