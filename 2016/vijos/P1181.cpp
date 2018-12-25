/*
这一题我用的是O(logn)的算法，理论上来说假设数据类型允许高精度的话，n=10^10000000 以内都可以在半秒出解。
说说思路：主要用了等差比数列求和（错位相减+等比求和），然后后期处理一下。
根据常识我们有：
1位数(1~9) 共有9个
2位数(10~99) 共有90个
3位数(100~999) 共有900个
...
n位数 共有 9*10^(n-1) 个
而一个n位数有n位，故所有n位数有 9n*10^(n-1) 位。令
a(n) = 9n*10^(n-1)
通过数学方法对 a(n) 求前n项和( 记作 f(n) )，得
f(n) = (1+ (9n-1) 10^n ) / 9
f(n) 代表的意义是 所有1位数，2位数，... ，n位数 的位数总和
例如 f(2) 代表1位数和2位数的位数总和，=189
因此我们只需要枚举并找到最小的 i ，使得 f(i)>=n (n是题目中给出的位数)，我们就可以判断出题目要输出的那一位来自一个 i 位数
根据本题数据范围，i 一定小于8 (可以用几何画板验证一下)
在程序中，
k 代表这一个 i 位数到底是所有 i位数中的第几个 (从0编号)
j 代表究竟要输出这个 i 位数的第几位 (从0编号)
s 还原出这个 i 位数
接着的循环就是提取 s 的左起第 j 位了
#include <stdio.h>
int pow10[10];
int tmp[10];
int f(int n){
    return (1+(9*n-1)*pow10[n])/9;
}
int main(){
    int n, i, j, k, s;
    scanf("%d", &n);
    pow10[0] = 1;
    for(i=1; i<10; i++)
        pow10[i] = pow10[i-1]*10;
    for(i=1; i<8; i++){
        if(f(i) >= n)
            break;
    }
    k = (n-f(i-1)-1)/i;
    j = (n-f(i-1)-1)%i;
    s = pow10[i-1]+k;
    for(i=0; s>0; i++, s/=10)
        tmp[i] = s%10;
    printf("%d\n", tmp[i-j-1]);
    return 0;
}*/
/*
数学解法害怕
但是数据不大直接枚举暴力也是可以得
直接暴力枚举1-i,每次n减去i的位数，直到n<=i的位数
*/
#include <cstdio>
#include <cstdlib>
using namespace std;
char t[11]="",ans;
int len(int x)
{
    if(x<10) return 1;
    else if(x<100) return 2;
    else if(x<1000) return 3;
    else if(x<10000) return 4;
    else if(x<100000) return 5;
    else if(x<1000000) return 6;
    else if(x<10000000) return 7;
    else if(x<100000000) return 8;
    else if(x<1000000000) return 9;
}
int main()
{
    int n,i=1;
    scanf("%d",&n);
    int tmp=len(1);
    while(1){
        if(n<=tmp) break;
        n-=tmp;
        i++;
        tmp=len(i);
    }
    sprintf(t,"%d",i);
    printf("%c",t[n-1]);
    return 0;
}