/*
长见识了
觉得这是道水题啊
就一直想着怎么模拟才能A
然后发现数组开不下
然后就想到其实数组可以不用保留
然后就一直在想怎么判断是否走过
用计算的方法
最后放弃了Orz我太弱了
然后直接交了个暴力QAQ
结果发现这道题做法真心神奇啊Orz
看来我的思维还是太局限了
真心开阔思维了
如果在最外圈则特判，否则转化为在内圈找，坐标相应变化即可。
就是递归
然后一圈一圈减少
横纵坐标之差用n来表示
每递归一次就减少2
然后beg用来表示当前圈的第一个标号
比如说
			1  2  3  4 
			12 13 14 5 
			11 16 15 6 
			10 9  8  7 
n=4,i=2,j=3	即我们要找的是14
我们进入solve(1,4,2,3)
发现并不在第一圈上
我们就进入下一层
计算出来时solve(13,2,1,2)
然后发现这个时候
x==1表示他是在里面的第二层环的第一行
然后就直接返回13+2-1
其他也是一样的
可以自行模拟
唉真神奇
我真是个弱逼
被普及组虐了Orz
*/
#include <iostream>
#include <cstdio>
using namespace std;

int n,x,y;

int solve(int beg, int n, int x, int y)
{
        if (x==1) return beg+y-1;
        if (y==n) return beg+n+x-2;
        if (x==n) return beg+n+n-2+n-y;
        if (y==1) return beg+n+n+n-3+n-x;
        return solve(beg+4*(n-1),n-2,x-1,y-1);
}

int main()
{
        cin>>n>>x>>y;
        cout<<solve(1,n,x,y)<<endl;
        return 0;
}