/*
Orz事实证明我弱的惊人啊
考试的时候一脸懵逼根本不会做
内心瞬间崩溃	这tm都是什么题啊
然后想都不想
打了个爆搜
我说有10分n最大是10
我这个爆搜拿不到10分我都不学OI了
Orz OI再见
结果0分了233333
哎真的太神了
反正我这辈子都想不到了
QAQ题解很多，很多都很难懂，贴两个我觉得好的题解
{
怎么使距离最小？哈哈哈哈，是在两个队列里面的火柴相对应（A集合火柴中第i小对应B集合中第i小），
将两个集合排序（为了让AB相对应），因为排好序A,B是最小的，所以A下标与B下标就要对应;
然后按照A去处理B，开一个数组C，C[A[i].point] = B[i].point;数组C中的下标为A[i]的下标，
对应的值是B[i]的下标；
举一个例子：
A:4 5 6 1 3 7 ->A':1 3 4 5 6 7
B:5 3 2 1 7 6 ->B':1 2 3 5 6 7
	C: 2 1 6 4 3 5
很明显要求C数组的逆序对数啊！逆序对数用什么？树状数组！
}
{
最开始思考这个问题肯定会想什么情况下所谓的距离和最小。
如果你足够聪明可能第一反应应该是在各个序列中排名一样的数对齐其和距离和最小。
如果你不能立刻看出来也没有关系，咱们可以证明一下：
   （1）设序列只有两个数分别是a,b;c,d;且c < d,a < b
令S1=(a-c)(a-d)+(b-d)(b-d)，S2=(a-d)(a-d)+(c-b)(c-b),则：
S1-S2=2ad+2bc-2ac-2bd=2a(d-c)+2b(c-d)=2(d-c)(a-b)。由已知条件易知S1 < S2。
   （2）由数学归纳法可以知道假设k个都是按序拍距离最小，第K+1项也一定是满足这样的顺序才能保证最小。
移动的时候可以将一个火柴序列不同，只移动另外一个序列。
于是可以构造一个数组C，C[i]表示第i个数应该移动到C[i]位置。
于是问题转换成对C[i]数组排序，每次可以交换相邻两个数，
问最少需要移动多少次的问题了，也就是求这个序列的逆序和问题。具体可以参考上一篇博文：
http://blog.sina.com.cn/s/blog_963453200101jxqa.html
}
这篇博文也蛮好的~QAQ
练习一下树状数组吧	QWQ因为我这种弱逼学不起线段树(滑稽币不够辣)
QAQ共勉希望你们不要像我一样弱
其实想到了用逆序对就很简单了
然后想到逆序对其实也很简单
然而我还是没想到233333
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXN=100010;
const int mod=99999997;
struct node
{
	int v,pos;//pos记录原先对应的位置
	bool operator < (const node&b)const
	{
		return v<b.v;
	}
}a[MAXN],b[MAXN];
int n;
int c[MAXN],p[MAXN];
int ans;

inline int lowbit(int x){return x&(-x);}

void add(int x,int d)
{
	while(x<=n)
	{
		p[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=p[x];
		x-=lowbit(x);
	}
	return ans;
}

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].v,a[i].pos=i;
	for(int i=1;i<=n;i++)
		cin>>b[i].v,b[i].pos=i;
}

int main()
{
	init();
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	//记录下c数组
	for(int i=1;i<=n;i++)
		c[b[i].pos]=a[i].pos;
	//求c[]的逆序对
	for(int i=1;i<=n;i++)
	{
		ans=(ans+i-sum(c[i])-1)%mod;
		add(c[i],1);
	}
	cout<<ans<<endl;
	return 0;
}
     