/*
LCIS啊QWQ
好裸的题目啊
可是一个月前的窝却仍是一脸懵逼
最长公共上升子序列（LCIS）的O(n^2)算法  
预备知识：动态规划的基本思想，LCS，LIS
问题：字符串a，字符串b，求a和b的LCIS（最长公共上升子序列）。 
首先我们可以看到，这个问题具有相当多的重叠子问题。于是我们想到用DP搞。
DP的首要任务是什么？
定义状态。  
1定义状态F[i][j]表示以a串的前i个字符b串的前j个字符且以b[j]为结尾构成的LCIS的长度。  
为什么是这个而不是其他的状态定义？
最重要的原因是我只会这个，还有一个原因是我知道这个定义能搞到平方的算法。
而我这只会这个的原因是，这个状态定义实在是太好用了。这一点我后面再说。  
我们来考察一下这个这个状态。
思考这个状态能转移到哪些状态似乎有些棘手，如果把思路逆转一下，
考察这个状态的最优值依赖于哪些状态，就容易许多了。
这个状态依赖于哪些状态呢？  
首先，在a[i]!=b[j]的时候有F[i][j]=F[i-1][j]。
为什么呢？因为F[i][j]是以b[j]为结尾的LCIS，
如果F[i][j]>0那么就说明a[1]..a[i]中必然有一个字符a[k]等于b[j]
（如果F[i][j]等于0呢？那赋值与否都没有什么影响了）。
因为a[k]!=a[i]，那么a[i]对F[i][j]没有贡献，于是我们不考虑它照样能得出F[i][j]的最优值。
所以在a[i]!=b[j]的情况下必然有F[i][j]=F[i-1][j]。这一点参考LCS的处理方法。 
那如果a[i]==b[j]呢？首先，这个等于起码保证了长度为1的LCIS。
然后我们还需要去找一个最长的且能让b[j]接在其末尾的LCIS。
之前最长的LCIS在哪呢？首先我们要去找的F数组的第一维必然是i-1。
因为i已经拿去和b[j]配对去了，不能用了。并且也不能是i-2，因为i-1必然比i-2更优。
第二维呢？那就需要枚举b[1]..b[j-1]了，因为你不知道这里面哪个最长且哪个小于b[j]。
这里还有一个问题，可不可能不配对呢？
也就是在a[i]==b[j]的情况下，需不需要考虑F[i][j]=F[i-1][j]的决策呢？
答案是不需要。因为如果b[j]不和a[i]配对，那就是和之前的a[1]..a[j-1]配对
（假设F[i-1][j]>0，等于0不考虑），这样必然没有和a[i]配对优越。
（为什么必然呢？
因为b[j]和a[i]配对之后的转移是max(F[i-1][k])+1，而和之前的i`配对则是max(F[i`-1][k])+1。
显然有F[i][j]>F[i`][j],i`>i
）
于是我们得出了状态转移方程：  
a[i]!=b[j]:   F[i][j]=F[i-1][j] 
a[i]==b[j]:   F[i][j]=max(F[i-1][k])+1 1<=k<=j-1&&b[j]>b[k]  
不难看到，这是一个时间复杂度为O(n^3)的DP，离平方还有一段距离。  
但是，这个算法最关键的是，
如果按照一个合理的递推顺序，max(F[i-1][k])的值我们可以在之前访问F[i][k]的时候通过维护更新一个max变量得到。
怎么得到呢？
首先递推的顺序必须是状态的第一维在外层循环，第二维在内层循环。
也就是算好了F[1][len(b)]再去算F[2][1]。 
如果按照这个递推顺序我们可以在每次外层循环的开始加上令一个max变量为0，
然后开始内层循环。当a[i]>b[j]的时候令max=max{F[i-1][j]}。
如果循环到了a[i]==b[j]的时候，则令F[i][j]=max+1。 
怎么说呢    我们看那么a[i]>b[j]一直取着最大值
而这里保存的值f[i][j]就是f[i-1][j](从递推式就可以知道)
所以一定要先将f[i-1][j]的值转移到f[i][j]中去
再取max   (很好懂吧不然你啥都没取到啊)
当a[i]==b[j]时   因为a[i]是不变的   
肯定就有b[j]>原先储存着的b[j](就是max存的值)
然后我们就可以直接用上这个值了
说通俗一点   就是我们在用一个a[i]去扫整个b[]的时候
如果不能构成LCS   并且a[i]>b[j]我们就顺手记下这些值的最大值就好了
最后答案是F[len(a)][1]..F[len(a)][len(b)]的最大值。
嗯这是我看到的一个挺详细的资料了
讲的很棒Orz
其实还有一个很风骚的一维的算法。
在此基础上压掉了一维空间（时间还是平方）。
i循环到x的时候，F[i]表示原来F[x][j]。
之所以可以这样，是因为如果a[i]!=b[j]，因为F[x][j]=F[x-1][j]值不变，F[x]不用改变，沿用过去的就好了，
就有点像背包一维算法的感觉
和这个比较维护更新得到的max值依然是我们要的。
而a[i]==b[j]的时候，就改变F[x]的值好了。
如果理解上上面二维算法
这个一维算法也挺好理解的QAQ
其实就是上面那个O(n^2)算法巧妙地去了一维
具体结合代码理解。
http://wenku.baidu.com/view/3e78f223aaea998fcc220ea0.html
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[510],b[510];
int f[510];
int main()
{
    int n,t,m;
    scanf("%d",&t);
    while(t--)
    {
        int m,ans=0;
        memset(f,0,sizeof(f));
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cin>>m;
        for(int i=1;i<=m;i++)
            cin>>b[i];
        for(int i=1;i<=n;i++)
        {
            int maxn=0;
            for(int j=1;j<=m;j++)
            {
                if(b[j]<a[i])   maxn=max(maxn,f[j]);
                if(b[j]==a[i])  f[j]=maxn+1;
                ans=max(f[j],ans);//记录所有出现过的f[j]的最大值
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
O(n^3)做法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[510],b[510];
int f[510][510];
int main()
{
    int n,t,m;
    scanf("%d",&t);
    while(t--)
    {
        int m,ans=0;
        memset(f,0,sizeof(f));
        
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        
        cin>>m;
        for(int i=1;i<=m;i++)
            cin>>b[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(a[i]!=b[j])
                    f[i][j]=f[i][j-1];
                else
                {
                    int s=0;
                    for(int k=1;k<i;k++)
                        if(a[k]<a[i])
                        s=max(s,f[k][j-1]);
                    f[i][j]=s+1;
                }
            }
        for(int i=1;i<=n;i++)
            ans=max(f[i][m],ans);
        cout<<ans<<endl;
    }
    return 0;
}
*/
