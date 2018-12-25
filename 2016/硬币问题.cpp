#include<stdio.h>  
#include<stdlib.h>  
#include<iostream>  
#include<algorithm>
#define INF 1<<30  
#define maxn 100+10  
using namespace std ;  
int V[maxn],n;  
int Min[maxn],Max[maxn];  

  
//打印可行的方案   
void print_ans(int* d,int S)  
{  
  for(int i=1;i<=n;i++)  
  {  
    if(S>=V[i] && d[S]==d[S-V[i]]+1)  
    {  
       printf("%d ",V[i]);  
       print_ans(d,S-V[i]);  
       break;  
    }  
  }  
}  
int main()  
{  
  int S;  
  while(scanf("%d%d",&S,&n)) //输入面值S和面值的种数n   
  {       
    for(int i=1;i<=n;i++)  
      scanf("%d",&V[i]);  
      Max[0]=0; Min[0]=0;  
    for(int i=1;i<=S;i++)  
      Min[i]=INF,Max[i]=-INF;  
    //递推实现   
    for(int i=1;i<=S;i++)  
      for(int j=1;j<=n;j++)  
        if(i>=V[j])  
        {  
          Min[i]=min(Min[i],Min[i-V[j]]+1);  
          Max[i]=max(Max[i],Max[i-V[j]]+1);  
        }  
     print_ans(Min,S);    
     printf("    Min\n");  
     print_ans(Max,S);    
     printf("    Max\n");  
     printf("min:%d max:%d\n",Min[S],Max[S]);     
  }  
  return 0;  
}  