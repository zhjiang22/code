/*
此题简单模拟，但也有细节要注意：
1.人数有可能为0，在处理剩余钱时要判断人数是否为0，
不然会出现除以0的情况
2.老问题了，可能是做题少，双重循环的自加条件，
总是容易将内循环自加写成外循环自加
3.注意num数组的找分钱人时的方法
总而言之，虽然这类题目简单，但竟然还做了很久，
应该多做点题锻炼一下基础能力了，不能贪图高级算法了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

struct node
{
	string name;
	int out,friends,in;
	int num[11];
}a[12];
int n;

int find(string b)
{
	for(int i=1;i<=n;i++)
		if(a[i].name==b)
			return i;
	return 0;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].name;
	string b;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		int x=find(b);
		cin>>a[x].out>>a[x].friends;
		for(int j=1;j<=a[x].friends;j++)
		{
			cin>>b;
			a[x].num[j]=find(b);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].friends==0)
			continue;
		int k=a[i].out/a[i].friends;
		a[i].out=k*a[i].friends;
		for(int j=1;j<=a[i].friends;j++)
			a[a[i].num[j]].in+=k;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i].name<<" "<<a[i].in-a[i].out<<endl;
	return 0;
}
     