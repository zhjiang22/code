/*
一个裸的高精度+快速幂啊
就是求解一个2^p-1而已
降低了难度还只要求最后五百位OTZ
我们就直接递归快速幂就好了
递归边界n==0直接返回
然后先分治
分治后就再将高精度数a*=a
如果n为奇数则还要再乘一个底数即2
然后为了练习一下高精度模板就写了一下bign咯
OTZ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

struct bign
{
    int a[501];
    bign()
    {
        memset(a,0,sizeof(a));
        a[1]=1;
    }
    bign mi()
    {
        bign c;
        c.a[1]=0;
        for(int i=1;i<=500;i++)
            for(int j=1;j<=500;j++)
                c.a[i+j-1]+=a[i]*a[j];
        for(int i=1;i<=500;i++)
        {
            c.a[i+1]+=c.a[i]/10;
            c.a[i]%=10;
        }
        return c;
    }
    bign pf()
    {
        bign c;
        for(int i=1;i<=500;i++)
            c.a[i]=a[i]*2;
        for(int i=1;i<=500;i++)
        {
            c.a[i+1]+=c.a[i]/10;
            c.a[i]%=10;
        }
        return c;
    }
};
int n;
bign a;

void solve(int n)
{
    if(n==0)
        return;
    solve(n/2);
    a=a.mi();
    if(n&1)
    a=a.pf();
}

int main()
{
    cin>>n;
    cout<<floor(log(2)/log(10)*n+1)<<endl;
    solve(n);
    for(int i=500;i>=2;i--)
    {
        cout<<a.a[i];
        if(i%50==1)
            cout<<endl;
    }
    cout<<a.a[1]-1<<endl;
    return 0;
}
     