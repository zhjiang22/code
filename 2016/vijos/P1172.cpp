/*
数论题表示不懂
就直接贴个搜索的程序？
不要打表啊rp--
*/
#include <iostream>
#include <stdio.h>
using namespace std;
const int prime[16]= {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
long long ans=888888888888888,n;
int bestsum;

void work(long long num,int sum,int k)
{
    if(sum>bestsum)
    {
        bestsum=sum;
        ans=num;
    }
    else if(sum==bestsum&&num<ans)
    {
        ans=num;
    }
    else if(sum<bestsum&&num>ans)return;
    if(k>15)return;
    long long total=num;
    for(int i=1;i<=50;i++)
    {
        if(total*prime[k]>n)break;
        total*=prime[k];
        work(total,sum*(i+1),k+1);
    }
}
int main()
{
    cin>>n;
    work(1,1,1);
    cout<<ans<<endl;
    return 0;
}