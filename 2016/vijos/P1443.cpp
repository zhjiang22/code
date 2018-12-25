/*
又是一道并查集的题目，一直很懵逼的一个地方就是昨天做了个并查集求最小环，
也是一直弄不懂getfather函数的里面的顺序，为什么要先递归在更新距离，
今天突然就明白咯~
getfather函数的作用有：
1.找根结点
2.路径压缩
3.更新得出该路径上的点的到根节点的距离
那么我们很容易知道，如果fa[x]==x，则不是根节点
那么我们如果要求出dist[x]，一定是要先求出dist[fa[x]]的
找到dist[fa[x]，则dist[x]+=dist[fa[x]]
因为肯定如果不是根节点的话dist[x]!=0
因为在合并两个队列的时候就有让dist变大的操作了
可以再多理解一下~
还有只想说vijos666666啊
用的cin然后TLE
然后用的scanf printf就直接2000ms
T_T
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=30005;
int fa[maxn];
int sum[maxn];//这一个集合(一列)的总个数，实际上只是用来接上使判断一下前面飞船数增加的多少
int before[maxn];//前面飞船数量，抽象为到根节点(队首)的距离
int n;//操作数
char ch;

int getfather(int x)
{
  if(fa[x]==x)return x;
  int p=getfather(fa[x]);
  before[x]+=before[fa[x]];
  fa[x]=p;
  return fa[x];
}

int main()
{
	int x,y;
    scanf("%d\n",&n);
  	for(int i=1;i<=30000;i++)
	{
		fa[i]=i;
		sum[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%c %d %d\n",&ch,&x,&y);
		int fx=getfather(x);
		int fy=getfather(y);
		if(ch=='M')
		{
			if(fx!=fy)
			{
				fa[fx]=fy;
				before[fx]+=sum[fy];//x所在列接在y所在列尾部，所以fx前面的舰队数要加上fy列的总舰队数
				sum[fy]+=sum[fx];//
			}
		}
		else
		{
			if(fx!=fy)
				printf("-1\n");
			else
				if(x==y)
					printf("0\n");
				else
					printf("%d\n",int(abs(before[x]-before[y])-1));
		}
	}
	return 0;
}
/*
那么这道题从数据范围来看，如果不用压缩路径的并查集会超时，
所以压缩路径是肯定的，那么如何合并并且记录数量，
需要解决的是这两个问题。
可以新增两个域，
b[i]表示i飞船前面有多少飞船，c[i]表示当i是并查集根时，
i后面有多少飞船。
那么在合并的时候就需要更新两列飞船的c[i]，
c[j]:=c[i]+c[j]+1,也许要更新b[i],因为他不在是飞船头了，
b[i]:=c[j]+1.那么在get找根的时候需要压缩路径和更新b[x]，
在没有压缩路径之前的父亲节点fa需要预先下来，
在回溯的时候因为fa的b数组是先更新的，所以b[x]:=b[x]+b[fa]
表示父亲之前父亲前面的飞船+之前自己到父亲之间的飞船等于
压缩后自己到当前总根的飞船数，因为不可能在自己和根之间插入飞船，
就算之后再有压缩路径的操作，那么总根前面飞船是0，自己也不会加重，
所以这么做是正确的。对于C操作就判断是否为同一列，
在查找的时候就更新了，输出就可以了。
*/