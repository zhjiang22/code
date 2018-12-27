/*
好题啊~ 大致解释一下题意吧
就是给定一个序列。要求对一个区间的数进行如下操作：把i~j这段数字全部设为，
使得代价最小。每次操作后，数列恢复成原始状态。求所有操作的最小代价和。
很明显对于每个区间，我们都要取这个区间的中位数。
（如果这个序列只有偶数个数，那么取第n/2个，或者第n/2+1个都可以，没有差别的。）
求中位数有一种堆的做法，但是这里可以用预处理解决
所以我们可以考虑预处理每个区间的中位数，再预处理每个区间的和减去中位数的绝对值的和。

枚举每一个数，向左扫，记录cnt l枚举到时大于等于的个数-比小的个数。
向右扫，记录cnt r枚举到时大于等于的个数-比小的个数。
如果是的中位数，那么下列两种条件必定满足一种：
1.l-r+1是奇数，且cnt r-cnt l=1
2.l-r+1是偶数，且cnt r=cnt l
那么先往左扫，然后用类似Hash的链表存下，然后向右扫的时候查询左边的情况，
看看能否满足上述条件的一种。然后存下答案就行。
最后预处理每个区间的和减去中位数的绝对值的和。
综上，预处理复杂度，询问复杂度 。整个算法的时间复杂度就是。
*/
#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
#define maxn 1005   
int m[maxn*3],pre[maxn],mid[maxn][maxn],a[maxn],id[maxn],n,q;  
long long sum[maxn][maxn];  

int main()  
{  
	ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    for(int i=1;i<=n;i++)
    {  
        memset(m,-1,sizeof(m));  
        memset(id,0,sizeof(id));  
        memset(pre,0,sizeof(pre));  
        int d=0,x=0,tot=1;  
        for(int j=i;j>=1;j--)
        {  
            if(a[j]>a[i])   d++;    else    x++;  
            id[tot]=j; pre[tot]=m[d-x+maxn];    m[d-x+maxn]=tot++;  
        }  
        d=0,x=-1;  
        for(int j=i;j<=n;j++)
        {  
            if(a[j]>a[i])   d++;    else    x++;  
            for(int p=m[x-d+maxn];p!=-1;p=pre[p])    if(((j-id[p]+1)%2)==0)    mid[id[p]][j]=i;  
            for(int p=m[x-d-1+maxn];p!=-1;p=pre[p])    if(((j-id[p])%2)==0)    mid[id[p]][j]=i;  
        }  
    }  
    memset(sum,0,sizeof(sum));  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=n;j++)   
        	sum[i][j]=sum[i][j-1]+1LL*abs(a[j]-a[i]);  
    int x,y;  
    long long ans=0;  
    while(q--)
    {  
        cin>>x>>y; 
        ans+=sum[mid[x][y]][y]-sum[mid[x][y]][x-1];  
    }  
    cout<<ans<<endl;   
    return 0;  
}  

     


/*
附上堆做法
首先每次加一个元素进入大根堆.如果 大根堆的元素个数-1>小根堆的元素个数.
那么把大根堆堆顶的元素加入小根堆.
这样就保证了小根堆的元素个数总是等于或者比大根堆的元素个数少1.
然后再比较小根堆堆顶元素与大根堆堆顶元素.如果小根堆堆顶元素小于大根堆堆顶元素.
那么把大根堆堆顶元素加入小根堆.把小根堆堆顶元素加入大根堆.
这样就可以保证小根堆中所有元素都不小于大根堆中的元素.于是大根堆堆顶元素就是中位数..
*/