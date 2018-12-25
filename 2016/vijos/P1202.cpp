/*
问题描述:
给出一个有n个数序列Q1,Q2,Q3...Qn,做一个博弈问题.
两人轮流重序列的两端取走一个数,在第二个人以最佳策略取数的情况下求第一个人取数的和的最大值.
我们来看    因为对手每次都会选择最优的来做
所以这道题就可以转换为最优性问题来做OTZ
那么就是DP了
我们设f[i,j]表示第i个数到第j个数在这个区间内先拿数的人最大能拿到的和
我写的程序是直接递推的区间长度即j-i
我们可以知道
在区间[i,j]中要得到最优的结果
而我们只有从头和尾取数的两种方法
也就是每个状态只有两种决策
而这又构成最优子结构性质了(这个很好推导吧)
则有状态转移方程
f[i,j]=sum[i,j]-min(f[i+1,j],f[i,j-1]);
初值为f[i][i]=a[i]
怎么解释这个状态转移方程呢？
我们这么看   这是一道博弈题
即我们在[i,j]这个区间如果取了i这个点对应的数
那么下一个人取数的时候问题就变成了怎么在[i+1,j]取到最大的数
如果取了j对应的同理就变成了f[i,j-1]
而只有两个人  如果对方取得数越多
自己取到的数肯定越少
而sum[i][j]是不变的  所以我们要尽可能让对方在你取完了某个数之后
他能得到的最大的值最小 而这个sum[i][j]减去他取得的最小的值
肯定就是你取得的最大的值
那么理清了这个关系答案就很简单了
我们最后的答案得出了f[1][n]表示整个能取到的最大值
那么如果小杉先手
答案就是f[1][n]
不然f[1][n]肯定就被对手选走了
他就会更少了就是sum[1][n]-f[1][n]
有点迭代交换的感觉   非常经典的博弈题
好题QWQ
果然窝还是太弱惹    想了半天才弄通
这里还想再提到的就是关于这个递推顺序的故事了
我们知道  lrj大神说过
状态和状态转移方程决定了天然的递推顺序
所以说我们要好好考虑状态很递推顺序的关系
我们可以看到状态转移中
当前的状态是从两个比当前状态对应的区间长度少1的状态转移而来
所以我们很容易想到
从区间长度短到长递推转移即可
Orz果然还是要深思 
*/
#include <iostream>
#include <cstdio>
using namespace std;

int f[2002][2002];
int a[2002];
int total[2002];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        total[i]=total[i-1]+a[i];
        f[i][i]=a[i];
    }
    for(int i=1;i<=n;i++)//枚举区间长度
    {
        for(int j=1;j+i<=n;j++)
            f[j][j+i]=(total[j+i]-total[j-1])-min(f[j+1][j+i],f[j][j+i-1]);
    }
    if(k==1)
    	printf("%d",f[1][n]);
    else
    	printf("%d",total[n]-f[1][n]);
}