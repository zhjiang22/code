/*
嗯一道分类在并查集的题目
所以第一次看到这道题，我想到了最简单的BFS+并查集。
并查集用来处理多次查询的情况，如果相某个点已经被计算过，那么，和他联通的点就不用计算了，
直接输出结果。但是对于每一次查询，却要用BFS，BFS是复杂度最高的那种，以dist数组最小为止。
这种做法会超时。逻辑没有问题。属于一种半在线半离线的状态
然后就想了半天还是没想到怎么做
后面看了某个神犇的题解
发现精妙啊
从最外层开始Floodfill,联通的节点染同一种颜色，然后颜色+1，floodfill下一个联通。
这样相当于分层Floodfill，这样相当于从外到内，依次是：河流、陆地、河流、陆地...，
最后的结果就是(层数-1)/2。
切忌对于本题而言最外层可能不全是0，加一层0包围即可。
这样，Floodfill我用DFS来做，对于分层，用BFS来做。这样逻辑性更好一些。
即从(0,0)开始
先floodfill即dfs一下 对于他当前所能到达的点
如果在地图内并且未曾染色:
1.如果与当前点是相同性质，color涂上一样的颜色
2.如果是不同性质，color涂上另一种颜色，并且入队列(可以从这个点开始找下一层)
看到该神犇的代码中bfs队列中还判断了某个入队的点的八个联通点是否是下一层
但仔细想一下其实没有必要的
因为在dfs该点时，我们一定会标记到一个更里层(如果还有的话)
即更里层一定有一个点入队列了(并且更里层所有点都会被dfs到)
而我们知道floodfill多么强大
只要有一个点入了队列
就可以一定保证当前层的所有点都能染色
嗯总体来说还是不难的
也就是可以不用并查集的做法
Orz被吓了这么久233333
果然我太弱了
每日说三声我好弱 rp++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=1005;
struct node
{
    int x,y;
    node(int x,int y):x(x),y(y) {}
};
int color[MAXN][MAXN];
int a[MAXN][MAXN];
int n,k;
int zx[8][2]={{-1,0},{1,0},{-1,-1},{-1,1},{0,1},{0,-1},{1,-1},{1,1}};
queue<node> q;

void dfs(int x,int y,int cl)
{
     for(int i=0;i<8;i++)
     {
        int newx=x+zx[i][0];
        int newy=y+zx[i][1];
        if(newx>=0&&newx<=n&&newy>=0&&newy<=n&&color[newx][newy] == 0)
        {
            //如果属性相同 
            if(a[newx][newy]==a[x][y])
            {
                color[newx][newy]=cl;
                dfs(newx,newy,cl);
            }
            //属性不同就入队列,颜色值+1
            else
            {
                color[newx][newy]=cl+1;
                q.push(node(newx,newy));
            }
        }
     }
}

void bfs()
{
    node start(0,0);
    color[0][0]=1;
    q.push(start);

    while(!q.empty())
    {
        node now=q.front();
        q.pop();
        dfs(now.x,now.y,color[now.x][now.y]);

        /*for(int i=0;i<8;i++)
        {
            int newx=now.x+zx[i][0];
            int newy=now.y+zx[i][1];
            if(newx>=0&&newx<=n&&newy>=0&&newy<=n&&color[newx][newy]==0)
            {
                //如果属性不同就加一层  
                if(a[newx][newy]!=a[now.x][now.y])
                {
                    color[newx][newy]=a[now.x][now.y]+1;
                    q.push(node(newx,newy));
                }
            }
        }*/
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //注意用了scanf了就不能加这句话了不然就WA+RE
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%1d",&a[i][j]);
    bfs();
    int x,y;
    for(int i=1;i<=k;i++)
    {
        cin>>x>>y;
        cout<<(color[x][y]-1)/2<<" ";
    }
    return 0;
}
     