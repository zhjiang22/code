/*
题目大意：给定一个字符串（长度为20*p，不超过200）和一个包含一些单词
（个数为n，1≤n≤6）的词典，问如何将该字符串分成K（不超过40）份，
使得每份中包含的单词个数之和最大，输出这个最大值。以一个位置为起始点只能统计一个单词。

用a[i][j]表示区间（i,j）内所含的单词个数，可以用暴力计算出所有a[i][j]。
再设f[i][k]为字符串前i个字符分割成k份的最优解，最终答案即是f[20*p][K]
状态转移方程为： f[i][k]=max(f[i][k],f[j][k-1]+a[j+1][i])。(k-1<=j<=i-1)
这个方程怎么理解呢？
其实挺简单的
我们对于当前状态f[i][k] 即是到第i个字符    分割成了k份
那我们必然要找到一个分割成k-1份的状态
然后想办法通过再加上一份来转移到当前状态
所以我们枚举这个加上的这一份
加上的这一份都终点肯定是i   那么我们枚举起点j
因为已经分成了k-1分所以j肯定要>=k-1
而因为是要再加上一份得到到i的状态
所以j<=i-1
所以我们很容易想到
如果我们从j这个地方断开i这一段(即使从j到i这一段作为这最后分的一段)
有价值f[j][k-1]+a[j+1][k]
所以我们取所有满足条件的j所得答案最大值就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=202;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int v[MAXN];
char c[MAXN];
string b[8];
int p,K,n;

void init()
{
    cin>>p>>K;
    for(int i=1;i<=p;i++)
    {
        for(int j=(i-1)*20+1;j<=(i-1)*20+20;j++)
            cin>>c[j];
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {  
        cin>>b[i];
        for(int j=1;j<i;j++)
            if(b[i]==b[j])
            {   
                i--,n--;
                break;
            }
    }
}

void geta()
{
    for(int i=1;i<=20*p;i++)//外两层
        for(int j=i;j<=20*p;j++)
        {
            memset(v,0,sizeof(v));//每次尝试一个范围的时候清零
            for(int k=1;k<=n;k++)//枚举字典单词
            {
                long len=b[k].length();//取长度
                for(int ii=i;ii<=j-len+1;ii++)//枚举尝试起点
                {   
                    if (v[ii]) continue;//已经匹配了一个单词(用了这个单词起点不能再用)
                    bool flag=1;//标志变量
                    for(int jj=0;jj<len;jj++)//开始尝试匹配
                        if (c[ii+jj]!=b[k][jj]) //有一个字符不一样
                        {
                            flag=0;
                            break;//直接跳出查找
                        }
                    if (flag) //flag=1说明找到了一个单词
                    {
                        a[i][j]++;
                        v[ii]=1;//标记这个起点已用
                    }
        }
      }
    } 
}

void DP()
{
    for(int k=1;k<=K;k++)
        for(int i=1;i<=20*p;i++)
            for(int j=k-1;j<=i-1;j++) //注意从k-1开始，勿漏情况
                f[i][k]=max(f[i][k],f[j][k-1]+a[j+1][i]);
    cout<<f[20*p][K]<<endl;
}

int main()
{
    init();
    geta();
    DP();
    return 0;
}