/*
好题~一个很巧妙的dp~
我们看到因为是有n堆如果和n扯上关系状态很难表示
那么我们可以这么想
我们可以将n堆分别隔离开看作一个单独的个体
然后对齐0/1背包必然可以求出每堆积木抽取若干积木之后
可以达到的高度
但是好像这也不太好处理	难道开一个二维数组分别记录下n堆的情况？
这样太麻烦了
我们可以换个角度想
对于这n堆我们只需要求出他们公共可行部分~
这样的话就转变了只要求出大家都可以达到哪些高度
取最大的就好
这样我们可以用一个f[]来记录每个高度是不是大家都是可行的
对于每次推出的一个g[]表示第i个数组的每个高度的可行性
我们都f[j]&=g[j]
这样最后剩下的f[]如果是可行的
那么必然是大家都共有的~
这个思想很奇妙也很重要经常可能会用到
这里我们的j的从0...sum
sum应该是所有堆的高度总和的最小值
这里我偷了个懒直接从0...10000(题目中100*100)
这样虽然慢了一点但是就懒得储存h[]了
(OTZ时间换空间23333)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXV=11000;
const int MAXN=105;
bool f[MAXV],g[MAXV];
int n;

void init()
{
	scanf("%d",&n);
}

void DP()
{
	for(int i=0;i<=10000;i++)
		f[i]=1;
	for(int i=1;i<=n;i++)
	{
		memset(g,0,sizeof(g));	g[0]=1;	int x=0;
		while(scanf("%d",&x)==1&&x!=-1)
		{
			for(int j=10000;j>=0;j--)
				if(g[j])
					g[j+x]=1;
		}
		for(int j=0;j<=10000;j++)
			f[j]&=g[j];
	}
	for(int j=10000;j>=0;j--)
		if(f[j])
		{
			printf("%d\n",j);
			return;
		}
}

int main()
{
	init();
	DP();
}
     