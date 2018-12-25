/*
水题模拟~一开始一看到就想
不是裸的压位高精？然后发现a,b范围在Long long内
那不是可以直接做减法？
只需要用unsigned long long保存加过就行了
因为一个long long极限的正数减一个极限的负数
就爆出long long了也是很有可能
但是开个unsigned long long范围两倍是够了的
正负号直接判断大小就好啦~
当然还要特判断一下a=b的时候~Orz
即c答案为0时	根本没有建立字符串。。。
Orz代码写的很丑
只是因为就想用个字符串string哈哈哈
QWQ还有很多搞法咯~直接秒杀~！
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long a,b;
unsigned long long c;

string getstr(unsigned long long x)
{
	int l=0;
	char c[105];
	while(x)
	{
		c[l++]=(x%10)+'0';
		x/=10;
	}
	c[l++]='\0';
	string p(c);
	return p;
}

int main()
{
	cin>>a>>b;
	if(a>b)
		c=a-b;
	else
		c=b-a;
	if(c==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(a<b)
		cout<<"-";
	string p=getstr(c);
	int l=p.length();	int l1=l/3*3;
	for(int i=l;i>l1;i--)
		cout<<p[i-1];
	for(int i=l1;i>=1;i-=3)
		cout<<","<<p[i-1]<<p[i-2]<<p[i-3];
	cout<<endl;
	return 0;
}
     