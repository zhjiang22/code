/*
经典的0/1背包问题
对于每株药 我们都有采或者不采两种情况
直接0/1就好了
注意这里不要求时间全部用完
所以初始化为0就好了
够裸够粗暴
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;

const int MAXN=1005;
int T,n;
int f[MAXN];

int main()
{
    cin>>T>>n;
    int t,w;
    for(int i=1;i<=n;i++)
    {
        cin>>t>>w;
        for(int j=T;j>=t;j--)
            f[j]=max(f[j],f[j-t]+w);
    }
    cout<<f[T]<<endl;
    return 0;
}