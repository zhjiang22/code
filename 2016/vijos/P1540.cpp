/*
有多个珠子，给出部分珠子之间的相对上下位置和间距，问你这些珠子在满足给出的条件下，
是否能把珠子排列在一条竖直直线上，如果能，求出每个珠子距离最高的珠子的距离，珠子的位置可重叠。
可以根据珠子的位置关系建立一张有向图，A->B 为A比B高，权值为之间的距离。
可以发现必须满足下列三种情况：
1、图有连通；无法比较出不同连通分支的上下关系。
2、有向图没有环；根据位置的传递关系，不可能自己比自己低。
3、如果从A到B有多条路径，路径的长度都应该一样；要不然B的位置关系就会有二义性。
我本来的想法是按顺序验证上面三条规则，把有向图转为无向图判联通，用拓扑排序判环，
用DFS来判路径长度，想想太复杂了。后来想想其实没必要那么复杂。对于每条有向边，
添加一条负权反向边，任意选定一个点，假设它是最高点，离最高点的距离是0，
用DFS搜索可连向的点，如果新点未访问，则新点的距离就是当前点的距离加上边的权值，
如果新点被访问过，这需要验证当前点的距离加上边权是否与新点原来的权值相等，如果不相等，
则说明有冲突。如果DFS结束还有点没被访问，则说明图不连通。如果发现有点的距离为负数，
则说明那个点比搜索开始的点的距离更高。
另外还可以使用并查集的方法，A是B的双亲就表示A的位置比B的高，
对于每个节点保存当前到双亲节点的距离（为正值），这样在并查集的树中，
根节点与一个孩子的孩子的孩子.....的孩子的距离就可以在路径压缩的过程中计算出来：
对于两个不同集合的合并，由于在找集合的过程中使用了find函数，所以相关节点一定直接和集合树的根节点连接。
设现在要连接的节点是a、b，它们的根节点分别是roota和rootb, a与b的距离为c, a在b的上面。
集合的合并是集合根节点之间的连接，所以需要计算出根节点之间的距离P，
b到roota的距离应为d[a]+c, b到rootb的距离为d[b] ,
假设rootb成为roota的孩子，设P为rootb到roota的距离
P+d[b]=d[a]+c => P=d[a]+c-d[b].
若P为负，则说明rootb在roota的上面则roota应成为rootb的孩子，距离为P的绝对值。
否则就直接将roota接在rootb的上面，距离为P
上面说的很详细了
千万要记住
如果未出现错误现象   到了输出d[]时
一定要对所有的节点进行一次getfather
更新他们到根节点的距离
不然是不完全的
即你其实每一次修改某个点的d[]
都是要等到下一次getfather这个点才能得到更新连锁子节点
嗯我觉得最好的方法就是这个并查集了吧
QWQ强大无敌
%%%%%
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=505;
int fa[MAXN];
int d[MAXN];
int n,q;

int getfather(int x)//注意这里要先更新距离再找爸爸不然会WA一个点
{
    if (fa[x]==x) 
        return x;
    int t=fa[x];
    d[x]+=d[t];
    return fa[x]=getfather(t);
}

void init()
{
    cin>>n>>q;
    for(int i=0;i<=n;i++)
        fa[i]=i;
}

void solve()
{
    int x,y,c;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y>>c;
        int fx=getfather(x);
        int fy=getfather(y);
        if(fx!=fy)
        {
            int p=d[x]+c-d[y];
            if(p>=0)
                fa[fy]=fx,d[fy]=p;
            else
                fa[fx]=fy,d[fx]=-p;
        }
        else
            if(d[x]+c!=d[y])
            {
                cout<<-1<<endl;
                exit(0);
            }
    }
}

void out()
{
    for(int i=1;i<=n;i++)
        getfather(i);
    for(int i=1;i<=n;i++)
        cout<<d[i]<<endl;
}

int main()
{
    init();
    solve();
    out();
    return 0;
}
     