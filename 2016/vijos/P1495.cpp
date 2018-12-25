/*
嗯两个月前写的代码
撸过来解决一下每日比水
直接模拟计数排序思想统计个数
再判断素数就好了
注意细节
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[30];
char b[102];

int isdp(int n)
{
	if(n==0)
	return 0;
	if(n==1)
	return 0;
	else for(int i=2;i<=(n/2);i++)
	if(n%i==0)
	return 0;
	return 1;
}

int main()
{
	gets(b);
	int max1=0;
	int min1=123456;
	memset(a,0,sizeof(a));
	int x=strlen(b);
	for(int i=0;i<x;i++)
	a[b[i]-'a']++;
	for(int i=0;i<30;i++)
	{if(a[i]!=0)
	{
	max1=max(max1,a[i]);
	min1=min(min1,a[i]);
	}
	}
	if(isdp(max1-min1))
	{
	    cout<<"Lucky Word"<<endl;
	    cout<<max1-min1;
	}
	else 
	{
	    cout<<"No Answer"<<endl;
	    cout<<"0";
	}
	return 0;
}