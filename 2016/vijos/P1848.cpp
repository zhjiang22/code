/*
枚举区间内所有的数
然后分解得到每位上的数
统计一下就好
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int ans=0;
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		int x1=i;
		while(x1)
		{
			if(x1%10==x)
				ans++;
			x1/=10;
		}
	}
	cout<<ans<<endl;
	return 0;
}
     