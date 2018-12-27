/*
考虑到n只有100大小
直接排个序
然后枚举加数判断是否有和两个加数和相同的数即可
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[102];
int n;

int main()
{
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j;k<=n;k++)
				if(a[i]+a[j]==a[k])
					ans++;
		}
	cout<<ans<<endl;
	return 0;
}
     