/*
第三百题
好题>3<   涨姿势了
我们来看到这道题他的标签是最短路
和最短路有什么关系呢？
我们来看对于每一个人的空闲时间[x,y]    价值为w
那么说明如果我们用了这个人(有点像走了这条路)
就可以成功地从x走到y+1花费了w
而对于每一个人不一定要全部时间都用上
所以我们可以有对于每一个任意时间x
如果要从x走到x前面的任意一点再"找一条路"走下去
代价应该是0  即直接中断使用上一个人就好了
不一定要全部用完呀
所以我们就可以得出这样的结论了
我们要求的是s到t+1的最小价值
1.对于(x,y,w),我们连一条x到y+1的边权值为w
(当然要注意特判在s,t之外的情况
即如果没有交集直接忽略 有端点在s,t外直接接到s或者t+1就可以了)
2.对于所有的点i，连一条边i到i-1权值为0
这样我们就可通过一次SPFA求出s到t+1的最短路
无解的情况就是无法到达的情况了
所以都不用判负环就可以了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100000;
const int INF=0x7ffffff;
struct Edge
{
    int to,next,w;
    Edge()
    {
        to=next=-1;
        w=0;
    }
}e[MAXN<<1];
int fisrt[MAXN];
int d[MAXN];
int q[MAXN];
bool in[MAXN];
int s,t;
int n,tot;
int front,rear;

inline void Add_Edge(int x,int y,int w)
{
    tot++;
    e[tot].to=y;    e[tot].w=w;
    e[tot].next=fisrt[x];   fisrt[x]=tot;
}

void init()
{
    memset(fisrt,-1,sizeof(fisrt));
    int x,y,w;
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>w;
        if(x<=t&&y>=s)
            Add_Edge(max(x,s),min(y,t)+1,w);
    }
    for(int i=s;i<=t+1;i++)
        Add_Edge(i,i-1,0);
    for(int i=s;i<=t+1;i++)
        d[i]=INF;
}

void SPFA(int s,int n)
{
    q[rear++]=s;
    in[s]=1;    d[s]=0;
    while(front!=rear)
    {
        int x=q[front++];   front%=(MAXN-1);
        in[x]=0;
        for(int i=fisrt[x];i!=-1;i=e[i].next)
        {
            int y=e[i].to;  int w=e[i].w;
            if(d[y]>d[x]+w)
            {
                d[y]=d[x]+w;
                if(!in[y])
                {
                    in[y]=1;
                    q[rear++]=y;    rear%=(MAXN-1);
                }
            }
        }
    }
}

int main()
{
    init();
    SPFA(s,t-s+2);
    if(d[t+1]!=INF)
        cout<<d[t+1]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
     