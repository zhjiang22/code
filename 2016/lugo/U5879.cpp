#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=500005;
int a[MAXN];
int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    long long ans=0;
    long long cur=0;
    for(int i=1;i<=n;i++)
    {
        cur+=a[i];
        cur=max(cur,0ll);
        ans=max(ans,cur);        
    }
    printf("%lld\n",ans);
    return 0;
}
