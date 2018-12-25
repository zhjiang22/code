/*
涨姿势啦    好题
在某个NOI2017金牌选手岑洋的指导下竟然刚下了这道题
哈哈这道题用到了一些bfs的技巧咯(事实上很多题可以这样搞)
我们令d[i][j]表示到i,j点最短路径长度
这个时候我们可以发现
因为点是可以重复走的
所以如果要最短路径到达终点
那么对于一个点来说到达这个点的距离也是要最小的
等等
这让我们想到了什么?
Bellman-Ford?    SPFA?   Dijkstra?
突然发现了这些最短路的共同之处Orz
好有道理啊有木有
所以我们bfs搜索的时候
对于当前点(u,v)所有可以到达的点(x,y)
当且仅当x,y不为障碍的时候
并且d[u][v]+k>d[x][y]的时候才将x,y入队
这里的k就是我们走一格的代价咯
如果是草地就是2    空地就是1
有没有感觉和SPFA的想法不谋而合
所以我们就可以直接裸着搜还是0ms
因为这个图决定了d[][]不会被更新太多太多
所以实际速度还是很快很快的
在bfs的时候不用判断是否到达终点
直接一次性bfs走到底
再根据d[to.x][to.y]判断了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=30;
const int MAX=1000;
const int INF=0x7fffff;
struct node
{
    int x,y;
}q[MAX];
int a[MAXN][MAXN];
int d[MAXN][MAXN];
int n,m;
int s,t;
int front,rear;
int zx[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
node start,to;

void init()
{
    char ch;
    cin>>t;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>ch;
            if(ch=='#')
                a[i][j]=2;
            else    if(ch=='o')
                a[i][j]=-1;
            else    if(ch=='.')
                a[i][j]=1;
            else    if(ch=='s')
                start.x=i,start.y=j,a[i][j]=1;
            else    
                to.x=i,to.y=j,a[i][j]=1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=INF;
}

int bfs()
{
    q[rear++]=start;
    d[start.x][start.y]=0;
    while(front!=rear)
    {
        node k=q[front++];   front%=999;
        for(int i=0;i<4;i++)
        {
            int newx=k.x+zx[i][0];
            int newy=k.y+zx[i][1];
            if(newx<1||newx>n||newy<1||newy>m)
                continue;
            if(a[newx][newy]!=-1)
            {
                int p=d[k.x][k.y]+a[newx][newy];
                if(p<d[newx][newy])
                {
                    d[newx][newy]=p;
                    q[rear++]=(node){newx,newy};    rear%=999;
                }
            }
        }
    }
    if(d[to.x][to.y]<t)
        return d[to.x][to.y];
    else
        return -1;
}

int main()
{
    init();
    int ans=bfs();
    if(ans==-1)
        cout<<"55555"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
     