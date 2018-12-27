/*
一道基础练习题咯~ 一开始想成了还要进制转换
发现做起来太难啦
后来仔细一想根本不需要进制转换啊
直接模拟加法就好
然后判断一下
总体还是很简单的	感觉数据也比较弱
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int k,l;
int b[100];
string a;

bool check()
{
	int left=0,right=l-1;
	while(left<=right)
	{
		if(b[left]!=b[right])
			return false;
		else
		{
			left++;
			right--;
		}
	}
	return true;
}

bool solve()
{
	bool in=0;
	int c[100];
	for(int i=0;i<l;i++)
		c[i]=b[l-i-1];
	for(int i=0;i<l;i++)
	{
		b[i]+=c[i];
		if(i==l-1&&b[i]>=k)
			in=1;
		if(b[i]>=k)
		{
			b[i+1]++;
			b[i]%=k;
		}
	}
	if(in)
		l++;
	if(check())
		return true;
	else
		return false;
}

int main()
{
	cin>>k;
	cin>>a;
	l=a.length();
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			b[l-i-1]=a[i]-'0';
		else
			b[l-i-1]=a[i]-'A'+10;
	}
	if(check())
	{
		cout<<0<<endl;
		return 0;
	}
	else for(int step=1;step<=30;step++)
	{
		if(solve())
		{
			cout<<"STEP="<<step<<endl;
			return 0;
		}
	}
	cout<<"Impossible!"<<endl;
	return 0;
}
     