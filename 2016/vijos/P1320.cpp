/*
因为m是递增的~	所以好像可以直接水法~
但是看数据这么好说话
一言不合来了个树状数组不解释
瞬间A了
说说水法吧~
因为M是递增的
所以每次对于A的询问，把前面求和的值保存下来，不必重复计数，可以秒杀
就是我们可以暂时维护一个sum表示到上一个m的总和
然后直接从上一个m继续累加到当前m就好了
不需要重复计算sum
所以复杂度还是O(n)的
会比树状数组的速度快~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=500005;
int c[MAXN];
int n,k;

void init()
{
	cin>>n>>k;
}

inline int lowbit(int& x){return x&(-x);}

void add(int x,int d)
{
	while(x<=n)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

void question()
{
	char ch;int m,p;
	for(int i=1;i<=k;i++)
	{
		cin>>ch;
		if(ch=='A')
		{
			scanf("%d",&m);
			cout<<sum(m)<<endl;
		}
		else	if(ch=='B')
		{
			scanf("%d%d",&m,&p);
			add(m,p);
		}
		else
		{
			scanf("%d%d",&m,&p);
			add(m,-p);
		}
	}	
}

int main()
{
	init();
	question();
	return 0;
}
     