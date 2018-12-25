/*
怎么看都感觉像是搜索的题目OTZ
然而却在动规里面Orz
可能是窝太弱了不懂神犇的世界叭
我们可以直接这样搜索(我觉得是我看到的最简单粗暴的方法了)
我们直接bfs搜索一下(也不算正宗bfs吧)
还不需要判重
我们先设置一个ans数组标记
初始化-1   如果ans[i][j]==x 说明第x步有可能走到这里
比如我们读进了一个第x步NORTH的操作
那我们就从所有的上一步能走的地方一直向上走(这里有点dfs的感觉)
直到走到一个不能走的X或者是到了边界
我们把这一步到过的地方的ans数组对应的位置设为当前的步数x
然后以此类推不断搜索
知道所有的操作完了
那么ans数组中值等于t(总步数)的位置对应的就是最后有可能的位置
还是很好写的
但是其实别的更好想到虽然更难写一点
dfs bfs都是可以得Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=205;
char g[MAXN][MAXN];
int ans[MAXN][MAXN];
int n,m,t;
int fx,fy;
string a;

void init()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='*')
                fx=i,fy=j;
        }
    memset(ans,-1,sizeof(ans));
    cin>>t;
}

void work(int x,int y,int k)
{
    if(a=="NORTH")
    {
        x--;
        while(x>0&&g[x][y]!='X')
            ans[x--][y]=k;
    }
    else    if(a=="WEST")
    {
        y--;
        while(y>0&&g[x][y]!='X')
            ans[x][y--]=k;
    }
    else    if(a=="SOUTH")
    {
        x++;
        while(x<=n&&g[x][y]!='X')
            ans[x++][y]=k;
    }
    else    if(a=="EAST")
    {
        y++;
        while(y<=m&&g[x][y]!='X')
            ans[x][y++]=k;
    }
}

void solve()
{
    ans[fx][fy]=0;
    for(int k=1;k<=t;k++)
    {
        cin>>a;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(ans[i][j]==k-1)
                    work(i,j,k);
    }
}

void out()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            {
                if(ans[i][j]==t)
                    cout<<"*";
                else    if(g[i][j]=='X')
                    cout<<'X';
                else
                    cout<<'.';
            }
        cout<<endl;
    }
}

int main()
{
    init();
    solve();
    out();
    return 0;
}
     