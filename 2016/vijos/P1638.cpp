/* 
这坑爹的题目
果然又是考语文 表示看了半天还是没看懂题目啊
然后一脸懵逼看了半个小时
就和算法竞赛宝典里面的那个LIS的回家有点像(哦不就是一样做法)
我解释一下题意吧
题意:通道大小为x(长)*y（宽)
(应该是数据原因，这个x,y好像并没有什么用，应该是用来判别 陷阱是否超出通道，好像数据都没有超出)
有n个陷阱，陷阱的d,c分别为陷阱所在的坐标系的位置（把通道看出坐标系，则陷阱位置为(c,d)） 
每个陷阱不能出现交叉（简单来说就是要保持上升[二维LIS问题] 
这就转换为LIS了
我们先按照C从小到大排序    C相同就按D从大到小排序
我们看到的是n有500000
如果是O(n^2)必定是会超时的
所以就要用LIS的O(nlogn)的算法来做了
这个算法的动规解释有点难理解对于入门者来说
我就说个模拟栈的做法一般？
我们维护一个栈，从左向右考虑每一个元素
如果当前元素大于栈顶元素，那么我们就让它进栈，并且最大长度+1
不然我们就二分查找栈中元素，找到从栈顶向下第一个比它小的数
那么上一个元素就是比它大的第一个数x
然后用它替换掉找到的元素x
很容易理解的其实    我们用它替换掉一个比他大的数
可以知道这个链长度没有变
而且肯定对于后面的元素没有影响 但是他的潜力却增大了(好好理解我说不清楚Orz)
这里的二分查找我们可以用自己手写的birnary_search 也可以直接用lowerbound
所以说STL大法好23333
*/  
#include <iostream>  
#include <algorithm>  
using namespace std;  
const int MAXN=500005;  
struct Node  
{  
    long long int d;  
    long long int c;  
};  
Node a[MAXN];  
Node dp[MAXN];  
bool cmp(Node a,Node b)  
{  
    if(a.c==b.c)  
    {  
        return a.d>b.d;  
    }  
    else  
    {  
        return a.c<b.c;  
    }  
}  
int main()  
{  
    long long int x,y;  
    int n;  
    cin>>x>>y>>n;  
    for(int i=1;i<=n;i++)  
    {  
        cin>>a[i].c>>a[i].d;  
    }  
    sort(a+1,a+n+1,cmp);  
    int top=0;  
    dp[0].c=0,dp[0].d=0;  
    for(int i=1;i<=n;i++)  
    {  
        if((a[i].c>=dp[top].c)&&(a[i].d>=dp[top].d))  
        {  
            top++;  
            dp[top].c=a[i].c;  
            dp[top].d=a[i].d;  
        }  
        else  
        {  
            int l=1,r=top,mid;  
            while(l<=r)  
            {  
                mid=(l+r)/2;  
                if ((a[i].c >= dp[mid].c)&&(a[i].d>=dp[mid].d))  
                {  
                    l = mid + 1;  
                }  
                else  
                {  
                    r = mid - 1;  
                }  
            }  
            dp[l].c=a[i].c;  
            dp[l].d=a[i].d;  
        }  
    }  
    cout<<top<<endl;  
    return 0;  
}  