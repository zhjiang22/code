/*
样例有错啊
OTZ直接贪心就好了
想明白了很简单
令c[i]=
{
t-i+1 1<=i<=n/2+1
i-t+1 n/2+1<i<=n
}
t是(n+1)/2
将a[i]和b[i]-=c[i]之后，问题就转化成了将a和b的所有元素变成同一个值得最小代价，
求中位数即可
即首先我们将所有的高度都减掉他们的高度差，那么得到的应该是一串高低不平的数列，
那么题目转化为，将这个改变后的数列变成一样高的最小费用。
操作的时候我们取mid=(n+1)/2
然后对于两个高度数组我们都对于中间砖左右进行减去距离值
距离值就是i位置减去mid的值
然后将两个数组复制到一个数组中去
再对整个数组排序    选择中间的中位数
所有的差值之和就是答案
数据要开longlong
怎么解释上面这个算法呢
我们来看这个题目
仔细想一想   因为两座城堡最终是一定要相同的
其实这个题目就等效于直接将两个数组全部转换为同一个数(两个数组最终中间的那个数)
但是这里还要满足每次少1啊
所以我们最优的时候肯定是就地取材
我们先选取中间这个点  别的点距离他距离为x
说明最终答案的时候要比中间这个关键点位置低x
所以我们预先减去个x  一定不影响答案
有点说不清楚我傻还是直接上个博客吧

对于一个n的序列   设最低点n/2高度为h  则向左向右分别为 h+1，h+2…………h+n/2
要是代价最小  就是是 h[i]最接近于 a[i] 
即h+n/2-i+1 -> a[i] 
数学优化   h = a[i]-(n/2-i+1) 
对于如下的情况
           i                    h            j
______。__________。______。_________________ 
h点 在ij之间是 
i点j点h点有最小距离 
就是此题的最小价值   
以此类推   孩子用将放有h的数组一个sort
然后取中位数  
再用每一个h减去中位数  取绝对值
即为ans  
对于此题  将两个城堡并在一起
形成    \/\/  形状
神奇的数学方法近似优化到了 o（n） 
数学大法好orz orz 
以后记得这些绝对值最小的优先想中位数啊orz
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long a[300010];
long long b[300010];
long long c[600010];
long long ans,alpha;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    int mid=(n+1)/2;
    for(int i=1;i<=mid-1;i++)
    {
        a[mid-i]-=i;
        a[mid+i]-=i;
        b[mid-i]-=i;
        b[mid+i]-=i;
    }
    for(int i=1;i<=n;i++)
        c[i]=a[i];
    for(int i=1;i<=n;i++)
        c[n+i]=b[i];
    sort(c+1,c+2*n+1);
    alpha=c[n];
    for(int i=1;i<=2*n;i++)
        ans+=abs(alpha-c[i]);
    cout<<ans<<endl;
    return 0;
}