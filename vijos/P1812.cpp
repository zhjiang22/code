/*
模拟咯~
只要小心就好了~！
说实话样例蛮坑的故意x^1系数为0
然后直接傻逼了一下没注意到
WA一次20分
然后猛然发现~
看来做这种基础题还是要小心一点不能大意~！
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int a[MAXN];
int n;
bool fisrt;

void init()
{
	scanf("%d",&n);	n++;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			continue;
		if(i==n)
		{
			if(!a[i])
				break;
			if(a[i]>0)
				cout<<"+"<<a[i];
			else
				cout<<a[i];
			break;
		}
		if(fisrt&&a[i]==-1)
			cout<<'-';
		else	if(fisrt&&a[i]==1)
			cout<<"+";
		else	if(fisrt&&a[i]>0)
			cout<<"+"<<a[i];
		else	if(fisrt)
			cout<<a[i];
		else
		{
			fisrt=1;
			if(a[i]==-1)
				cout<<'-';
			else	if(a[i]==1);
			else
				cout<<a[i];
		}
		if(i!=n-1)
			cout<<"x^"<<n-i;
		else
			cout<<'x';
	}
}