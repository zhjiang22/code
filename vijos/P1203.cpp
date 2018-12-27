/*
直接贪心就好啦~
脚注紧跟脚注标记所在行，这样肯定是最优的
那么一行行扫描下来，如果当前行（加上脚注）加到当前页超过的话就新建一页。
注意如果最后剩余行数>0，还要新建一页。
直接乱搞就好了~
好像数据很弱~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[MAXN];
int n,k,f;
int ans;

void init()
{
	int x,y;
	cin>>n>>k>>f;
	for(int i=1;i<=n;i++)
		a[i]=1;
	for(int i=1;i<=f;i++)
	{
		cin>>x>>y;
		a[x]+=y;
	}
}

int main()
{
	init();
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(cur+a[i]>k)
			cur=a[i],ans++;
		else
			cur+=a[i];
	}
	cout<<++ans<<endl;
	return 0;
}
     