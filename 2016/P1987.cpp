/*
为了找出t和m的最大差，我们需要先找出所有可能的m，
也就是要算出来有哪些数字可以通过在n个数字中挑选k个来得到。
这一个简化版的01背包问题，记F[i][j][x]表示前i个数字中选出j个来，是否可以组成数字x。
这样做时间复杂度是O(nkMAXB)的，可以通过85%的数据。
又可以发现F[i][j][x]全都是boolean型的，考虑把多个F[i][j][x]在最后一维进行压缩，
例如我们可以用一个64位整数来表示64个boolean值。01背包的所有转移都可以用位运算来实现。
这便可以通过100%的数据。
又是一个NOIP模拟赛第一题，结果又是一个大佬的0/1背包
我还以为是一道水题呢结果直接暴力
唉位运算真的学的不好啊
考试碰到这个还是就老老实实写个朴素的0/1背包吧
可以得八十分？	我目测了一下规模
但是为了我的通过率	还是不试验了吧
下次拿同学号试试2333333
*/
#include <algorithm>  
#include <string>  
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <cstdlib>  
  
using namespace std;  
  
int f[69][69][19500],n,k,a,b,x[259];  
int main()  
{  
    scanf("%d%d%d%d",&n,&k,&a,&b);  
    for (int i=1;i<=n;i++) scanf("%d",&x[i]);  
      
    f[0][0][0]=1;//边界，前0个数选0个组成0是可以的  
    for (int i=1;i<=n;i++)  
    {  
        for (int j=1;j<=min(k,i);j++)  
        {  
       		for (int l=b;l>=x[i];l--)  
            	f[i][j][l]=f[i-1][j-1][l-x[i]] || f[i-1][j][l];  
 			for (int l=0;l<x[i];l++) 
 				f[i][j][l]=f[i-1][j][l];//前l<x【i】不能选x[i]，那么就只有，以上的不选x【i】的那种情况了  
        }  
        f[i][0][0]=1;//被这里坑了一段时间（没有考虑到，前i个数选0个，组成0是可以的）  
    }  
    int ans=0,last=0,now;  
    for (int i=1;i<a;i++) if (f[n][k][i]) last=i;  
    for (int i=a;i<=b;i++)  
    if (f[n][k][i])   
    {  
        if (last<a)//t在最小的时候，t==a时  
        {  
            ans=min(a-last,i-a);  
            last=i;  
        }  
        ans=max(ans,(i+last)/2-last),last=i;//t在两个数中间时，肯定方案最好  
    }   //在这里想了半天  
              
    ans=max(ans,b-last);//t在最大的时候t==b时  
    printf("%d",ans);  
    return 0;  
}  