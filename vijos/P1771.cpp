/*
这道题粗看很简单的
就是模拟一下比赛
然后更新一下得分再排个序再进行下一次比赛
以此反复类推
但我们会发现如果这样要进行Q次排序
复杂度太大了是O(Qnlogn)
肯定不能拿下全部数据
那我们怎么办呢？
很容易想到   其实我们按开始的时候
进行第一遍排序
这个时候这个状态(a[])已经按照降序排好
那我们更新得分的时候
其实并不需要所有的改一遍
我们想到了什么
对没错归并排序
每次扫描整个序列，计算胜者和负者，分入两个数组，
然后把这两个数组归并回原来的序列里
（因为这两个序列都已经有序，所以可以免去排序直接合并）
然后我们要注意题目中要求比分相同的时候
编号小的要在前面
所以我们要手写cmp函数和MAX函数判断
这样才能AC
所以其实挺简单的
这样的复杂度每次修改是O(n)的
然后总的复杂度就是O(Qn)
对于数据就可以AC惹
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
int a[MAXN*2];
int s[MAXN*2],w[MAXN*2];//s是分数值,w是能力值
int win[MAXN],lose[MAXN];
int n,r,q;

bool cmp(int x,int y)//要保证分数相同时编号小的在前面
{
    if(s[x]!=s[y])
        return s[x]>s[y];
    return x<y;
}

bool MAX(int x,int y)//同理要保证分数相同时编号小的在前面
{
    if(s[x]!=s[y])
        return s[x]>s[y];
    return x<y;
}

void init()
{
    cin>>n>>r>>q;
    n<<=1;
    for(int i=1;i<=n;i++)
        a[i]=i;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        cin>>w[i];
}

void merge(int s,int t)
{
    int l=1,r=1,c=0;
    while(l<=s&&r<=t)
        if(MAX(win[l],lose[r]))
            a[++c]=win[l++];
        else
            a[++c]=lose[r++];
    while(l<=s) 
        a[++c]=win[l++];
    while(r<=t)
        a[++c]=lose[r++];
}

void solve()
{
    sort(a+1,a+n+1,cmp);
    while(r--)
    {
        int l=0,r=0;
        for(int j=1;j<=n;j+=2)
            if(w[a[j]]>w[a[j+1]])
            {
                s[a[j]]++;
                win[++l]=a[j];
                lose[++r]=a[j+1];
            }
            else
            {
                s[a[j+1]]++;
                win[++l]=a[j+1];
                lose[++r]=a[j];
            }
        merge(l,r);
    }
    cout<<a[q]<<endl;
}

int main()
{
    init();
    solve();
    return 0;
}
     