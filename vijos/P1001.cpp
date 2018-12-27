/*
签到题咯~
直接模拟就好
分别计算出每个人的奖学金
然后就AC了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

struct people
{
	string name;
	int qimo,banji;
	char ganbu,xibu;
	int lunwen;
	int ans;
}a[102];
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].name>>a[i].qimo>>a[i].banji>>a[i].ganbu>>a[i].xibu>>a[i].lunwen,a[i].ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].banji>80&&a[i].ganbu=='Y')
			a[i].ans+=850;
		if(a[i].qimo>80&&a[i].lunwen>=1)
			a[i].ans+=8000;
		if(a[i].qimo>85&&a[i].banji>80)
			a[i].ans+=4000;
		if(a[i].qimo>90)
			a[i].ans+=2000;
		if(a[i].qimo>85&&a[i].xibu=='Y')
			a[i].ans+=1000;
	}
	int Max=-1;
	string k;
	int tot=0;
	for(int i=n;i>=1;i--)
	{
		tot+=a[i].ans;
		if(a[i].ans>=Max)
		{
			k=a[i].name;
			Max=a[i].ans;
		}	
	}
	cout<<k<<endl;
	cout<<Max<<endl;
	cout<<tot<<endl;
	return 0;
}
     