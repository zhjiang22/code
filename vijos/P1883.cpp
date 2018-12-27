/*
水题直接模拟
这套比赛卷都懒得写了
就直接写了个思路就好了OTZ
道题的关键在于所有的圆位置关系只有内切、外切、内含、外含四种关系，不存在两个圆相互交叉。
所以理论上有n个圆，平面就被分成n+1个，之所以多是因为有些圆被其他几个圆分成了两个了，
看懂这一点就成功了一点了。
找出 完全包含而又最大的圆
然后按左端点递增，左端点相同则右端点越远越优先排序
每个圆本来只能增加1个平面
会出现更多 是因为一些圆首尾相接把一个大圆割成了两部分
那我们只要找出每个圆的一级祖先就可以判断了
然后求每个圆的一级祖先可以用我在程序中的dfs来求出，正确性应该显然。
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define L 300010
using namespace std;
struct circle
{
    int lp,rp,IO,father;
}po[L];
int n,ans,O,R,nows;
bool cmp(circle a,circle b)
{
    if(a.lp==b.lp)
        return a.rp>b.rp;
    return a.lp<b.lp;
}
void dfs(int looks)
{
    while(nows<=n&&po[nows].rp<=po[looks].rp)
    {
        po[nows].father=looks;
        nows++;
        dfs(nows-1);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&O,&R);
        po[i].lp=O-R;
        po[i].rp=O+R;
    }
    sort(po+1,po+n+1,cmp);
    nows=1;
    po[0].rp=2147483647;
    dfs(0);//先打上fa标记
    for(int i=1;i<=n;i++)
        po[po[i].father].IO+=(po[i].rp-po[i].lp);
    ans=n+1;
    for(int i=1;i<=n;i++)
        if(po[i].IO==po[i].rp-po[i].lp)
            ans++;
    printf("%d\n",ans);
    return 0;
}