/*
20%的数据：随便搞搞
40%的数据：同上
60%的数据：枚举N次，每次枚举每一户人家，判断这一户人家是否被推销过，
找到选择哪一户人家会得到最大的疲劳值，累加到ans里即可。
注意：若选择在当前已选最靠右的一户人家（设为x）的左边的人家（设为y），
则答案只需要增加推销这户人家的疲劳值（即ans=ans+A[y]）。
而选择x右边的人家（设为z），则答案需要增加多出来的走路疲劳值和推销这户人家的疲劳值
（即ans=ans+(d[z]-d[x])*2+A[z]）。时间复杂度O(n2)
100%的数据：和60分数据差不多，
将枚举每一户人家改为用堆维护已选的最右边的那户人家（设为x）的左边推销疲劳值的最大值（
设为堆D1）和x的右边推销疲劳值加上来回走路疲劳值的最大值（设为堆D2）。
那么每次的答案就是ans=ans+max(D1[1],D2[1]-d[x]*2)。
求答案之前要判断D1[1]和D2[1]是否合法
（即D1[1]所对应的点在x左边且没选过，D2[1]所对应的点在x的右边且没选过）。
时间复杂度O(n log2 n)。
做模拟比赛的时候想了半天
想到了线段树？
然后线段树没有滑稽币不会啊
然后就果断打了个60分暴力QAQ
然后考完一看
这个堆优化不是很容易想到吗
唉果然被普及组吓坏了
都不敢想高级算法了直接交了个暴力
Orz我好害怕
说说我的理解吧
我们很容易看到
其实对于选择n个这个问题
可以贪心的
不难想到 X= i 时的最优方案一定从 X = i-1 时的最优方案的基础上再加一户宣传对象得来。
考虑 X = 1 时的选择，显然是所有住户中 Ai + 2Si 中最大的被选，
若有多个住户的 Ai + 2Si 相同，则优先选择 Si 最小的（想一想为什么）。
然后序列被划分成左右两个部分，选择左边住户获得 Ai 的贡献，
选择右边住户获得 Ai + 2(Si - T) 的贡献，T 表示当前划分界限到胡同入口的距离，
注意右边部分的贡献的大小关系相比最初并没有改变，只需要重新对左边住户的贡献进行排序。
于是可以建一个新优先队列将左边的所有住户加入，将原优先队列中被划分到左边部分的元素丢掉。
因为划分界线是一直往右移的，所以每个元素至多被加入两次，被删除两次，
说白了就是我们每次选一个最优
只有可能是两种情况
1.继续向右走扩大距离(这个情况肯定是要选择能得到最大疲劳值的点)
2.不继续向右走了(那么我们就直接在左边选一个推销疲劳值的最大的点了)
两种情况去最大就好了
考虑到范围很大
加了个堆(优先队列)优化咯
Orz就这样没了
*/
#include <cstdio>
#include <queue>
using namespace std;

const int MAXN=100010;
int d[MAXN],a[MAXN];
int Last,Next,n,Sum,Best;
priority_queue<int> q;//堆用来维护已选的最右边的点左边的最大值

void init()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&d[i]);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
}

void solve()
{
	Next=0;//Next用来记录下下一个最右边点的位置
    for(int k=1;k<=n;k++)
    {
        Last=Next;//已选的最右边的点
        if(!q.empty())//q非空(即不是第一次)
            Best=q.top()+d[Last]*2;//因为sum中只保存了所有选取的疲劳值而为保存走路的疲劳值
        						   //就是直接选取了左边的最优解
        else 
        	Best=0;
        for(int i=Last+1;i<=n;i++)//尝试右边可不可以更新最大疲劳值
            if(a[i]+d[i]*2>Best)
            {
                Best=a[i]+d[i]*2;
                Next=i;//记录下更新的右边的店
            }
        printf("%d\n",Sum+Best);
        if(Next==Last)//如果没有更新到最右边的点
        {
            Sum+=q.top();//就直接选取堆中的点
            q.pop();//选完了出栈
        }
        else//说明选取的是右边的点
        {
            for(int i=Last+1;i<Next;i++)//更新了最右边的点那么左边的点要跟到来入栈
            	q.push(a[i]);
            Sum+=a[Next];//选上了这个点
        }
    }
}

int main()
{
   	init();
   	solve();
    return 0;
}
/*
写了一个多小时AC。说一下思路。在下面的讨论中，假定入口在最左边。
观察样例，可以发现第 X-1 步选择的地点总是被包含在第 X 步选择的地点中。因此这题很可能具有贪心的可行性。仔细论证一下，可以证出这个结论是正确的。（可以运用反证法，类似 dijkstra算法 的证明方法）。
明白这一点后，算法的步骤即为：令集合 T 一开始为全体地点，sum=0。每一步从 T 中选取点 i，该点利益 E[i] 是各点中最大的，令 sum += E[i]，输出 sum，并将 i 点从 T 中删除。这里的利益指的是走到那个点能增加的的疲惫值。
那么利益EiEi如何计算呢？很显然，一开始时EiEi由下式给出
Ei=Ai+2∗SiEi=Ai+2∗Si
然而当选取了一个点后，E[i]需要进行相应的更改。以下的讨论中，
假设之前被选中的 S 最大的点（即最靠右的点）为 prev，当前被选中的点为 this 。
1) 为了让 this 不再被选中，令
Ethis=−∞Ethis=−∞
2) 对于 prev 和 this 之间（不含端点）的所有点 i，若 Sthis>SprevSthis>Sprev：
Ei=Ei−2∗(Si−Sprev)Ei=Ei−2∗(Si−Sprev)
否则 E[i] 不变。意思是：若 this 比起 prev 还往前走了一段距离，那么显然在后续过程中这些点所能获得的利益将减少两倍的 i 与 prev 间的距离。若没有往前走，那么该点利益维持不变。
3) 对于 this 右边的所有点 i，若 Sthis>SprevSthis>Sprev：
Ei=Ei−2∗(Sthis−Sprev)Ei=Ei−2∗(Sthis−Sprev)
否则 E[i] 不变。解释同情况 2。不明白的可以画图验证。
接下来需要考虑的问题是如何快速更新利益的值，并快速地找出其中的最大值。如果是纯暴力，每次需要 O(n) 来查询最大值与更新，总计是 O(n^2)，60分左右；如果用堆，每次查询需要 O(log n)，但更新需要 O(n log n)。还不如暴力。
因为涉及区间修改和查询，想到用线段树，维护区间最值，并需要支持区间更新。平摊下来查询与更新都是 O(log n)。之所以说是平摊，是因为第二种情况中，无法进行整段区间的更新，而只能单点更新（因为每个点减去的值不同），具体的时间复杂度是不定的。但是由于第二种情况对于每个点来说至多出现一次，单点更新的总次数是 O(n)，故平摊下来还是 O(log n)。
*/
/*
线段树
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int t[262145],tag[262145],S,n,pos;
int s[100010],a[100010];
priority_queue<int>Q;
void build() {
    for (S=1;S<=n+1;S<<=1);
    for (int i=1;i<=n;i++) {
        t[S+i]=s[i]+a[i];
        tag[S+i]=i;
    }
    for (int i=S-1;i>0;i--) {
        if (t[i<<1]>=t[(i<<1)+1]) {
            tag[i]=tag[i<<1];
            t[i]=t[i<<1];
        }
        else {
            tag[i]=tag[(i<<1)+1];
            t[i]=t[(i<<1)+1];
        }
    }
    return;
}
int query(int l) {
    int ans=-1,r=S+n+1;
    for (l+=S;l^r^1;l>>=1,r>>=1) {
        if ((l&1)^1 && ans<t[l^1]) {
            ans=t[l^1];
            pos=tag[l^1];
        }
        if (r&1 && ans<t[r^1]) {
            ans=t[r^1];
            pos=tag[r^1];
        }
    }
    return ans;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",s+i);
        s[i]<<=1;
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",a+i);
    }
    build();
    int now=0,total=0;
    for (int num=1,ans,re;num<=n;num++) {
        ans=-1;
        if (!Q.empty())
            ans=Q.top();
        re=query(now)-s[now];
        if (re>ans) {
            total+=re;
            for (int i=now+1;i<pos;i++) {
                Q.push(a[i]);
            }
            now=pos;
        }
        else {
            total+=Q.top();
            Q.pop();
        }
        printf("%d\n",total);
    }
    return 0;
}
*/
