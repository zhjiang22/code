/*
真心坑爹这题
首先其实她叫来的同学人数p+1才是我们要用的总人数
然后我们再看p最大范围是32位
正好+1就爆了 所以必须要64位longlong
OTZ一道离散化的题目
但是数据的端点也就最大500万 直接扫一遍也是可以的咱不怂
注意题目中的游戏是可以中途进入，中途退出的，就是说题目所求就是尽量让电脑全部满载时的时间。
t[i]表示在i时间能玩的游戏增加了几个（注意是增加了，所以可以为负数），
我们开个变量delta记录当前有多少游戏能玩，然后扫描一遍时间，
同时根据t修改delta，最后now的总合就是时间数了，
注意now如果比人数+1与电脑数的最小值大要改成最小值的。
这种区间取上端点然后再用离散的思想的题目也见了很多了
总结一下吧
这种题目关键在于我们要弄清一个区间它的端点对于结果的影响
其实也就是进入一个区间和出一个区间后的影响
搞清楚这个关系就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long t[5000002];
long long p,m,n,ans;
int s,d,delta;

int main()
{
    cin>>n>>m>>p;
    p++;
    for(int i=1;i<=n;i++)
    {
        cin>>s>>d;
        t[s]++;
        t[d+1]--;
    }
    for(int i=0;i<=5000001;i++)
    {
        delta+=t[i];
        ans+=min((long long)delta,p);
    }
    cout<<ans<<endl;
    return 0;
}