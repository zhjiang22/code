/*
考这种数学题真的好吗？
我数学真的好差啊
然后果断来了个枚举暴力70分
Orz数学差 OI再见
(一个月后.....)
终于在一个月之后的窝终于认真学了下数论
才发现这就是一道水题。。。
于是重写一遍~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a,b;
int x,y,d;

void gcd(int a,int b,int& d,int& x,int& y)
{
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
    cin>>a>>b;
    gcd(a,b,d,x,y);
    if(d==1)
        cout<<(x+b)%b<<endl;
    return 0;
}
     