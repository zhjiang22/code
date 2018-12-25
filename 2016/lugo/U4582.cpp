#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int MAXN=300005;
map<int,int> p;
int a[MAXN];
int f[MAXN];
int top;
int n,m;
int len;

void init()
{
    int x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        p[x]=i;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        if(p[x]!=0)
            a[++len]=p[x];
    }
}

int find(int x)
{
    int l=1,r=top;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(x>f[mid])
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}

void LIS()
{
    for(int i=1;i<=len;i++)
    {
        if(a[i]>f[top])
            f[++top]=a[i];
        else
        {
            int x=find(a[i]);
            f[x]=a[i];
        }
    }
    cout<<top<<endl;
}

int main()
{
    init();
    LIS();
    return 0;
}