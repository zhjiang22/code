#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

int cost[210][210],d[210],a[210];
bool vis[210];
int n,m,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(cost,0,sizeof(cost));
    int x,y,c;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&c);
        if (cost[x][y]==0 || cost[x][y]>c)
            cost[x][y]=c;
    }
    int Min,p,temp;
    ans=0x7FFFFFFF;
    for (int i=1;i<=n;i++)
        if (cost[1][i]!=0)
        {
            temp=cost[1][i]; cost[1][i]=0;
            memset(d,127,sizeof(d));
            memset(vis,false,sizeof(vis));
            d[i]=0;
            for (int j=1;j<=n-1;j++)
            {
                Min=0xFFFFFFF; p=0;
                for (int k=1;k<=n;k++)
                    if (!vis[k] && d[k]<Min)
                    {
                        Min=d[k]; p=k;
                    }
                if (p==0) break;
                vis[p]=true;
                for (int k=1;k<=n;k++)
                    if (cost[p][k]!=0 && !vis[k] && d[k]>d[p]+cost[p][k]+a[k])
                        d[k]=d[p]+cost[p][k]+a[k];
            }
            cost[1][i]=temp;
            if (ans>cost[1][i]+a[i]+d[1])
                ans=cost[1][i]+a[i]+d[1];
        }
    if (ans<2100000000) printf("%d\n",ans);
    else printf("-1\n");
    return 0;
}
