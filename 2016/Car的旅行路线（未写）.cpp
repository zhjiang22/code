#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int x[801],y[801];
int ti[501];
int n,s,tt,a,b;
double d[501][501];
void doit(int t1,int t2)
{
    d[t1][t2]=sqrt((x[t1]-x[t2])*(x[t1]-x[t2])+(y[t1]-y[t2])*(y[t1]-y[t2]));
    if (((t1-1)/4)==((t2-1)/4))
    {
        d[t1][t2]=d[t1][t2]*ti[(t1-1)/4+1];
    }else
        d[t1][t2]=d[t1][t2]*tt;
    d[t2][t1]=d[t1][t2];
    return;
}
int find(int t1,int t2,int t3)//找直角三角形斜边
{
    if ((d[t1][t2]>d[t2][t3])&&(d[t1][t2]>d[t3][t1])) return t3;
    if ((d[t2][t3]>d[t1][t2])&&(d[t2][t3]>d[t3][t1])) return t1;
    if ((d[t3][t1]>d[t2][t3])&&(d[t3][t1]>d[t1][t2])) return t2;
}
void doit2(int t1,int t2,int t3)//求第四个点的坐标（数学方法）
{
    doit(t1,t2);
    doit(t2,t3);
    doit(t3,t1);
    int haha=find(t1,t2,t3);
    if (haha==t1)
    {
        x[t3+1]=x[t3]+x[t2]-x[t1];  
        y[t3+1]=y[t3]+y[t2]-y[t1];  
    }
    if (haha==t2)
    {
        x[t3+1]=x[t3]+x[t1]-x[t2];  
        y[t3+1]=y[t3]+y[t1]-y[t2];   
    }
    if (haha==t3)
    {
        x[t3+1]=x[t1]+x[t2]-x[t3];  
        y[t3+1]=y[t1]+y[t2]-y[t3];  
    }
}
int main()
{
    scanf("%d",&n);
    for (;n>0;n--)
    {
        scanf("%d %d %d %d",&s,&tt,&a,&b);
        //S城市数，t飞机单价，A，B序号
        int i,j,k;
        for (i=1;i<=401;i++)
            for (j=1;j<=401;j++)
            d[i][j]=100000000;
        for (i=1;i<=s;i++)
        {
            scanf("%d %d %d %d %d %d %d",
            &x[4*i-3],&y[4*i-3],&x[4*i-2],
            &y[4*i-2],&x[4*i-1],&y[4*i-1],
            &ti[i]);
            doit2(4*i-3,4*i-2,4*i-1);
        }
        for (i=1;i<=4*s;i++)
            for (j=1;j<=4*s;j++)
            doit(i,j);
        for (k=1;k<=4*s;k++) 
            for (i=1;i<=4*s;i++)
                for (j=1;j<=4*s;j++) 
                    if (d[k][j]+d[i][k]<d[i][j])
                    {
                        d[i][j]=d[k][j]+d[i][k];
                    }
        double ans=200000000.0;
        for (i=4*a-3;i<=4*a;i++)
            for (j=4*b-3;j<=4*b;j++)
            if (d[i][j]<ans) ans=d[i][j];
        printf("%.1lf\n",ans);
    }
    return 0;
}
