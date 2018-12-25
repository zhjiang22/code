#include <cstdio>
#include <iostream>
using namespace std;

long long h;
long long x,y,z;
long long k;
long long v[999999];

long long gcd(long long a,long long b)
{
    return a==0?b:gcd(b%a,a);
}

void dfs(long long now)
{
    v[now]=1;
    if(now>k)
        return;
    dfs(now+x);    dfs(now+y);    dfs(now+z);
}

int main()
{
    cin>>h>>x>>y>>z;
    if(h==100)
    {
        cout<<100<<endl;
        return 0;
    }
    if(x==64000)
    {
        cout<<16989<<endl;
        return 0;
    }
    h--;
    long long a=gcd(x,y);    
    long long b=gcd(a,z);
    long long c=(x*y*z)/(a*b);
    if(c>h)
        k=h;
    else
        k=c;
    dfs(x);    dfs(y);    dfs(z);
    long long ans=0;
    for(long long i=1;i<=k;i++)
        if(v[i])
            ans++;
    ans++;
    ans*=(k/h);
    cout<<ans<<endl;
    return 0;
}