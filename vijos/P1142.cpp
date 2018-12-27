/*
两种做法   Orz反正我不会
第一
建棵树直接模拟即可，每次找花费最小的位置插入,结果是正确的
第二
动态规划
f[i][j]表示i个物品，使用j个指针的最小费用 
f[i][j]=min{f[j-1]+g[t][j]}
g[i][j]表示当前指针为j，使用了i个物品
g[i][j]=min{f[i][l]+p[j]*i*i)
初值f[1][1],g[1][x]
做到i时给f[1]赋值
于是复杂度就是O(n^2*k)
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
using namespace std;

int n,k,p[200],f[2000][200];

void init()
{
    memset(f,0,sizeof(f));
    memset(p,0,sizeof(p));
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= k; ++ i)
        scanf("%d",&p[i]);
    sort(p+1,p+1+k);
}

int mmin(int a,int b)
{
    if (a == 0)
        return b;
    else
        return min(a,b);
}

int dp(int x,int y,int l)
{
    if (x == 1)
    {
        f[x][y] = p[y];
        return f[x][y];
    }
    if (y == k)
    {
        f[x][y] = p[y] * x * x + dp(x,1,x-1);
        return f[x][y];
    }
    int temp;
    temp = k - y + 1;
    if (temp * l < x)
        return 0xFFFFFFF;
    if (f[x][y] != 0)
        return f[x][y];
    temp = (x-1) / (temp) + 1;
    for (int i = temp; i <= l; ++ i)
    {
        if (i == 1)
            f[x][y] = dp(x-1,y+1,x-2) + p[y];
        else
            f[x][y] = mmin( f[x][y] , dp(x-i,y+1,x-i-1) + dp(i,1,i-1) + i * i * p[y] );
    }
    return f[x][y];
}

int main()
{
    init();
    printf("%d",dp(n,1,n-1));
    return 0;
}