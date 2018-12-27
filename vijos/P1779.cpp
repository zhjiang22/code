/*
很明显是贪心
但是看到最大金币最小我竟然有种二分的冲动23333
然后仔细想想这怎么分啊666
怎么贪？
我们把左右手乘积更小的人排在前面
证明的博客很多，找了一个写的比较好的贴出来
{
看到这道题的使得获得奖赏最多的大臣，所获奖赏尽可能的少，我的第一想法是二分答案。但是又仔细想了想，答案不具有单调性，二分是行不通的。
再看看这道题，我感觉可以用贪心来做。也就是说先用贪心确定一种最优的方案，再在这个排列队伍中求得答案。
可以这样思考，相邻两个的人交换对于前面的人答案没影响（这不是废话么），而且对于后面的人答案也没有影响（这里很关键）。也就是说相邻两人的位置交换只会对这两个人产生影响。那么我们就先考虑这两个人。
设这两个人分别为i和i+1。左手数字为a[i]和a[i+1]，右手数字为b[i]和b[i+1]。两人的金币数为w[i]和w[i+1]。
记P[i]=a[1]*a[2]*a[3]*...*a[i]
可得：
w[i]=P[i-1]/b[i];
w[i+1]=P[i]/b[i+1];
又P[i]=P[i-1]*a[i]
那么 w[i+1]=P[i-1]*a[i]/b[i+1]=w[i]*a[i]*b[i]/b[i+1]
不难看出，在这个相邻的二元组中，前面的数不受后面的影响，而后面的金币数决定于w[i],a[i],b[i]。
推广到整个排队方案，前面的金币数和a[i],b[i]都会影响后面的答案。贪心原则便出来了：按a[i]*b[i]为关键字从小到大排序，相同的顺序无所谓。最后再扫一遍，算出答案即可。
此题需要注意一点：乘除法都要写高精度，且答案有10000多位。	
}
然而我辣么懒真心不想写高精度Orz
就直接贴个代码上来吧
我的弱逼无高精度代码留在下面警示大家233333
*/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
struct node
{
	unsigned long long x,y;
}a[MAXN];
int n;
unsigned long long ans;

bool cmp(node a,node b)
{
	return a.y*a.x<b.y*b.x;
}

void init()
{
	cin>>n;
	cin>>a[0].x>>a[0].y;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
}

int main()
{
	init();
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		unsigned long long x=1;
		for(int j=0;j<i;j++)
			x*=a[j].x;
		x/=a[i].y;
		ans=max(x,ans);
	}
	cout<<ans<<endl;
	return 0;
}
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1000+10;
struct Node{
    int a,b;
    bool operator <(const Node& rhs) const{
     return (a*b<rhs.a*rhs.b );  
    }
};
Node nodes[maxn];
struct gaojing{
    int A[10000];
    void init() {
        memset(A,0,sizeof(A)); //memset<-0
        A[0]=1;  //长度 
        A[1]=1;
    }
    void cheng(int x) {
        for(int i=1;i<=A[0];i++) A[i]=A[i]*x;  //先乘后进位 
        for(int i=1;i<=A[0];i++) {
            A[i+1]+=A[i]/10;
            A[i]%=10;
        }
        int tmp=0;
        if(A[A[0]+1]) {
            A[0]++;
            while(tmp=A[A[0]]/10,tmp) {
                A[A[0]+1]=tmp;
                A[A[0]]%=10;
                A[0]++;
           }
        }
    }
    void chu(int x) {
        int tmp=0;
        for(int i=A[0];i;i--) {
            int k=A[i];
            A[i]=(tmp*10+k)/x;
            tmp =(tmp*10+k)%x;
        }
        while(!A[A[0]]) A[0]--;
    }
    void print() {
        for(int i=A[0];i;i--) printf("%d",A[i]);
    }
};
gaojing ans,rec;
gaojing max_gaojing(gaojing a,gaojing b){
    if(a.A[0]>b.A[0]) return a; else if(a.A[0]<b.A[0]) return b;
    for(int i=a.A[0];i;i--)  {  //从最高位开始比较 
     if(a.A[i]>b.A[i]) return a;
     if(a.A[i]<b.A[i]) return b;
    }
    return a; 
}

int n;
int main() {
    scanf("%d",&n);
    for(int i=0;i<=n;i++) scanf("%d%d",&nodes[i].a,&nodes[i].b);
    sort(nodes+1,nodes+n+1);
    rec.init(); ans.A[0]=0;
    for(int i=1;i<=n;i++) { //高精与单精相运算 
        rec.cheng(nodes[i-1].a); 
        gaojing k=rec; k.chu(nodes[i].b);
        ans=max_gaojing(ans,k);
    }
    ans.print();
    return 0;
}