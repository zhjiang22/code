/*
好题~一个很经典的dp
状态和状态转移都很巧妙~
首先我们定义f[i][j]表示
到第i块水晶堆成高度差为j的双塔时,较矮塔的高度最大值
这样我们成功地将问题转换为了最优性问题
这样就可以尝试用DP来解决了~
既然想到了这样的状态表示必然是不难想到决策的
考虑到每个状态都可以由四个决策而来~
(这个时候最好自己拿起笔来画图手算模拟)
对于第i块水晶
1.不选取这块水晶	f[i-1][j]
2.将这块水晶放在高塔上	f[i-1][j-h[i]]	j-h[i]>=0
3.将这块水晶放在低塔上并且不改变高低塔关系	f[i-1][j+h[i]]+h[i]	j+h[i]<=s[i-1]
4.将这块水晶放在低塔上且改变了高低塔关系	f[i-1][h[i]-j]+h[i]-j 	h[i]-j>=0
这样我们就可以直接开始转移了~
这里需要好好手算理解一下
同时注意到如果一个f[i][j]是还未到到达的状态~
那么必然是不可行的
如果f[][]初始化为0那么可能某个f[i][j]是由一个本来无法到达的转移而来~
那么必然是不合法的
就像0/1背包中的要求装满的情况一样
我们应该将f[][]初始化为-INF
同时初值f[0][0]=1
同时注意几个限制条件
最终答案是
如果f[n][0]为0说明是不可行的输出无解
(注意因为不是-INF因为一直不选木块也可以成功转移到f[n][0]只是值为0)
不然最终答案就是f[n][0]
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXH=2005;
int f[MAXN][MAXH];
int h[MAXN];
int s[MAXN];
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		s[i]=s[i-1]+h[i];//维护前缀和
	}
}

inline void update(int& i,int& j)
{
	f[i][j]=f[i-1][j];//不放
	int h1=j-h[i];//放在高塔
	if(h1>=0)//限制条件
		f[i][j]=max(f[i][j],f[i-1][h1]);
	int h2=j+h[i];//放在低塔未改变高矮关系
	if(h2<=s[i-1])//必须h2要小于s[]限制条件
		f[i][j]=max(f[i][j],f[i-1][h2]+h[i]);
	int h3=h[i]-j;//放在低塔改变了高矮关系
	if(h3>=0)//限制条件
		f[i][j]=max(f[i][j],f[i-1][h3]+h3);
}

void DP()
{
	memset(f,-0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++)//由初始推向末尾
		for(int j=0;j<=s[i];j++)//j从0到s[i]才可行
			update(i,j);
	if(!f[n][0])//判断是否有解
		printf("Impossible\n");
	else
		printf("%d\n",f[n][0]);
}

int main()
{
	init();
	DP();
}
/*
最朴素最简单做法~
数据弱是可以过的而且也不卡时间
但是如果数据加强估计就不行了~~
预期得分65~70但是却无压力AC...
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int MAXV=2005;
int f[MAXV][MAXV];
int h[MAXN];
int sum;
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		sum+=h[i];
	}
}

void DP()
{
	f[0][0]=1;
	for(int k=1;k<=n;k++)
		for(int i=sum;i>=0;i--)
			for(int j=sum;j>=0;j--)
				if(f[i][j])
				{
					f[i+h[k]][j]=1;
					f[i][j+h[k]]=1;
				}
	for(int i=sum;i>=1;i--)
		if(f[i][i])
		{
			printf("%d\n",i);
			return;
		}
	printf("Impossible\n");
}

int main()
{
	init();
	DP();
}*/
/*
同时看到某神犇给出了上面思想代码的bitset优化~
这里就直接贴出来了
速度还是蛮快的
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<cmath>  
#include<bitset>  
using namespace std;  
int w[105],n,h[105],sum=0;  
  
int main()  
{  
    scanf("%d",&n);  
    for (int i=1;i<=n;i++)scanf("%d",&w[i]),sum+=w[i];  
    bitset<3000> f[3000];  
    for (int i=0;i<=sum;i++) f[i].reset();  
    f[0].set(1);  
    for (int i=1;i<=n;i++)  
    {  
        for (int j=sum;j>=0;j--) if (f[j].any())  
        {  
            f[j+w[i]]=f[j]|f[j+w[i]];//位运算的精髓  
            f[j]=f[j]|(f[j]<<w[i]);//精髓！  
        }  
    }  
    int ans;  
    for (ans=sum;ans>0;ans--) if (f[ans].test(ans+1)) break;  
    if (ans) printf("%d",ans);else printf("Impossible");  
    return 0;  
}  
*/