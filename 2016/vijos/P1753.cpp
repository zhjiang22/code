/*
1． x 和 a0 的最大公约数是 a1；
2． x 和b0 的最小公倍数是 b1。\
{
这道题主要思路是对a0,a1,b0,b1分解质因数，得到其对于50000以内每个质因子的幂a,down,b,up，然后对于方程组：
        min(a,x)=down
        max(b,x)=up
求|x|.
①一个条理的思路是将其分为八种情况讨论，这是非常优秀的。
②另一个更简洁的思路是分三种情况：
   |x|=0,               down>up||a>down&&b<up&&up!=down.
   |x|=up-down+1,除0且a==down&&b==up
   |x|=1.                除1且除2
这是基于这样一种简单的思路：
    若down==a,则x>=down即可，若down<a,则x=down.
    若up==b,则x<=up即可，若b<up,则x=up.
∴再加入对up与down大小的考虑，就得到了上面的结论。
亦即通过对三个关系的思考：
       up与down，a与down，b与up
 
这样当然是可以A掉这道题，但还是可以加一些很好的优化的。
③分解质因数时，从前往后扫每一个质数，若当前被分解的数甚至已经大于当前质数的平方时，实际上分解就可以停止了。这是最大质因子定理在在线分解过程中的一个非常优秀的应用。
④分解质因数时，在线一起分解四个数是要比分别分解每个数再乘是更好的及更简洁的。
⑤为了分解质因数先打出质数表是要比在线分解是要更好的，但一个需要十分注意的问题是代码长度。
⑥我们可以只分解在是最小公倍数的质因子的质数，这样的话可以提高效率，最终考虑的依然是上面三种情况，但是是需要仔细推敲的：
        1、a0可能会剩下很多质因子，由于它们不是b1的质因子，且它们可能不影响ans，但它们可能会对我们的判断造成一些蛋痛的影响。
        2、b1有可能剩下一个最大公因数，但也有可能只剩下一个1。

这道题也给我们一些教训：
⑦在做题的时候，一定不能忘记数学推导和演草纸，空想是很容易出错的；而思路一定要严谨、也一定要发散，注意转换，寻求最简单的代码写法。毕竟，考场上的时间是有限的。	
}
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a0,a1;
int b0,b1;
int tot;
int t;

int gcd(int a , int b)
{
    return b==0?a:gcd(b, a%b);
}

int main(int argc, char *argv[]) 
{
	scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        if(a0%a1 || b1%b0) { cout<<"0\n"; continue; }
        int ind1 = a0/a1 , ind2 = b1/b0;
        int cnt = 0;
        for(int i=1;i*i<=b1;i++)if(b1%i==0)
        {
            int x = i;
            if(x%a1==0)
                if(gcd(ind1, x/a1)==1 && gcd(ind2, b1/x)==1) cnt++;
            x = b1/i;
            if(x!=i && x%a1==0)
                if(gcd(ind1, x/a1)==1 && gcd(ind2, b1/x)==1) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}