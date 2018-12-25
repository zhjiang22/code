#include <iostream> 
#include <algorithm>
using namespace std;
int dp[2005];
int main()
{
int a[2005],n,k;
cin>>n>>k;;
for(int i=1;i<=n;i++)
{
cin>>a[i];
}
for(int i=2;i<=n;i++)
{
    for(int j=1;j<i;j++)
    {   



        if((dp[j]+1)%k==0)
        {
            if((dp[j]+1)/k%2==0)
            {
                if(a[i]>a[j])
                    dp[i]=max(dp[j]+1,dp[i]);
            }
            else
                {
                    if(a[i]<a[j])
                        dp[i]=max(dp[j]+1,dp[i]);
                }
        }
        else
        {
            if(((dp[j]+1)/k+1)%2==0)
            {
                if(a[i]>a[j])
                    dp[i]=max(dp[j]+1,dp[i]);
            }
            else
                {
                    if(a[i]<a[j])
                        dp[i]=max(dp[j]+1,dp[i]);
            }
        }

    }
}
int maxn=0;
for(int i=1;i<=n;i++)
{  maxn=max(dp[i],maxn);
}
cout<<maxn+1<<endl;
return 0;
} 