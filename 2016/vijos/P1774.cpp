/*
直接模拟一下就好了
用一个类似于队列一样的数组来做这个内存空间
然后这个数字都是1000以内
所以就可以用一个计数排序一般的方法
来标记某个数是否在内存内
如果不在就加入内存中
依次反复就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=1005;
int q[MAXN];
int v[MAXN];
int n,m;
int cur;
int ans;

int main()
{
	int x;
	memset(q,-1,sizeof(q));
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(v[x])
			continue;
		if(q[cur]!=-1)
			v[q[cur]]=0;
		v[x]=1;
		q[cur++]=x;	cur%=m;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
     