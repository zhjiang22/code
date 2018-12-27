/*
直接枚举区间内所有数，然后循环拆分判断每位上的数是否为2即可
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int cur;
int l,r;
int ans;

int main()
{
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		int cur=i;
		while(cur)
		{
			if(cur%10==2)
				ans++;
			cur/=10;
		}
	}
	cout<<ans<<endl;
	return 0;
}
     