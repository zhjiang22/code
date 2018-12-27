/*
不太会啊，是动态规划？
神犇啊，只能老老实实地打暴力了
按照NOIP2008那道火柴棒等式写了个百分之二十的数据
感觉这是省选难度了吧
坑爹
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int z[10]={6,2,5,5,4,5,6,3,7,6};
int t,n,m;
int cases;

int f(int x)
{
	if(x==0)
		return 6;
	int ans=0;
	while(x)
	{
		ans+=z[x%10];
		x/=10;
	}
	return ans;
}

int main()
{
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=4100;i++)
			for(int j=1;j<i;j++)
			{
				int x=f(i);	int y=f(j);
				if(x+y>n-4)
					continue;
				int k=f(i-j);
				if(k+x+y+3==n)
					ans++,ans%=m;
			}
		cout<<"Case #"<<++cases<<": "<<ans<<endl;
	}
	return 0;
}
     