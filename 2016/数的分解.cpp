#include<cstdio>

using namespace std;

int dp[210][7],n,k,i,j;

int main()

{

    scanf("%d%d",&n,&k);

    dp[0][0] = 1;

    for(i=1;i<=n;i++)dp[i][1]= 1;

    for(i=1;i<=n;i++)

        for(j=1;j<=k;j++)

         if(i>=j)

 dp[i][j]=dp[i-j][j]+dp[i-1][j-1];

    printf("%d\n",dp[n][k]);

return 0;

}