/*
一个很老的经典的二分图的梗了
看成两部分分别为（1..n)和(1..m)的二分图
若(x,y)=1 则给x-->y连条边
问题转化为选出最少的点使以这些点为端点的所有边的集合为所有边的集合
也就是最小点覆盖数了
根据König定理我们可以知道 二分图的最大匹配等于这个图的最小点覆盖数
这个鬼东西自己记下来就好了
思路很简单
再简单重述一遍
就是对于有凸起的格子坐标为(x,y)
我们就在x,y中连一条边
然后直接裸的匈牙利算法求个最大匹配就是答案
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int map[102][102];
int Link[102]={0};
bool visit[102];
int n,m;

bool dfs(int x)
{
    for(int i=1;i<=m;i++)
        if(!visit[i]&&map[x][i])
        {
            visit[i]=1;
            if(!Link[i]||dfs(Link[i]))
            {
                Link[i]=x;
                return true;
            }
        }
    return false;
}

int main()
{
    char c;
    int ans=0;
    cin>>n>>m;
    getchar();
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        { 
            cin>>c;
            if (c=='1') 
                map[i][j]=1;
        }
        getchar();
    }
    for(int i=1;i<=n;i++)
    {
        memset(visit,0,sizeof(visit));
        if(dfs(i))
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
     