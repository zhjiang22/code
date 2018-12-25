#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;  

const int maxn=10005; 
int c[maxn],n;  
int Lowbit(int k)  
{  
    return (k&-k);  
}  
void update(int pos,int num)  
{  
    while(pos<=maxn)//注意这里  
    {  
        c[pos]+=num;  
        pos+=Lowbit(pos);  
    }  
}  
int sum(int pos)  
{  
    int s=0;  
  
    while(pos>0)  
    {  
        s+=c[pos];  
        pos-=Lowbit(pos);  
    }  
    return s;  
}  
int main()  
{  
    int i,j,s;  
    scanf("%d",&n);
        memset(c,0,(n+3)*sizeof(c[0]));  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d",&s);  
            update(s,1);  
        }  
    while(scanf("%d",&i))
    {
        if(i==-1)
            break;
        else
            cout<<sum(i)<<endl;
    }
    return 0;  
}  