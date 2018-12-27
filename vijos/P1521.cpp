/*
一开始随机此题	看了一下题目觉得是一道很水的贪心？
然后一看分类结果是网络流？
一阵后怕然后就进了题解区	仔细一看发现贪心是可行的
首先窝们统计一下每个男生和每个女生喜欢的对象的个数
那么我们很明显可以发现
舞会可以持续多久是取决于最不想跳的那个人能跳多久的
即像我们都知道的短板原理
所以我们就直接找到出度最少的人(包括男女生)的出度+k
注意如果这个值比n大是要取n的(因为一个男孩只能和一个女孩跳一次)
所以最多只能跳n次
所以取个最小值即可
然后贪心就直接秒杀了....
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=55;
int b[MAXN];
int g[MAXN];
int ans=0x7fffffff;
int n,k;

void init()
{
	string a;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		for(int j=0;j<n;j++)
			if(a[j]=='Y')
				b[i]++,g[j+1]++;
	}
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		ans=min(ans,min(b[i],g[i]));
	cout<<min(n,ans+k)<<endl;
	return 0;
}
     