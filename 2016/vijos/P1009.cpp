/*
根据题意不难得出 Mt+x-nt-y=pl.即(m-n)t-pl=y-x
令a=m-n, b=l ,c=y-x ,x=t ,y=-p
所以本题是求一个不定方程(ax+by=c）的最小非负x
可以用扩展欧几里德`所谓扩展欧几里得就是我们用欧几里得(a,b)=(b,a MOD b)求最大公约数的同时求出ax+by=(a,b)的一组特解.x0,y0
令d=(a,b).若c mod d<>0则 Impssible
否则x0*c/d,y0*c/d为ax+by=c的一组特解
所以通解为x0*c/d+b/d*t,y0*c/d-a/d*t
现在剩下的问题就是如何用扩欧求ax+by=(a,b)的一组特解
方法如下：
设ax0+by0=(a,b)=(b,a mod b)=bx1+(a mod b)y1              （*）
而a mod b=a-[a/b]代入（*）式比较系数得x0=y1,y0=x1-y1*[a/b]
所以我们可以递归实现以上算法.
最后还要注意几个个细节.
1.a,b,c若是负数的话.虽然欧几里得MS可以处理.但是mod 运算会变得很别扭.所以为了变成容易实现.建议将a.b.c转换为正数再解.
对于a我们可以讨论m>n,n<m两种情况.而b本身就是正的.对于c可以加b加到非负为止
即 ax+by=c 方程两边同时加q倍的b解不变
2.中间结果有可能超出longint。。最好用int64.虽然NOIP已经不让用了.
这样这个题就解决了。
根据同余方程的ax+by=c，可以得出a=n-m,b=l,c=x-y 之后扩展欧几里得求线性同余方程。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long x,y,m,n,l;

void gcd(long long a,long long b,long long& d,long long & x,long long& y)
{
    if(!b)  {d=a;x=1;y=0;}
    else    {gcd(b,a%b,d,y,x);   y-=x*(a/b);}
}

int main()
{
    cin>>x>>y>>m>>n>>l;
    long long a=((n-m)%l+l)%l;  long long b=l;    long long c=((x-y)%l+l)%l;
    long long d;
    gcd(a,b,d,x,y);
    if(c%d)
        cout<<"Impossible"<<endl;
    else
    {
        long long a1=x*(c/d);
        long long a2=abs(l/d);
        while(a1<0)
            a1+=a2;
        while(a1-a2>=0)
            a1-=a2;
        cout<<a1<<endl;
    }
    return 0;
}
     