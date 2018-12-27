/*
详细看lrj训练指南P37啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=20005;
const int INF=(1<<30)-1;
int a[MAXN];
int Left[MAXN],Right[MAXN];
int ans;
int n;

void init()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=a[1];
}

void work2()
{
    for(int i=1;i<=n;i++)
        ans=max(ans,a[i]+a[i+1]);
    printf("%d\n",ans);
}

bool check(int p)
{
    int x=a[1],y=p-a[1];
    Left[1]=x;  Right[1]=0;
    for(int i=2;i<=n;i++)
        if(i%2)//奇数尽量往后放
        {
            Right[i]=min(y-Right[i-1],a[i]);
            Left[i]=a[i]-Right[i];
        }
        else
        {
            Left[i]=min(x-Left[i-1],a[i]);
            Right[i]=a[i]-Left[i];
        }
    return Left[n]==0;
}

void work1()
{
    int l=0,r=0;    ans=INF;
    for(int i=1;i<=n;i++)
    {
        l=max(l,a[i]+a[i+1]);
        r=max(r,a[i]*3);
    }
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
            ans=min(ans,mid),r=mid-1;
        else
            l=mid+1;
    }
    printf("%d\n",ans);
}

int main()
{
    init();
    if(n%2)
        work1();
    else
        work2();
}
     