/*
无话可说一道傻逼题？
然后我很傻的打了个模拟暴力QAQ
竟然只有60分
唉什么人都丢光了Orz
然后就发现做法这么多这么简单
一种都没想到
唉我好弱啊
OI再见
http://blog.sina.com.cn/s/blog_963453200101jt50.html
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{ 
    int n;
    cin>>n;
    int ans=0,last=0,x;
    for(int i=1;i<=n;i++)
    {
       cin>>x;
       ans+=max(x-last,0);
       last=x;
    }
    cout<<ans<<endl;
    return 0;
}