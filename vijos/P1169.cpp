/*
二分图最优完美匹配       KM算法Orz
考虑到也就只有男的和女的两种人咯(难道还有双性？)
然后就很明显考虑到二分图咯   但是关键难点在于建图QAQ
QWQ而且字符串处理也很麻烦(对于我这种弱弱来说233333)
但主要是判断两个人是否能连成一条边啊
要满足两个条件
1.要在射程范围内，这个就很简单，我们直接求出两个点的欧几里德距离就好了
没啥很大的难度
2.两个人的连线上不能有另外一个人
这个也不麻烦，因为n也就不超过30吧，直接暴力一点咯
枚举所有人判断是否在一条直线上
如果三个点在一条直线上，那么一定可以根据直角三角形之类的组成相似三角形咯
这个就自行脑补了我提供了一种判断的方法
那么理清了这个我们在处理好name后，然后对于每对点，如果满足这个我们就拉一条无向边
这样就成功地构成了一个二分图模型QAQ
然后就是求这个二分图的最优完美匹配了
嗯这个就是裸的KM算法了(原谅我不会网络流啊)
然后我用的是O(n^4)的KM算法啊
实际上是可以优化顶标查找使算法到O(n^3)
Orz但是实际上这种图的最优匹配都是很好找的
所以O(n^4)比O(n^3)也慢不了多少
而且n也很小
所以偷个懒就写了个朴素的KM算法咯
也算是练习了一下KM算法了
一道好题~   调了一中午QAQ
还要特别注意的一个地方 对于两者不能连线的情况
一定要将其权值设为-INF而不能是0
不然第五个点稳稳地爆炸啊
QAQ一定要小心细节  一个地方炸了全都炸
建议每写好一个部分就测试一下  确保无误再写下一部分
但还是有个小小的疑惑在心里
在处理边的时候 本来按道理是男的和女的才能连边？
但是我直接男的和男的连边(标记的地方 把i,j的循环是对于所有n个点的)
结果也能AC  
这不符合我的意志    这非常尴尬QAQ
留到以后来考虑吧    先去QAQ了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=2000;
const int INF=0x7fffff;
struct node
{
    int x,y;
}a[MAXN];
int n,m,maxd;
int w[MAXN][MAXN];
int lx[MAXN],ly[MAXN],slack[MAXN];
int s[MAXN],t[MAXN];
int match[MAXN];
int ans;
string name[MAXN];

bool Dist(int n1,int n2)
{
    return sqrt((a[n1].x-a[n2].x)*(a[n1].x-a[n2].x)
               +(a[n1].y-a[n2].y)*(a[n1].y-a[n2].y))<=maxd;
}

bool Dir(int n1,int n2)
{
    if(a[n1].x==a[n2].x)
    {
        for(int i=1;i<=n;i++)
            if(i!=n1&&i!=n2)
                if(a[i].x==a[n1].x)
                    if(a[i].y<=max(a[n1].y,a[n2].y))
                        if(a[i].y>=min(a[n1].y,a[n2].y))
                            return  false;
        return true;
    }
    else
    {
        for(int i=1;i<=n;i++)
                if(i!=n1&&i!=n2)
                    if(a[i].x<=max(a[n1].x,a[n2].x))
                        if(a[i].x>=min(a[n1].x,a[n2].x))
                            if((a[n1].y-a[i].y)*(a[n2].x-a[i].x)==
                               (a[n2].y-a[i].y)*(a[n1].x-a[i].x))
                                return false;
            return true;
    }
}

string change(string x)
{
    int k=x.length();
    for(int i=0;i<k;i++)
        if(x[i]>='A'&&x[i]<='Z')
            x[i]-=('A'-'a');
    return x;
}

void init()
{
    cin>>maxd>>n;
    n*=2;
    //for(int i=1;i<=n;i++)
        //for(int j=1;j<=n;j++)
            //w[i][j]=-INF;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>name[i];
    for(int i=1;i<=n;i++)
        name[i]=change(name[i]);
    string s1,s2;
    while(true)
    {
        cin>>s1;
        if(s1=="End")
            break;
        cin>>s2;
        s1=change(s1);
        s2=change(s2);
        int n1=0,n2=0;
        for(int i=1;i<=n;i++)
            if(name[i]==s1)
            {
                n1=i;
                break;
            }
        for(int i=1;i<=n;i++)
            if(name[i]==s2)
            {
                n2=i;
                break;
            }
        int k;
        cin>>k;
        if(Dist(n1,n2)&&Dir(n1,n2))
            w[n1][n2]=w[n2][n1]=k;
    }

    for(int i=1;i<=n/2;i++)
        for(int j=n/2;j<=n;j++)//Orz不解
            if(i!=j&&!w[i][j])
                if(Dist(i,j)&&Dir(i,j))
                    w[i][j]=w[j][i]=1;
    //没有边相连就要设为-INF而不能为0！！！
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!w[i][j])
                w[i][j]=-INF;
}

bool dfs(int x)
{
    s[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(lx[x]+ly[i]==w[x][i]&&!t[i])
        {
            t[i]=1;
            if(!match[i]||dfs(match[i]))
            {
                match[i]=x;
                return true;
             }
        }
    }
    return false;
}

void update()
{
    int a=INF;
    for(int i=1;i<=n;i++)   if(s[i])
        for(int j=1;j<=n;j++)   if(!t[j])
            a=min(a,lx[i]+ly[j]-w[i][j]);
    for(int i=1;i<=n;i++)
    {
        if(s[i])    lx[i]-=a;
        if(t[i])    ly[i]+=a;
    }
}

void KM()
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(match,0,sizeof(match));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            lx[i]=max(lx[i],w[i][j]);
    for(int i=1;i<=n;i++)
        for(;;)
        {
            memset(s,0,sizeof(s));
            memset(t,0,sizeof(t));
            if(dfs(i))
                break;
            else
                update();
        }
    for(int i=1;i<=n;i++)
        ans+=w[i][match[i]];
    cout<<ans/2<<endl;
}

int main()
{
    init();
    KM();
    return 0;
}
     