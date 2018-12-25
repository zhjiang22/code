#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char rd;    int pn;
template<typename Type>
inline void read(Type& v)
{
    pn=1;
    while((rd=getchar())<'0'||rd>'9')
        if(rd=='-')
            pn=-1;
    v=rd-'0';
    while((rd=getchar())>='0'&&rd<='9')
        v=v*10+rd-'0';
    v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1)
{
    if(v==0)
        putchar(48);
    else  
    {
        if(v<0)
        {
            putchar('-');
            v=-v;
        }
        int len=0,dg[20];  
        while(v>0)
        {
            dg[++len]=v%10;
            v/=10;
        }  
        for(int i=len;i>=1;i--)
            putchar(dg[i]+48);  
    }
    if(c)
        putchar('\n');
    else
        putchar(' ');
}  
  
const int MAXN=105;
int a[MAXN];
int n,maxw;
  
int gcd(int a, int b)  
{  
    return b ? gcd(b, a % b) : a;  
}  

void init()
{
    read(n);
    for(int i=1;i<=n;i++)
    {
        read(a[i]);
        maxw=max(maxw,a[i]);
    }
}
  
void work()
{
    int maxgcd=maxw;
    int x;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            x=gcd(a[i],a[j]);
            maxgcd=gcd(maxgcd,x);
        }
    int moved=maxw/maxgcd-n;
    if(moved&1)
        printf("Alice\n");
    else
        printf("Bob\n");
}

int main(void)  
{    
    init();
    work(); 
    return 0;  
}  