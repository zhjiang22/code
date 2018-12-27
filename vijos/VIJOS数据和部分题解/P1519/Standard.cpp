#include <stdio.h>
#include <iostream>
using namespace std;
int n;//n for the height
unsigned long a[310][310];//a for the triangle
unsigned long f[310][310][310];//f[x] for the dp result for the highest x levels
unsigned long sum;//sum for the last result
void input();
void dp();
void getBest();
void output();
int main()
{
    input();
    dp();
    getBest();
    output();
    return 0;
}
void input()
{
     scanf("%d",&n);
     int i,j;
     for (i=1;i<=n;i++)
     {
         for (j=1;j<=i;j++)
         {
             scanf("%ld",&a[i][j]);
         }
     }
}
void dp()
{
     memset(f,0,sizeof(f));
     int i,j,k;
     for (i=1;i<=n;i++)//i for all levels
     {
         for (j=i;j>=1;j--)//j for inner levels 
         {
             for (k=1;k<=j;k++)//k for rows
             {
                f[i][j][k]=max(f[i][j+1][k],f[i][j+1][k+1]);
                f[i][j][k]+=a[j][k]; 
             }
         }
     }
}
void getBest()
{
     sum=0;
     int i,j,k;
     for (i=1;i<n;i++)//jump form i to i+1 (level)
     {
         for (j=1;j<=i;j++)
         {
             for (k=1;k<=i+1;k++)//jump form j to k (row)
             {
                 if (f[i][i][j]+f[n][i+1][k]>sum)sum=f[i][i][j]+f[n][i+1][k];
             }
         }
     }
}
void output()
{
     printf("%ld\n",sum);
}
