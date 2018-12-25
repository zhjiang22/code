/*
不多说	这道题写了整整两节晚自习
最后发现代码太丑了
不敢贴出来啊
这就是个裸的高精度比谁会写代码啊
心好痛	于是丢了自己的代码(100++)
丢个别人的正常点的代码吧
谁让我作死去弄啥重载运算符
醉了醉了
其实思想很简单
就是像我们做小数乘法一样
我们把他当作整数乘法来做	只需要记录下小数点的位置
然后加上小数点即可	不输出前导0和后缀0，整数就只输出整数部分
注意一些0的处理问题就好了
蛮坑的
数据范围还有点带感
唉还有36天NOIP了	感觉要被虐了
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int ans[100001];
char s[7];
int main()
{
    int a=1;
    int n;
    while(scanf("%s %d", s, &n)==2&&a++)
    {   if(a!=2)puts("");
        memset(ans,0,sizeof(ans));
        ans[1]=1;
        int dot;
        int b=0;
        int zhen;
        for(int i=5;i>=0;i--)
        if(s[i]!='0')
        {
            zhen=i;
            break;
        }

        for(int i=0;i<=zhen;i++)
        {
            if(s[i]!='.')
            b=b*10+s[i]-'0';
            else
            dot=(zhen-i)*n;
        }
        int max=1;
        for(int i=1;i<=n;i++)
        {int in=0,j;
            for(j=1;j<=max||in;j++)
            {
                int now=b*ans[j]+in;
                ans[j]=now;
                in=ans[j]/10;
                ans[j]%=10;
            }
            if(max<j-1)
            max=j-1;
        }
        for(int i=max;i>dot;i--)
        printf("%d",ans[i]);
        if(dot!=0)
        printf(".");
        for(int i=dot;i>0;i--)
        printf("%d",ans[i]);
    }
    return 0;
}  