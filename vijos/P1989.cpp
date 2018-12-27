/*
标解是这样的：
题目分析
把平面上每一个区域看作一个结点，最外层没有边界的区域也看作一个结点。
如果一个区域刚好被另外一个区域直接包含，则连边。构成的图上做最短路径即可以得到40~60的分数。
又发现，上述得到的图是树结构的，在树上预处理好任意两点的最近公共祖先，之后的询问可以线形完成，
这便可以得到满分。
但是其实可以有更简单的做法
先判断两个人在任意一个圆的圆内还是圆外，如果一个人在圆内，一个人在圆外，
那么必须破坏一个圆，复杂度为N*Q Orz
这样做就很水了 因为考虑到
如果直接返回圆心和该点的欧几里德距离
那么就又设计到了浮点数的问题了 QAQ我太弱所以最讨厌浮点数什么的
所以我们可以直接保留平方就好
因为都是正数嘛~比平方和比自己都是等效的
再运用异或   用两个bool值表示是否在某个圆外
只有异或值为真才要拆了一堵墙
所以这样就可以直接解决了QWQ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=8001;
const int MAXlog=21;
struct Edge
{
    int to,next;
}e[MAXN<<1];
int fisrt[MAXN];//Edges
struct P
{
    int x,y,r;
    bool operator<(const P& b)const
    {
        return r<b.r;
    }
}a[MAXN];
int fa[MAXN],L[MAXN];
int anc[MAXN][MAXlog];
int sumcost[MAXN][MAXlog];
int n,tot,q;

inline void Add_Edge(int x,int y)
{
    e[++tot].to=y;  
    e[tot].next=fisrt[x];   fisrt[x]=tot;
}

inline bool in(int& i,long long& x,long long& y)
{
    return (x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y)<=a[i].r*a[i].r;
}

int find(long long x,long long y)
{
    for(int i=1;i<=n;i++)
        if(in(i,x,y))
            return i;
    return n+1;
}

void init()
{
    memset(fisrt,-1,sizeof(fisrt));
    memset(anc,-1,sizeof(anc));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
}

inline bool han(int& i,int& j)//圆i是否包含于圆j
{
    int& x=a[i].x; int& y=a[i].y; int& r1=a[i].r;
    int& x2=a[j].x; int& y2=a[j].y; int& r2=a[j].r;
    if(r1>=r2)
        return 0;
    return (x-x2)*(x-x2)+(y-y2)*(y-y2)<=(r1-r2)*(r1-r2);
}

void getmap()
{
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        bool have=0;
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&han(i,j))
            {
                Add_Edge(i,j);  Add_Edge(j,i);
                have=1;
                break;
            }
        }
        if(!have)
        {
            Add_Edge(i,n+1);    Add_Edge(n+1,i);
        }
    }
}

void dfs(int u,int father)
{
    fa[u]=father;
    for(int i=fisrt[u];i!=-1;i=e[i].next)
        if(e[i].to!=father)
        {
            int& v=e[i].to;
            L[v]=L[u]+1;
            dfs(v,u);
        }
}

void pre()
{
    for(int i=1;i<=n+1;i++)
    {
        anc[i][0]=fa[i];
        sumcost[i][0]=1;
    }
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n+1;i++)
            if(anc[i][j-1]!=-1)
            {
                int& x=anc[i][j-1];
                anc[i][j]=anc[x][j-1];
                sumcost[i][j]=sumcost[i][j-1]+sumcost[x][j-1];
            }
}

int LCA(int p,int q)
{
    if(L[p]<L[q])
        swap(p,q);
    int mlog=1;
    for(;(1<<mlog)<=L[p];mlog++);   mlog--;

    int ans=0;
    for(int i=mlog;i>=0;i--)
        if(L[p]-(1<<i)>=L[q])
        {
            ans+=sumcost[p][i];
            p=anc[p][i];
        }
    if(p==q)
        return ans;
    for(int i=mlog;i>=0;i--)
        if(anc[p][i]!=-1&&anc[p][i]!=anc[q][i])
        {
            ans+=sumcost[p][i]; p=anc[p][i];
            ans+=sumcost[q][i]; q=anc[q][i];
        }
    ans+=2;
    return ans;
}

void question()
{
    long long x,y,x2,y2;    int p1,q1;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%lld%lld%lld%lld",&x,&y,&x2,&y2);
        p1=find(x,y);    q1=find(x2,y2);
        printf("%d\n",LCA(p1,q1));
    }
    /*for(int i=1;i<=n+1;i++)
        cout<<fa[i]<<" ";
    cout<<endl;*/
}

int main()
{
    init();
    getmap();
    dfs(1,-1);
    pre();
    question();
}
/*
解法2
#pragma GCC optimize("O2")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const long long MAXN=8010;
struct node
{
    long long x,y,r,s;
}p[MAXN];
int n;
int q;
long long ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].r);
        p[i].s=p[i].r*p[i].r;
    }
    cin>>q;
    while(q--)
    {
        ans=0;
        long long a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        for(int i=1;i<=n;i++)
        {
            long long way1=(a-p[i].x)*(a-p[i].x)+(b-p[i].y)*(b-p[i].y);
            long long way2=(c-p[i].x)*(c-p[i].x)+(d-p[i].y)*(d-p[i].y);
            bool f1=false,f2=false;
            if(way1>=p[i].s)
                f1=true;
            if(way2>=p[i].s)
                f2=true;
            if(f1^f2)
                ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
*/