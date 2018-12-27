#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,k,tmp;
unsigned long long sum=0,ans=0,R[100001];

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&tmp);
        sum+=tmp;
        if (sum%k==0) ans++;
        ans=(ans+R[sum%k])%1234567;
        R[sum%k]++;
    }
    cout<<ans<<endl;
    return 0;
}