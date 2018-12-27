/*
先解释一下样例，合理的安排顺序是 1 4 2 3
因为是一道noip题所以题解百度上很多了自己看一下~
关键是要注意
1.怎么判断最小代价
2.一定不要忘了这是个环，所以还要试着逆序推一遍
http://wenku.baidu.com/view/878beb64783e0912a2162aa7.html
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=50005;
int n,near[maxn][3];
int target[maxn]/*目标序列*/,same[maxn];
bool use[maxn];

void init()
{
    cin>>n;
    int l,r;
    for (int i=1;i<=n;++i)
    {
        cin>>l>>r;
        near[i][1]=l;
        near[i][2]=r;
    }
}

void work()
{
    target[1]=1;
    use[1]=1;
    for (int i=1;i<=n-1;++i)     /*构建目标序列*/
    {
        if (!use[near[target[i]][1]])//如果目前点想坐的人没有被选
        {
            target[i+1]=near[target[i]][1];//选上
            use[near[target[i]][1]]=1;//标记已经选了
        }
        else if (!use[near[target[i]][2]])//目前点想坐的人没有被选
        {
            target[i+1]=near[target[i]][2];//选上
            use[near[target[i]][2]]=1;//标记
        }
        else//有冲突
        {
            puts("-1");
            return;
        }
        //注意此构造方法的合理性，如果方案正确，那么一定是如果A想和B坐，B一定想和A坐，
        //不然根本无法完成构造，那么如果一个人被当前点一个点选放在了下一个位置，
        //那么这个人就已经满足了一个心愿，接下来就直接将另一个"心愿人物"放在他右边
    }
    memset(same,0,sizeof(same));  /*顺序求解*/
    for (int i=1;i<=n;++i)
    {
        int delta=(target[i]-i+n)%n;//当i为右端点时会有负的，所以要+n取膜
        same[delta]++;//计算一遍各个点与标准位置的差距
    }
    int ans=1000000000;
    for (int i=0;i<=n-1;++i)
    {
        ans=min(ans,n-same[i]);//相当于枚举了顺序(环)，看以哪个点为头更优
    }
    memset(same,0,sizeof(same));  /*逆序求解*/
    for (int i=1;i<=n;++i)
    {
        int delta=(target[n-i+1]-i+n)%n;
        same[delta]++;
    }
    for (int i=0;i<=n-1;++i)
    {
        ans=min(ans,n-same[i]);//道理相同
    }
    cout<<ans<<endl;
}

int main()
{
    init();
    work();
    return 0;
}