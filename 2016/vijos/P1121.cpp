/*
递推即可
注意两个边界处理(即0行的递推和0列的递推)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i,j,x,y,n,m,f[100][100];
    long long ans[100][100];
    scanf("%d%d%d%d",&n,&m,&x,&y);
    memset(f,1,sizeof(f));
    memset(ans,0,sizeof(ans));
    ans[0][0]=1;
    f[x][y]=0,f[x+1][y+2]=0,f[x-1][y+2]=0;
    f[x+1][y-2]=0,f[x-1][y-2]=0,f[x+2][y+1]=0;
    f[x-2][y+1]=0,f[x+2][y-1]=0,f[x-2][y-1]=0;
    for (i=1; i<=n; i++)
        if (f[i][0])
            ans[i][0]=1;
        else break;
    for (i=1; i<=m; i++)
        if (f[0][i])
            ans[0][i]=1;
        else break;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (f[i][j])
                ans[i][j]=ans[i-1][j]+ans[i][j-1];
    printf("%lld\n",ans[n][m]);
    return 0;
}
