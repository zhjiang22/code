#include<cstdio>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;  

 
int n,ans=0,k;  
int a[1000],b[1000];  
int f[1000+10]={0};//f[i]表示从i点出发的最长路  
int g[1000+10]={0};//g[i]表示从i点出发的最短路  
int map[1000+10][1000+10]={0}; //判断2个矩形是否存在可镶嵌的关系【有向图】   


int dp(int i)  
{  
    if(f[i])return f[i];//记忆化搜索  
    //如果当前情况已访问过直接返回  
       
    f[i]=1;//未尝试，赋初值  
       
    for(int j=1;j<=n;j++)  
    {  
        if(map[i][j])f[i]=max(f[i],dp(j)+1);  
        //状态转移方程   
    }  
    return f[i];  
}  
  
void print(int i)//输出从i开始   
{  
    cout<<i<<' ';  
      
    for(int j=1;j<=n;j++)  
       if(map[i][j]&&f[i]==f[j]+1)//如果i能嵌套在j内，输出i后面的矩形   
       {  
           print(j);   
           break;  
       }  
}  

int main()  
{  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d%d",&a[i],&b[i]);  
    }  
    for(int i=1;i<=n;i++)  
       for(int j=1;j<=n;j++)  
       {  
           if((a[i]<a[j]&&b[i]<b[j])||(a[i]<b[j]&&b[i]<a[j]))map[i][j]=1;  
       }//判断图是否存在，是否可以镶嵌   
      
    for(int i=1;i<=n;i++)f[i]=dp(i);  
    //尝试每个矩形镶嵌  
       
      
    for(int i=1;i<=n;i++)if(ans<f[i])ans=f[k=i];//找出最大的f[i]，并记录结点号k   
    printf("%d\n",ans);  
  
    print(k);  
  
    return 0;   
      
}  
