/*
这道题有两种做法
1.建立无向图+最短路算法，难点在于建图，读入时间之后，把能到达的点之间都连上边，跑一遍SPFA，
边权就是出发点的点权，设最上是1号点，d[1]+w[1]就是答案
注意，本行行尾可以到达本行及上一行的行首
2，标程应该是动态规划吧
f[i][j]表示第i行第j个点到目标终点(1,1)的最小时间
则转换为数字三角形问题，但是只是多了几种走法，不断更新最小值就好了
但是问题就来了，这样动态规划具有最优子结构吗？
注意这是个环形走法
答案是不成立于的，怎么说？
我们来看一下这样一个例子，假设某个数据的第某层的时间为
1，1，1，1，1，1
而从下往上推上来一开始的初值f[][]分别为
1，2，4，3，9，10
那么我们先进行第一次同行内从左往右的更新的递推(可以看代码内的推法)
则有更新为
1，2，3，3，4，5
再从右往左更新推一遍
1，2，3，3，4，2(左端的1可以走到右端来更新了右端的时间)
那么这样就完了吗？不，我们可以发现我们可以用新更新的2去更新推出更优的解
则应该为
1，2，3，3，3，2
所以从这个样例中我们可以看出一次两边推根本的不出最优解
为什么呢？
我们看某次往一边推，由于是环形，所以可能从右向左推，用第一个更新了最右端的那个点
但是最右端的那个点在更新之前已经推完了右边数的第二个点
就是新更新的这个右端点并没有用来当作"下家"来更新别的点使别的点更优
同理从左往右也是一样
那么怎么办呢？
我们可以推两遍，这样假如更新了某个端点的值，在下一次递推时一定能用来作为"下家"尝试再更新别的点
那么这样问题就解决了
我们总结一下做法
首先每个点的初值为从下一层走到这一层的两个更优解
然后我们在同层迭代递推，左推一遍右推一遍，然后再重复推一遍
问题就解决了，so easy
*/
/*
DP
*/
/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1005;
int a[maxn][maxn];
int f[maxn][maxn];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        cin>>a[i][j];
    f[1][1]=a[1][1];//终点处就直接是该点时间
    for(int i=2;i<=n;i++)//一层一层往上推
    {
        for(int j=2;j<i;j++)//先求出从上一层推出来的最小值
            f[i][j]=min(f[i-1][j],f[i-1][j-1])+a[i][j];
        f[i][1]=min(f[i-1][1],f[i-1][i-1])+a[i][1];//特殊边界点处理
        f[i][i]=min(f[i-1][i-1],f[i-1][1])+a[i][i];//特殊边界点处理
        //同一层更新最优解
        for(int k=i-1;k>0;k--)//从右往左推 从右往左走的情况更新
            f[i][k]=min(f[i][k],f[i][k+1]+a[i][k]);
        f[i][i]=min(f[i][i],f[i][1]+a[i][i]);

        for(int l=2;l<=i;l++)//从左往右推 从左往右走的情况更新
            f[i][l]=min(f[i][l],f[i][l-1]+a[i][l]);
            f[i][1]=min(f[i][1],f[i][i]+a[i][1]);

        for(int k=i-1;k>0;k--)//再推一遍从右往左推 从右往左走的情况更新
            f[i][k]=min(f[i][k],f[i][k+1]+a[i][k]);
            f[i][i]=min(f[i][i],f[i][1]+a[i][i]);

        for(int l=2;l<=i;l++)//再推一遍从左往右推 从左往右走的情况更新
            f[i][l]=min(f[i][l],f[i][l-1]+a[i][l]);
                f[i][1]=min(f[i][1],f[i][i]+a[i][1]);
    }
    cout<<f[n][1]<<endl;
}*/
/*
SSSP
最短路很容易~
但是建图有点麻烦~~
因为考虑到如果从一个点往上连边的话
会有点小麻烦(可能不存在~)
那么我们可以从每一个点开始
每一个可以走到它的点向他连边
即向下找往上连
如果是在一行的首位置或者末位置就有5种被走上来的方法
否则四种走法
这个需要很小心注意一个地方写错了就gg(调了半小时)
好坑的地方就是这里的右上方=上方....
害怕~
然后用个等差数列求和公式求出对应的顶标就好啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXn=1005;
const int MAXN=500501;
const int MAXM=2500001;
const int INF=(1<<30)-1;
struct Edge
{
    int to,w,next;
}e[MAXM];
int fisrt[MAXN];//Edges
queue<int> q;
int d[MAXN],in[MAXN];//SPFA
int w[MAXn][MAXn];
int l,n,tot;

inline void Add_Edge(int x,int y,int w)
{
    e[++tot].to=y;  e[tot].w=w;
    e[tot].next=fisrt[x];   fisrt[x]=tot;
}

inline int getn(int x,int y)
{
    return x*(x-1)/2+y;
}

void init()
{
    memset(fisrt,-1,sizeof(fisrt));
    scanf("%d",&l); n=getn(l,l);
    for(int i=1;i<=l;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&w[i][j]);
}

void getmap()//建图从上向下建更方便
{
    Add_Edge(2,1,w[2][1]);
    Add_Edge(3,1,w[2][2]);
    for(int i=2;i<=l;i++)
        for(int j=1;j<=i;j++)
        {
            int u=getn(i,j);
            if(j==1)
            {
                Add_Edge(getn(i,i),u,w[i][i]);
                Add_Edge(getn(i,j+1),u,w[i][j+1]);
                if(i!=l)
                    Add_Edge(getn(i+1,i+1),u,w[i+1][i+1]),
                    Add_Edge(getn(i+1,j),u,w[i+1][j]),
                    Add_Edge(getn(i+1,j+1),u,w[i+1][j+1]);
            }
            else    if(j==i)
            {
                Add_Edge(getn(i,j-1),u,w[i][j-1]);
                Add_Edge(getn(i,1),u,w[i][1]);
                if(i!=l)
                    Add_Edge(getn(i+1,j),u,w[i+1][j]),
                    Add_Edge(getn(i+1,1),u,w[i+1][1]),
                    Add_Edge(getn(i+1,j+1),u,w[i+1][j+1]);
            }
            else
            {
                Add_Edge(getn(i,j-1),u,w[i][j-1]);
                Add_Edge(getn(i,j+1),u,w[i][j+1]);
                if(i!=l)
                    Add_Edge(getn(i+1,j),u,w[i+1][j]),
                    Add_Edge(getn(i+1,j+1),u,w[i+1][j+1]);
            }
        }
}

void SPFA(int s)
{
    memset(d,0x37,sizeof(d));
    q.push(s);  d[s]=0;  in[s]=1;
    while(!q.empty())
    {
        int u=q.front();    q.pop();    in[u]=0;
        for(int i=fisrt[u];i!=-1;i=e[i].next)
        {
            int& v=e[i].to; int& w=e[i].w;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                if(!in[v])
                {
                    q.push(v);
                    in[v]=1;
                }
            }
        }
    }
    cout<<d[1]+w[1][1]<<endl;
}

int main()
{
    init();
    getmap();
    SPFA(getn(l,1));
}
     