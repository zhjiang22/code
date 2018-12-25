#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

const int MAXN=100005;
struct node
{
    int t,s;
}a[MAXN];
int minn=0x7fffff;
int n;

inline bool cmp(const node&a,const node&b)
{
    return a.s<b.s;
}

void init()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].t>>a[i].s;
        minn=min(minn,a[i].s);
    }
    sort(a+1,a+n+1,cmp);
}

bool check(int x)
{
    int cur=x;
    for(int i=1;i<=n;i++)
    {
        if(cur+a[i].t>a[i].s)
            return 0;
        else
            cur+=a[i].t;
    }
    return 1;
}

int main()
{
    clock_t s=clock();
    init();
    if(!check(0))
    {
        cout<<-1<<endl;
        return 0;
    }
    int l=0,r=minn;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    cout<<l-1<<endl;
    cout<<(double)((clock()-s)/CLOCKS_PER_SEC)<<endl;
    return 0;
}
     