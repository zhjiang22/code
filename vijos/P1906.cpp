/*
一道让我感到恶心却不得不承认的好题
Orz 第一眼看到这道题
直接想到Floyd可做啊，而且只是2的距离就可以小小优化一下Floyd保留下2距离的对应序列
心中默默来一句，好水啊比NOIP2015Day1T2还水QAQ
然后一看数据范围，n到了200000
我心中千万头草泥马奔涌而过
想了一会，觉得其实可以直接枚举吧？
距离为2，边权为1，所以和同一个点相连的其它点之间都会产生联合权值，枚举60分2333
再仔细一看看到n个点n-1条边就是一个树了
一想看起来就是树上乱搞了~
讲讲这个方法吧
比较基础的树形dp了
用边集数组来储存这20万的边
然后我们用w[]表示每个点的权值
先对于每一条边处理一下
m[i]记录下i点的邻接点的权值的最大值,m[0]表示所有联合权值最大值
s[i]记录下i点的所有邻接点的权值之和，s[0]表示所有联合权值之和
第一遍循环维护这两个数组就好了
我们还要理清楚这个问题
所谓最短距离为2可以构成联合权值
其实就是所有同一个点的邻接点的距离为2了
那么最大联合权值还是比较好乱搞的
然后我们来讨论一下怎么求出这个联合权值之和
对于所有的联合权值之和，我们要求你还是要有一点数学基础的，但也不高，三年级就足够了！！
你先想一想，我们怎么来求这个和呢？哦！无非就是把所有的加起来而已嘛！
对啊， 但是怎么加着快呢？你想一想，哦，一个点旁边有好多个点，每两个都乘一下，真的好麻烦啊！！
有什么传说级别的算法能处理一下吗？
不，没有。有的只有一个，那叫做，加法结合律！！！
你想一想，和o点相邻的点有a,b,c,d,e,f,g七个，假设他们的权值就是a,b,c,d,e,f,g，
二逼青年的计算过程是这样的：sum：=a*b+a*c+a*d+a*....+e*f+e*g....,
但其实我们这样处理，我们先用加法运算法则，发现sum其实就是每个点的权值乘以可以联合（距离为2）
的节点的所有权值之和，所以说，把每个节点周围相邻节点的权值之和给加起来，
就以上述为例，在处理时，把a,b,c....g的权值加起来为s[o](O点相邻点的权值之和)，
然后在计算时，就可以用sum:=a*(s[o]-a)+b*(s[o]-b).....很自然的结果就出来了!
嗯所以我们就可以很快得出答案了
详细细节不好说
我们见代码旁边的注释吧~
Orz真的是好题，扩展思维
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=200005;
const int mod=10007;
struct Edge
{
    int x,y;
}e[MAXN];
int w[MAXN],s[MAXN],m[MAXN];
int n;

void init()
{
    cin>>n;
    for(int i=1;i<n;i++)
        cin>>e[i].x>>e[i].y;
    for(int i=1;i<=n;i++)
        cin>>w[i];
}

int main()
{
    ios::sync_with_stdio(false);
    init();
    for(int i=1;i<n;i++)
    {
        int x=e[i].x,y=e[i].y;
        s[x]+=w[y]; s[y]+=w[x];//记录总和
        if(w[m[x]]<w[y])//记录最大值
            m[x]=y;
        if(w[m[y]]<w[x])//记录最大值
            m[y]=x;
    }
    for(int i=1;i<n;i++)
    {
    //某个点最大联合权值就是与它相邻的最大点*他所有点相邻结点的乘积的最大值
    //我们可以不用一个点一个点维护，而是直接维护总体最大值就好
        int x=e[i].x,y=e[i].y;
        if(m[y]!=x)//必须是非最大值点
            m[0]=max(m[0],w[x]*w[m[y]]);
        if(m[x]!=y)//必须是非最大值点
            m[0]=max(m[0],w[y]*w[m[x]]);
        //当前k点与w这个根的所有相邻的点的权值*(所有相邻点的权值-k点的权值)
        int u=((w[x]%mod)*((s[y]-w[x])%mod))%mod;//以y为根
        int v=((w[y]%mod)*((s[x]-w[y])%mod))%mod;//以x为根
        s[0]=(s[0]+u+v)%mod;//两个都加起来
    }
    cout<<m[0]<<" "<<s[0]<<endl;
    return 0;
}
     