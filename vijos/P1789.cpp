/*
一道数学排列组合的问题的样子？
分情况讨论
我们注意到这个字母是可以重复使用的只要保证串不完全相同即可
所以当k=1的时候,答案是所有的序列数即是m^n
当k>n的时候也是合法的，此时答案随便搞都满足也是m^n
当n=k的时候，显然这是个排列就能做的，
枚举一半必定有且只有一个另一半与之对应，所以直接做就行了。
当k是奇数的时候，我们可以假设有一个奇数长的模型，每一次向右移动一个，
显然最前边和最后边、此前边和次后边以此类推，他们都是相等的，也就是说，
这个序列一定由两个元素组成（可以相同）那么显然有m*m种方法
当k是偶数的时候，根据前边的分析，显然只有m种序列（每一种序列的元素是一模一样的）
因为m,n的范围不大所以也用不上快速幂直接朴素的乘法就好了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long MD=1e9+7;
long long n, m, k, ans=1;

long long mul(long long a, long long b) 
{ 
    return ((a%MD)*(b%MD))%MD; 
}

int main() 
{
    cin>>n>>m>>k;
    if(k==1 || k>n) 
        for(int i=1;i<=n;i++) 
            ans=mul(ans, m);
    else if(n==k) 
    {
        long long mid=(n+1)>>1; 
        ans=1;
        for(int i=1;i<=mid;i++) 
            ans=mul(ans, m);
    }
    else if(k&1) 
        ans=mul(m, m);
    else 
        ans=m;
    cout<<ans%MD<<endl;
    return 0;
}