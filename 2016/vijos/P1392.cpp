/*
这题如果状态直接定义为f[i,j]=x表示前i个数放入j个集合最多能包含x个数 
那么操作起来会比较困难，所有应换一种状态的定义。
记a[i]为第i个数，
f[i,j]=(t,s)表示前i个数选了j个数需要t个集合，最后一个集合所有数之和为s，
那么 f[i,j]=min{f[i-1,j],f[i-1,j-1]+a[i]} 
边界f[0,0]=(1,0) 
那么就是一个0-1背包问题啦
最后的答案是使得f[n,i]的t<=m的最大的i
考虑到0/1背包的一维优化咯
所以我们也就可以用
f[i]=(t,s)表示选了j个数需要t个集合，最后一个集合所有数之和为s
初值f[0]=(1,0)
按照一维0/1的思路递推就好了
细节上我们要注意    当我们给结构体重载运算符的时候(也可以用函数调用来进行+和cmp)
这个(node){t,s}强制类型转换时是和结构体中成员的顺序有关的
别傻乎乎地写错了Orz
像我一样智障了
窝好弱啊
结构体状态的动规
涨姿势惹
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int n,m,T；
struct node//0/1背包状态
{
    int t,s;//注意这两个顺序不能反了~！
    bool operator <(const node d)const
    {
        if(t<d.t)
            return 1;
        if(t>d.t)
            return 0;
        return s<d.s;
    }
    node operator + (const int d)const
    {
        if(s+d<=T)
            return (node){t,s+d};
        else    
            return (node){t+1,d};
    }
}f[MAXN];

void init()
{
    cin>>n>>m>>T;
    f[0].t=1;
}

void DP()
{
    int x;  node t;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        f[i]=f[i-1]+x;
        for(int j=i-1;j>=1;j--)
        {
            node t=f[j-1]+x;
            if(t<f[j])//注意不能直接max比较了
                f[j]=t;
        }
    }
}

void out()
{
    for(int i=n;i>=0;i--)
        if(f[i].t<=m)
        {
            cout<<i<<endl;
            return;
        }
}

int main()
{
    init();
    DP();
    out();
    return 0;
}
