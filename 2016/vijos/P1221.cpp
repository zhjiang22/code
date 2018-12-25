/*
并查集拆点做法
对于每一个村民的询问，就对应着两种可能
都说谎话或者都说真话
用x+maxn表示x的对立面
则同一个集合表示真假性相同的元素综合
即有若f[x]处于一个集合A 那么f[x+maxn]所在集合B一定是和A对立的
那么对于输入的a,x,b,y
如果x==y 说明a,b要么是同真要么是同假，就把a,b和a+maxn,b+maxn合并为一个集合
如果x!=y 说明a,b只有一真一假的可能，就把a,b+maxn和a+maxn,b合并为一个集合
当读入x==y时 如果a+maxn和a或者b和b+maxn在一个集合说明有冲突
同理当x!=y时，如果a,b或者a+maxn,b+maxn在一个集合则冲突
而此题的方案数和集合数k的关系为2^k(不懂啊数学差)
这里要用到高精度幂因为数据很大
那么怎么求集合数呢
设置v[]，表示该集合的根节点是否算过即该集合是否算过
然后我们只要统计一面的集合数就好，即正面的集合数
所以我们在对于1-n所有结点找到根节点的时候，判断根节点是否<=n
如果是就可以算上一个集合，再设置标记此集合已经算过了即可
高精度要练习一下~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1000;
int fa[maxn*2];
bool v[maxn*2];
int n,m;
int a,x,b,y;
int a1[maxn],c[maxn];
int cnt;

int getfather(int x)
{
	return fa[x]==x?x:fa[x]=getfather(fa[x]);
}

void Union(int x,int y)
{
	int fx=getfather(x);
	int fy=getfather(y);
	if(x!=y)
		fa[fx]=fy;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n+maxn+10;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>x>>b>>y;
		if(x==y)
		{
			if(getfather(a)==getfather(b+maxn))
			{
				cout<<"No Answer"<<endl;
				return 0;
			}
			else
			{
				Union(a,b);
				Union(a+maxn,b+maxn);
			}
		}
		else
		{
			if(getfather(a)==getfather(b))
			{
				cout<<"No Answer"<<endl;
				return 0;
			}
			else
			{
				Union(a,b+maxn);
				Union(a+maxn,b);
			}
		}
	}
for (int i=1;i<=n;++i)
{
	int fi=getfather(i);
if (!v[fi]&&(fi<=n))//一定要加后面这个判断，即只统计一面即正面
    {
        ++cnt;
        v[fi]=1;
    }
}
int l=1;
a1[0]=1;
for (int i=0;i<cnt;++i)
{
for (int j=0;j<l;++j)
    {
    c[j]+=a1[j]*2;//每一位都要乘2m并转移到c数组
    c[j+1]+=c[j]/10;//进位
    c[j]%=10;//进位后取余数
    }
++l;
while (l>=0&&c[l]==0) --l;//去除首位0
++l;

for (int j=0;j<l;++j) a1[j]=c[j];//每计算完一次，c数组内转移到a数组中去
memset(c,0,sizeof(c));
}

for (int i=l-1;i>=0;--i) printf("%d",a1[i]); 
       return 0;
}
     