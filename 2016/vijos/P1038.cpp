/*
很明显是一道合并石子的变形题
难点在于输出，输出和的顺序是从左到右，从里到外。
还有本题是有多解情况的，在动规寻找分割点时请让分割点尽量靠右（<改成<=）
即把括号尽量往前放，所以就要尽量让分割点在后部分(相同解时)
定义f[i][j]表示i到j段所能得到的最优解
则有DP方程：f[i][j]=min(f[i][k]+f[k+1][j]+getsum(i,j))+sum[i][j](i<=k<j)
sum[i][j]表示i到j段的数之和
k就是我们要找到的分割点
我们用g[i][j]表示i到j这段取到最大值时的分割点
因为要尽量让括号放在前面
所以如果解相同的话应该选择靠后面那个分割点
即用<=来完成
因为要维护两个数组f[][],g[][]所以我们要用记忆化搜索方法更好做
(这里递推和记忆化我都写了一遍)
然后求出值和分割点后我们就要递归输出答案了
考虑输出算式
递归下降输出就好，每次输出"("然后递归输出左部分，再是"+"，再是右部分,再是")"
边界自然也是x==y的时候输出a[x]即可
然后输出各段代价和也是递归输出就好，输出的是sum[][],因为是从内到外输出，
所以我们应该先递归下降左右两段，再输出当前的sum[x][y]
递归边界就是x==y的时候g[x][y]不存在为0
这个时候就不用输出了
嗯大体就是这样
详细见代码体会
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=22;
int f[MAXN][MAXN];
int g[MAXN][MAXN];
int a[MAXN];
int s[MAXN];
int n;

void init()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
}

inline int getsum(int i,int j)
{
    return s[j]-s[i-1];
}

void DP()
{
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)
        f[i][i]=0;
    for(int l=2;l<=n;l++)
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            for(int k=i;k<j;k++)
                if(f[i][k]+f[k+1][j]+getsum(i,j)<=f[i][j])//注意括号要尽量前所以应<=
                {
                    f[i][j]=f[i][k]+f[k+1][j]+getsum(i,j);
                    g[i][j]=k;
                }
        }
}

void print(int x,int y)
{
    if(x==y)//边界
    {
        printf("%d",a[x]);
        return;
    }
    printf("(");
    int& k=g[x][y];
    print(x,k);
    printf("+");
    print(k+1,y);
    printf(")");
}

void prints(int x,int y)
{
    if(!g[x][y])
        return;
    int &k=g[x][y];
    prints(x,k);
    prints(k+1,y);
    printf("%d ",getsum(x,y));
}

void printans()
{
    printf("\n%d\n",f[1][n]);
}

int main()
{
    init();
    DP();
    print(1,n);
    printans();
    prints(1,n);
}
/*
dp(1,n)即可
int dp(int x,int y)//注意两个边界处理
{
    if(f[x][y])//记忆化
        return f[x][y];
    if(x==y)//无法合并
        return 0;
    if(x==y-1)
    {
        g[x][y]=x;
        return f[x][y]=a[x]+a[y];
    }
    int minv=INF,w=0;
    for(int k=x;k<y;k++)
    {
        if(dp(x,k)+dp(k+1,y)+sum[x][y]<=minv)//<=，这样可以让w(分割点靠后
        {
            minv=dp(x,k)+dp(k+1,y)+sum[x][y];
            w=k;//记录分割点
        }
    }
    g[x][y]=w;
    return f[x][y]=minv;
}*/