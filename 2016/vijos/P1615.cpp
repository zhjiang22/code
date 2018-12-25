/*
贪心即可，对于中间的每一个山的高度，若：
1.该山比左右两山都更高，则与其从左山上山右下山(必然会浪费重复体力),
不如直接将中间山变矮，可以保证解更优*；先求出左右两山最高值，
将中间山变为此值高度即可，而变为更低山必然浪费体力。
2.该山比左右两山都更矮，则同理，将其变为左右两山的最小值即可。
处理完后，用魔法消耗的体力+一遍循环即可找出答案（abs）
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

long long a[100002];
long long n;
long long ans;

int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=2;i<n;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])
		{
			long long x=max(a[i-1],a[i+1]);
			ans+=(a[i]-x);
			a[i]=x;
		}
		else if(a[i]<a[i+1]&&a[i]<a[i-1])
		{
			long long x=min(a[i+1],a[i-1]);
			ans+=(x-a[i]);
			a[i]=x;
		}
	}
	for(long long i=1;i<n;i++)
		ans+=abs(a[i+1]-a[i]);
	cout<<ans<<endl;
	return 0;
}
     