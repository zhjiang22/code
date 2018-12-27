/*
一道经典记忆化了
看到n这么大有点虚啊
数组开不下就直接map了
复杂度还是大概log^2n的
可以很快过
当然也有数学黑魔法做法
应该可以达到log24n(2*3*4)
但是这个速度已经很快了足够秒杀~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

map<long long,long long> Map;
int T;
long long n;

long long dfs(long long x)
{
	if(Map[x])
		return Map[x];
	if(x<=3)
		return x;
	return Map[x]=max(x,dfs(x/2)+dfs(x/3)+dfs(x/4));
}

int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		if(n<=3)
			cout<<n<<endl;
		else
			cout<<dfs(n)<<endl;
	}
}
     