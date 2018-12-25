/*
找规律~	其实可以直接找规律然后就能发现答案有周期性
当n=1,2,3,4,5,6,7,8……时，对应的输出是1,1,0,0,1,1,0,0……
下面给出数学证明
{
我们知道，连续的四个整数可以让其和为0。-n+(n+1)+(n+2)-(n+3)=0。
所以我们把1到n个数从后往前分成n div 4份。若n为5则1(-2+3+4-5)＝1
N=10则-1+2(-3+4+5-6)(-7+8+9-10)＝1
当然n mod 4=0时和就为0。
于是我们要计算出n mod 4的值，只要计算1..n mod 4的最小非负值
（n mod 4+1…n这些数的和为0，不用管它们）。那么需要高精度除法吗？
不！若n>=100，我们设n=100a+b|b<100，前面的100a mod 4必=0，不用考虑，于是要计算n mod 4，
只要计算n的最后两位(就是b)mod 4就行了！最后在根据mod出来的余数进行特判：
N mod 4=0:ans=0
N mod 4=1:ans=1
N mod 4=2:ans=-1+2=1
N mod 4=3:ans=-1-2+3=0
}
然后直接搞就行了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long n;

int main()
{
	scanf("%d",&n);
	if(n%4==1||n%4==2)
		cout<<1<<endl;
	else
		cout<<0<<endl;
	return 0;
}
     