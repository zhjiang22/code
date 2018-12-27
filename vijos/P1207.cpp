/*
一道不是很难的动态规划 rp竟然这么高
但是的确很考验思维能力的博弈题
嗯和那个啥P1202有点像(一类)   先去做通P1202
嗯状态是一样的
f[i,j]表示[i,j]中的最大值，但注意只存一个人的
首先需要注意到一个性质：
当确定了哪段[i,j]之后，最后哪个人拿数（i或者j）是确定的，
因此枚举拿i还是拿j，那么哪个更加优呢？
我们可以给每个f[I,j]存一个g[I,j]表示决策，然后往前推k步就行了
即设f[i,j]表示i到j轮到的人能取的最大值
  g[i,j]=1表示取i，g[i,j]=2表示取j那么
f[i,j]=max(a[i]+get(i+1，j),a[j]+get(i,j-1))（倒着取）
get函数是用来求上次此人取得的最大值
即我们可以看到k个人实际上是轮流选择这个最优解的
那么比如第x个人    我们枚举他是取左边还是右边
那我们肯定是要考虑到我们要有
a[i]+(选了a[i]后可以达到的最大值)和a[j]+(选了a[j]后的最大值)要取最大值
那么我们怎么得到选了a[i]或a[j]后可以达到的最大值呢？
我们已经用g[i][j]记录了做[i,j]这个区间决策的时候是选取左边还是右边
所以我们就向前推k-1步  即k-1次取数就是上一轮这个人的时候选取得到的最大值
和1202一样我们的每一个决策都是从一个比它短的区间递推而来
所以我们肯定在[i-1,j]或者[i,j-1]中的所有需要的f[][]和g[][]都已经球出来了
所以我们在[i-1][j]和[i,j-1]中推一遍
仔细考虑这个递推的过程
我们看一直将这个区间缩短    如果g[x][y]==1说明这一个区间最优取的是x
则转换为了[x-1,y]中的问题 x--
同理g[x][y]==2 则y--
那么就有两种情况了，这个人是第一次选数字    那么肯定推不到他上次选数的情况
就会出现x>y了    如果没有出现这种情况  那么我们在循环k-1次后
得到的新的f[x][y]一定就是他上次选数之后的最优解了
所以我们就可以根据情况返回0或者f[x][y]
这个函数很重要考虑到了一种DP递推的思路
至于输出答案
我们就按照f[][]和g[][]走一遍
当走完k个人的时候   肯定就将每个人的最优解得出来了
好题  锻炼思维了
OTZ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1002;
int a[MAXN];
int f[MAXN][MAXN];
int g[MAXN][MAXN];
int n,k;

void init()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],g[i][i]=1,f[i][i]=a[i];
}

int get(int x,int y)//求上次此人取得的最大和
{
    for(int i=1;i<=k-1;i++)
        if(x>y)
            break;
        else    if(g[x][y]==1)
            x++;
        else
            y--;
    if(x<=y)   
        return f[x][y];
    else
        return 0;
}

void getans()
{
    int x=1;    int y=n;
    for(int i=1;i<=k;i++)
    {
        cout<<f[x][y]<<endl;
        if(g[x][y]==1)
            x++;
        else
            y--;
    }
}

int main()
{
    init();
    for(int l=1;l<=n-1;l++)//长度
        for(int i=1;i<=n-l;i++)//起点
        {
            int j=i+l;//终点
            int x=get(i+1,j);//求出上次
            int y=get(i,j-1);//的最大值
            if(x+a[i]>y+a[j])
            {
                f[i][j]=x+a[i];
                g[i][j]=1;
            }
            else
            {
                f[i][j]=y+a[j];
                g[i][j]=2;
            }
        }
    getans();
    return 0;
}
     