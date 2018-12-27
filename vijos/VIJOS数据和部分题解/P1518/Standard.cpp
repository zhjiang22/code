#include <stdio.h>
int n,k;
int left[101],right[101],wi[101],di[101];
int f[101][101][51];
int min(int a,int b){
    return a<b?a:b;
}
void init(){
    int v,w,d,i;
    scanf("%d%d",&n,&k);
    for (i=0;i<=n;i++) left[i]=right[i]=n+1;
    for (v=0;v<=n;v++) for (w=0;w<=n;w++) for (d=0;d<=k;d++) f[v][w][d]=-1;
    for (i=1;i<=n;i++){
        scanf("%d%d%d",&w,&v,&d);
        right[i]=left[v];
	    left[v]=i;
	    di[i]=d;
	    wi[i]=w;
    }
}
int work(int from,int to,int k,int s,int tx){
    if(from==n+1||to==n+1) return 0;
    if(f[from][to][k]!=-1) return f[from][to][k];
    int x=2147483647,i;
    for (i=0;i<k;i++){
        x=min(x,work(left[from],from,i,0)+work(right[from],to,k-i-1,s));
    }
    for (i=0;i<=k;i++){
        x=min(x,work(left[from],to,i,s+di[from])+work(right[from],to,k-i,s)+(s+di[from])*wi[from]);
    }
    f[from][to][k]=x;
    return x;
}
int main(){
    init();
    printf("%d",work(left[0],0,k,0));
    return 0;
}
