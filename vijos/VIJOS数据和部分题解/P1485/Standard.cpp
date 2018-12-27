#include <stdio.h>
int n,m;
int at1(int x){
    if(x<1) return x+n;
    if(x>n) return x-n;
    return x;
}
int main(){
    int f[31][31]={0},i,j;
    scanf("%d%d",&n,&m);
    f[1][2]=f[1][n]=1;
    for (i=2;i<=m;i++)
        for (j=1;j<=n;j++) f[i][j]=f[i-1][at1(j-1)]+f[i-1][at1(j+1)];
    printf("%d",f[m][1]);
    return 0;
}
