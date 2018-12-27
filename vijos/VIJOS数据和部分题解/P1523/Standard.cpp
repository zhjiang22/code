//NOI 2002 Day 1 Problem 3 Dragon   by  Ziqing Mao
//This program was converted by JackDavid127
#include <stdio.h>
#include <string.h>
const int MaxN=500;
int g[MaxN+1][MaxN+1],brother[MaxN+1],son[MaxN+1],n,m,need,h[2][MaxN+1][MaxN+1];
bool v[MaxN+1];
void Init(){
     int i,j,p,k;
     scanf("%d%d%d",&n,&m,&need);
     memset(g,255,sizeof(g));
     for (p=1;p<n;p++){
         scanf("%d%d%d",&i,&j,&k);
         g[i][j]=g[j][i]=k;
     }
}
void Make(int now){
     int i;
     v[now]=1;
     for (i=n;i>=1;i--)
         if(!v[i]&&g[now][i]>=0) {brother[i]=son[now];son[now]=i;Make(i);}
}
int Get(int now,int father,int need,int head){
    int p,q,c,min1,k;
    if(now==0) {if(need==0) return 0; else return -1;}
    if(h[head][now][need]!=-1) return h[head][now][need];
    min1=2147483647;
    for (k=0;k<=need;k++){
        p=Get(brother[now],father,k,head);
        if(k==need) q=-1; else q=Get(son[now],now,need-k-1,1);
        if(p>=0&&q>=0)
          {if(head==1) c=p+q+g[father][now]; else c=p+q;
           if(c<min1) min1=c;
          }
        q=Get(son[now],now,need-k,0);
        if(p>=0&&q>=0)
          {if(head==0&&m==2) c=p+q+g[father][now]; else c=p+q;
           if(c<min1) min1=c;
          }
    }
    if(min1==2147483647) {h[head][now][need]=-2;return -2;}
    else {h[head][now][need]=min1;return min1;}
}
void Main(){
     int now,ans;
     memset(v,0,sizeof(v));
     Make(1);
     memset(h,255,sizeof(h));
     if(need+m-1>n) ans=-1;
     else ans=Get(son[1],1,need-1,1);
     printf("%d",ans);
}
int main(){
    Init();
    Main();
    return 0;
}
