/*
经典状态压缩dp
其实也不是很难只是被知识点名字吓到了
连循环数组优化都不用加就直接AC了
首先我们可以知道的是，这道题的问题在于L太大了，不可能开一个这么大的数组来存放所有的点
估计就是ORZ然后爆炸了然后运行都运行不了23333
但是这题的突破口在于：
1.首先不多说，特判，如果s==t，那么就只能s，s地跳，这个就是个简单的情况了，直接特判。
计算出能经历多少个这样的点在s的整数倍坐标上即可
排除此情况后：
2.石子的数量实在是太小了，最多100个QAQ，试想一个10^9的数轴上，只有一百个有效点，
剩下的都是空点,而其中很多的空点其实是没有实际意义的
所以我们就压缩一下咯,首先排序,对于排好序的石头数(注意：石子并没有按顺序给出要排序)
我们可以观察两个相邻的石头，
中间那一块空地是不管怎么样都不会影响到下一块石头的数量的(你乱蹦乱跳怎么弄也都是空地)
那么我们就把中间这块空地给压缩一下吧
我们考虑一下，对于一片空地而言，至少要多长的空地才能让青蛙对这些地方处处可达？
ORZ我数学其实不好，所以引用一下Peeeeeach的题解中的话吧
{
	讲一下这个题的数学分析思路吧。首先桥很长，但石子很少，所以可以对桥的长度进行压缩，
然后再DP。首先特判S==T，如果相等的话，那么就看石子是否落在S的整数倍格子上。
然后我们再进行分析。青蛙最坏的情况就是S=T-1，它每次跳跃只有两种选择，我们只考虑这种情况即可。
问题的关键就是多么长的空地才能保证青蛙对这些空地是处处可达的？假设这个距离是X，
那么比X长的空地也都是处处可达的，就与长为X的空地等效了，因此这就是压缩长度的关键。
最后的结论是X=T^2。青蛙跳跃X需要跳T次T长度，但是可以把每个T逐个换成S（也就是T-1）
那么TS到TT就是跳T次能到达的所有格子了。而跳T-1次能到达的最大长度为(T-1)T=ST，
与跳T次的最小长度衔接上了。而T的最大值是10，也就是X取100。
因此先对输入数据进行一次初始化，如果发现两个石子之间的长度比100大，那么就直接视为它们相距100即可。
}
不多说先膜拜%%%%Peeeeeach大神
Px+(P+1)y=Q     
x,y是未知数，P是跳跃的距离，P+1也是跳跃的距离，对于任意Q，Q>=P*(P-1), 
x，y一定存在正整数解，换句话说当两个石子之间的距离大于等于T*(T-1)时，
中间有相当大的距离是每个点都可以跳到的，因为没有石子，所以对答案没有贡献，可以取模(%90),
这样就很好办了。。。于是我们就成功地把状态给压缩了。
那么处理好这个问题以后我们就可以进行压缩了，对于每两个相邻石头距离一言不合就直接%个100吧，
但是弱比的我发现这里的数据%90也可以，可能是没有这种T==10&&S=T-1的极端数据吧
3.注意最后的结果一定要算到l+t(因为跳出范围也是合法的)，最终输出答案时，
在f[L]到f[L+t]中找到最优解输出
其他不多说了，直接看代码吧
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1100000;
const int MAXM=105;
const int MOD=90;
int stone[MAXM];
int a[MAXN];
int f[MAXN];
int L,s,t;
int n;

void init()
{
	scanf("%d%d%d%d",&L,&s,&t,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&stone[i]);
}

void solve()
{
	int tot=0;
	for(int i=1;i<=n;i++)
		if(stone[i]%s==0)
			tot++;
	cout<<tot<<endl;
	exit(0);
}

void work()//处理石头~缩掉里面的空地
{
	sort(stone+1,stone+n+1);
	for(int i=1;i<=n;i++)
	{
		int dist=stone[i]-stone[i-1];
		stone[i]=stone[i-1]+dist%MOD;
	}
	L=(L-stone[n])%MOD+stone[n];
	for(int i=1;i<=n;i++)
		a[stone[i]]=1;
}

void DP()
{
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=s;i<=L+t;i++)//第一次至少也会跳到s
		for(int j=s;j<=t;j++)
			if(i>=j)
				f[i]=min(f[i],f[i-j]+a[i]);
	int ans=(1<<30)-1;
	for(int i=L;i<=L+t;i++)
		ans=min(ans,f[i]);
	cout<<ans<<endl;
}

int main()
{
	init();
	if(s==t)//特判s==t
		solve();
	work();
	DP();
}
     