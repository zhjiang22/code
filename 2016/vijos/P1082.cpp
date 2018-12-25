/*
也算是一种题型了吧
SPFA多了一个约束条件即体力值要满足
一个可行法是
写3个SPFA，一个来判最短体力是否大于k，一个来判最短时间，然后二分再SPFA
看到题解区有一种这样的做法
在SPFA的时候多加一个条件：当前体力花费<=k，一次SPFA跑完
这样其实仔细想是错误的贪心法
可能你节约的时间会让你的体力无法到达
但是竟然神奇地也能AC(数据奇水)
比如我们有数据
4 4
1 3 5 2
1 2 1 2
2 3 2 2
3 4 2 1
1 4
6
答案是5但是如果用上面的贪心会是-1
正解应该是
直接跑两遍最短路，然后将所有可以用的边全部找出来，然后在跑一遍最短路求出最短时间即可
http://blog.csdn.net/dan__ge/article/details/52529145
但是看到数据范围其实并不大
完全可以搜索bfs或者dfs解决
我这里用的dfs很方便
直接深搜加入当前节点和当前所用时间以及所用体力为参数
加入剪枝
1.可行性剪枝havec>k return
2.最优性剪枝havet>ans(当前的最优可行时间) return
这样时间复杂度O(n+m)并且剪枝了
所以必然还是很快的
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=5005;
const int MAXM=40005;
const int INF=(1<<30)-1;
struct Edge
{
    int to,c,t,next;
}e[MAXM<<1];
int fisrt[MAXN];
bool vis[MAXN];
int n,m,tot,k;
int s,t;
int ans=INF;

inline void Add_Edge(int& x,int& y,int& c,int& t)
{
    e[++tot].to=y;  e[tot].c=c; e[tot].t=t;
    e[tot].next=fisrt[x];   fisrt[x]=tot;
}

void init()
{
    memset(fisrt,-1,sizeof(fisrt));
    scanf("%d%d",&n,&m);
    int x,y,c,t1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&x,&y,&c,&t1);
        Add_Edge(x,y,c,t1);  Add_Edge(y,x,c,t1);
    }
    scanf("%d%d%d",&s,&t,&k);
    vis[s]=1;
}

void dfs(int u,int havec,int havet)
{
    if(havec>k||havet>ans)
        return;
    if(u==t)
    {
        ans=min(ans,havet);
        return;
    }
    for(int i=fisrt[u];i!=-1;i=e[i].next)
    {
        int& v=e[i].to; int& c=e[i].c;  int& t=e[i].t;
        if(!vis[v])
        {
            vis[v]=1;
            dfs(v,havec+c,havet+t);
            vis[v]=0;
        }
    }
}

void out()
{
    if(ans==INF)
        printf("-1\n");
    else
        printf("%d\n",ans);
}

int main()
{
    init();
    dfs(s,0,0);
    out();
}

/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=5005;
const int MAXV=400005;
const int INF=0x7fffff;
struct node
{
    int to,next,w,c;
    node()
    {
        to=next=-1;
        w=c=0;
    }
}e[MAXV];
int fisrt[MAXN];
int q[MAXN+5];
bool in[MAXN];
int d[MAXN];
int c[MAXN];
int front,rear;
int n,m;
int s,t;
int tot;
int k;

void inline Add_Edge(int x,int y,int w,int c)
{
    tot++;
    e[tot].to=y;
    e[tot].w=w;
    e[tot].c=c;
    e[tot].next=fisrt[x];
    fisrt[x]=tot;
}

void init()
{
    int x,y,w,c;
    cin>>n>>m;
    memset(fisrt,-1,sizeof(fisrt));
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>c>>w;
        Add_Edge(x,y,w,c);
        Add_Edge(y,x,w,c);
    }
    cin>>s>>t;
    cin>>k;
    for(int i=1;i<=n;i++)
        d[i]=INF;
}

bool SPFA(int s)
{
    d[s]=0;
    in[s]=1;
    q[rear++]=s;
    while(front!=rear)
    {
        int x=q[front];
        front=(front+1)%MAXN;
        in[x]=0;
        for(int i=fisrt[x];i!=-1;i=e[i].next)
        {
            int u=e[i].to; int w=e[i].w;   int c1=e[i].c;
            if(d[x]+w<d[u]&&c[x]+c1<=k)
            {
                d[u]=d[x]+w;
                c[u]=c[x]+c1;
                if(!in[u])
                {
                    q[rear]=u;
                    rear=(rear+1)%MAXN;
                    in[u]=1;
                }
            }
        }
    }
    return d[t]!=INF;
}

int main()
{
    init();
    if(SPFA(s))
        cout<<d[t]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}*/
