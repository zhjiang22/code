/*
dp[i][j]=min(dp[i][j],dp[i−1][j−k]+Cal(i,k))
dp[i][j]表示前i个主题写j篇论文的最少时间。
初始化要注意，要设为无穷大
那么用change函数得到当前选此课题某个数量所需要的时间
这是普通做法
*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn=205;
long long f[maxn][maxn];
long long n,m;
struct node
{
    long long a,b;
}p[maxn];

long long change(long long cur,long long num)
{
    long long ans=1;
    for(long long i=1;i<=p[cur].b;i++)
        ans*=num;
    return p[cur].a*ans;
}

int main()
{
    cin>>n>>m;
    for(long long i=1;i<=m;i++)
        cin>>p[i].a>>p[i].b;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = INF;
    for(long long i=1;i<=n;i++)
        f[1][i]=change(1,i);
    for(long long i=2;i<=m;i++)
        for(long long j=1;j<=n;j++)
        {
            f[i][j]=f[i-1][j];
            for(long long k=0;k<=j;k++)
                f[i][j]=min(f[i][j],f[i-1][j-k]+change(i,k));
        }
    cout<<f[m][n]<<endl;
    return 0;
}
*/
/*
接下来是优化算法，类似0/1优化
第二层一定是要逆推的，因为第三层已经枚举了所有可能的选择数量，
则下一个数据读进来递推应该是建立在上一个已经选完的情况下
传说中的分组背包？
*/  
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn=205;
long long f[maxn];
long long n,m;
long long a,b;

long long change(long long b,long long num)
{
    long long ans=1;
    for(long long i=1;i<=b;i++)
        ans*=num;
    return ans;
}

int main()
{
    cin>>n>>m;
    memset(f,127,sizeof(f));
    f[0]=0;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        for(int j=n;j>=1;j--)//逆推
        {
             for(int k=0;k<=j;k++)//枚举选的数量
                f[j]=min(f[j],f[j-k]+a*change(b,k));
         }
    }
    cout<<f[n]<<endl;
    return 0;
}