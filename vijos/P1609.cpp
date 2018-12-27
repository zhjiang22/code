/*
二分图？
OTZ我看到了很多种水法然而没看到二分图的水法
那么就让我来水一发吧
我们来看就两个门吧
我们先求出一个最大值Max 最小值Min
那么我们肯定可以这样:
贪心,让最大的和最小的分别走两个门一定是最优的
这个很明显吧如果是要差值不能大于k的话
那么我们肯定就知道了Max和Min其实是分别代表两个对立的门了
那么我们对于每一个v[i]
如果它和最大值最小值的差值都会大于k的话
肯定是两个门都走不了的会gg
不知道这样贪心对不对？
我这么弱不明白啊
感觉是不是数据太弱了有人按一个门直接做都90分
OTZ我好害怕
感觉二分图的话应该是差值在k之内的两个点连边
然后构造二分图来做？
然后看看有没有完美匹配？
OTZ本着我们是共青团员的本质上
我就决定好好再认真写一个二分图了
贪心留着玩233333
然而贪心0ms
二分图600ms
真是弱啊窝
*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN=1550;
int n,m,k;
int v[MAXN];
int link[MAXN];
bool visit[MAXN];
bool map[MAXN][MAXN];

bool dfs(int x)
{
    for(int i=1;i<=n;i++)
        if(map[x][i]&&!vis[i])
        {
            visit[i]=1;
            if(!link[i]||dfs(link[i]))
            {
                link[i]=x;
                return true;
            }
        }
    return false;
}


int main()
{
    int ans=0;
    cin>>n>>v[1]>>k;
    for(int i=2;i<=n;i++)
      cin>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                if(abs(v[i]-v[j])<=k)
                    map[i][j]=1;
    for(int i=1;i<=n;i++)
    {
        memset(visit,0,sizeof(visit));
        if(dfs(i))
            ans++;
    }
    if(ans==n)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
/*
#include <iostream>
using namespace std;
    
int v[1600];
int k,n;
    
int main()
{
    cin>>n>>v[1]>>k;
    for(int i=2;i<=n;i++)
        cin>>v[i];
    int Max=v[1],Min=v[1];
    for(int i=2;i<=n;i++)
    {
        if(v[i]>Max)
            Max=v[i];
        if(v[i]<Min)
            Min=v[i];
    }
    for(int i=1;i<=n;i++)
        if(v[i]-Min>k&&Max-v[i]>k)
        {
            cout<<"No";
            return 0;
        }
    cout<<"Yes";
    return 0;
}

*/