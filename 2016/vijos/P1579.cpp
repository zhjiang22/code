/*
好题啊 充分地体现了BST的原理和性质
我们先说一下啥叫最小完全图(vijos竟然不告诉窝这种弱弱CV上同样的题目却告诉惹)
果然我这种弱弱做不了vijos啊
若一个图的每一对不同顶点都恰有一条边相连，则称为完全图。
其实就是连通的图咯而且每对点都要有一条无向边
最小完全图就是要一个最小的权值咯
而对于完全图有很多种，原理上是有无限小的
但是我们这里要满足这个最小完全图的BST为我们给出的这个最小生成树
这就是关键的限制条件了
考虑到这样一个性质：
在一个建到一半的最小生成树中，两点直接连的边的距离一定严格大于它们在最小生成树上的路径边权最大值
所以我们可以首先把最小生成树中的边按边权从小到大排序，依次枚举每条边，
根据Kruskal的求最小生成树思路可知，加入这条边前两点属于不同的集合，
集合问题自然涉及到并查集思想了
而这条边又一定是连接这两个集合的边中边权最小的（因为这是唯一的最小生成树），于是要构成满足条件的最小完全图，
需要在两个集合之间连上（第一个顶点所在集合的点数*第二个顶点所在集合的点数-1）条边权为（当前边边权+1）的边，
并把这些边权加入到答案中。然后只需要在并查集的合并操作中顺便维护集合内的点数即可。
注意因为边权是int内
一乘就有可能会爆int
所以中间强制类型转换一下long long
或者直接用long long就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=20010;
struct Edge
{
    int x,y,w;
}e[MAXN];
int fa[MAXN];
int sum[MAXN];
int n;
int m;
long long ans;

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void Merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    fa[fx]=fy;
    sum[fy]+=sum[fx];
}

void inline Add_Edge(int x,int y,int w)
{
    m++;
    e[m].x=x;   e[m].y=y;   e[m].w=w;
}

void init()
{
    cin>>n;
    int x,y,w;
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y>>w;
        Add_Edge(x,y,w);
    }
    for(int i=1;i<=n;i++)
        sum[i]=1,fa[i]=i;
}

int main()
{
    init();
    sort(e+1,e+n,cmp);//注意边数为n-1
    for(int i=1;i<=n-1;i++)
    {
        int w=e[i].w;
        ans+=(w+(w+1)*(long long)((long long)sum[find(e[i].x)]*(long long)sum[find(e[i].y)]-1));
        Merge(e[i].x,e[i].y);
    }
    cout<<ans<<endl;
    return 0;
}
     