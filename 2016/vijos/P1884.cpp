/*
用meet-in-the-middle的思想。
先一遍dfs暴力求出长度为[n/2]的情况下([x]表示对x下取整)，某一hash值f有多少个串与之对应。
求出33对于2^m的逆元inv，然后反向dfs后半段。可以秒出。
*/
#include <iostream>

using namespace std;

typedef unsigned int LL;

int n,k,m,maxd,mind;
LL inv,res;
LL sum[1<<25];

inline LL pow(LL a,LL x,LL mod){
    LL res=1;
    for(;x;x>>=1,(a*=a)&=mod) if(x&1) (res*=a)&=mod;
    return res;
}

void dfs(int dep,LL s){
    if(dep>=mind) sum[s&m]++;
    else for(int i=1;i<=26;i++) dfs(dep+1,(s<<5)+s^i);
}

void dfs2(int dep,LL s){
    if(dep>=maxd) res+=sum[s&m];
    else for(int i=1;i<=26;i++) dfs2(dep+1,(s^i)*inv);
}

int main()
{
    cin >> n >> k >> m;inv=pow(33,(1<<m-1)-1,(1<<m)-1);
    m=(1<<m)-1;maxd=n+1>>1;mind=n>>1;dfs(0,0);dfs2(0,k);
    cout << res << endl;
    return 0;
}