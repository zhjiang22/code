/*
f[i][t][k]表示第i行状态为k，下一行状态为t时的种数。
即k==1表示当前i行有雷否则无雷
t==1表示下一行有雷否则无雷
我们知道每一行的状态由之前一行和现在这行和下一行决定
而状态中又包含了当前行和下一行
所以我们只需要从上面行推来即可即dp[i-1][][]推来
即我们就可以根据当前i行的雷数递推
因为我们要求的是方案数 我们知道i行目前某个状态可能的方案数
是要能满足条件的所有方案数递推上来
然后一直推啊推推到第n行即可
根本不用状态压缩OTZ
毕竟我太弱了
其实这道题根本不用保存a[]数组
也可以省去那个f[][][]的第一维变成2维
但是如果用一个二维优化的话
一定要注意因为里面的f[][]是迭代更新的
所以我们不能直接先赋值给一个值再用已经改变了的值去赋值给另一个
而且会有环的关系你会发现不管咋交换都gg
所以我们先用变量存起来再交换就好了
嗯代码在下面2333
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[10010];
int f[10010][2][2];    //1下一行还需要一个1,0下一行不需要1

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    f[0][1][0]=1;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==0)//即i-1,i,i+1都无雷
        {
            f[i][0][0]=f[i-1][0][0];//只有f[i][0][0]有值为f[i-1][0][0]
        }
        else if (a[i]==1)//有一个雷
        {
            f[i][1][0]=f[i-1][0][0];//下一行有雷，所以上一个状态的当前行和下一行都应该无雷
            f[i][0][1]=f[i-1][1][0];//当前行有雷，所以上一个状态的当前行无雷但下一行有雷
            f[i][0][0]=f[i-1][0][1];//当前行和下一行无雷，则上一个状态的当前行有雷下一行无雷
        }
        else if (a[i]==2)//有两个雷
        {
            f[i][0][1]=f[i-1][1][1];//当前行有雷且下一行无雷，所以上一个状态的当前行和下一行有雷
            f[i][1][0]=f[i-1][0][1];//下一行有雷当前行无雷，所以上一个状态的当前行有雷下一行无雷
            f[i][1][1]=f[i-1][1][0];//当前行和下一行有雷，所以上一个状态的下一行有雷当前行无雷
        }
        else if (a[i]==3)//有三个雷
        {
            f[i][1][1]=f[i-1][1][1];//三个都一样要有雷直接从f[i-1][1][1]推过来
        }
    }
    printf("%d\n",f[n][0][0]+f[n][0][1]);//分成最后一行有无雷的情况相加
}

/*
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int f[2][2];   
int n,w;

int main()
{
    scanf("%d",&n);
    f[0][0]=1;
    f[1][0]=1;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&w);
        if (w==0)
        {
            //f[0][0]=f[0][0];
            f[1][1]=f[1][0]=f[0][1]=0;
        }
        else if (w==1)//有一个雷
        {
            int x=f[0][1],y=f[1][0],z=f[0][0];
            f[0][0]=x;
            f[1][0]=z;
            f[0][1]=y;
            f[1][1]=0;
        }
        else if (w==2)//有两个雷
        {
            int x=f[1][1],y=f[1][0],z=f[0][1];
            f[0][1]=x;
            f[1][1]=y;
            f[1][0]=z;
            f[0][0]=0;
        }
        else if (w==3)//有三个雷
        {
            //f[1][1]=f[1][1];
            f[1][0]=f[0][1]=f[0][0]=0;
        }
    }
    printf("%d\n",f[0][0]+f[0][1]);
}
*/
