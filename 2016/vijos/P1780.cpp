/*
平衡树+倍增
Orz我太弱根本不会
共勉
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=~0U>>2;
int n;
struct High
{
    int ord,Val;
}R[100005];
int H[100005];
struct List
{
    int Val,next,last;
}L[100005];
inline bool Cmp(const High& A,const High& B)
{
    return A.Val<B.Val;
}
struct Tree
{
    int S_A,S_B;
    int C_A,C_B;
    int S[18],CA[18],CB[18];
}T[100005];
inline void Build(int Pc,int Pr)
{
    T[Pc].C_A=T[Pc].C_B=INF;
    if (L[Pr].last)
        if (H[Pc]-H[L[L[Pr].last].Val]<T[Pc].C_B)
            T[Pc].S_B=L[L[Pr].last].Val,T[Pc].C_B=H[Pc]-H[L[L[Pr].last].Val];
    if (L[Pr].next)
        if (H[L[L[Pr].next].Val]-H[Pc]<T[Pc].C_B)
            T[Pc].S_B=L[L[Pr].next].Val,T[Pc].C_B=H[L[L[Pr].next].Val]-H[Pc];
    if (T[Pc].S_B)
    {
        if (L[Pr].last)
        {
            if (L[L[Pr].last].Val!=T[Pc].S_B)
                T[Pc].S_A=L[L[Pr].last].Val,T[Pc].C_A=H[Pc]-H[L[L[Pr].last].Val];
            if (L[L[Pr].last].last && L[L[Pr].last].Val==T[Pc].S_B)
                T[Pc].S_A=L[L[L[Pr].last].last].Val,T[Pc].C_A=H[Pc]-H[T[Pc].S_A];
        }
        if (L[Pr].next)
        {
            if (L[L[Pr].next].Val!=T[Pc].S_B)
                if (H[L[L[Pr].next].Val]-H[Pc]<T[Pc].C_A)
                    T[Pc].S_A=L[L[Pr].next].Val,T[Pc].C_A=H[L[L[Pr].next].Val]-H[Pc];
            if (L[L[Pr].next].next && L[L[Pr].next].Val==T[Pc].S_B)
                if (H[L[L[L[Pr].next].next].Val]-H[Pc]<T[Pc].C_A)
                    T[Pc].S_A=L[L[L[Pr].next].next].Val,T[Pc].C_A=H[L[L[L[Pr].next].next].Val]-H[Pc];
        }
    }
    if (L[Pr].last) L[L[Pr].last].next=L[Pr].next;
    if (L[Pr].next) L[L[Pr].next].last=L[Pr].last;
}
int Find(int x)
{
    int l=1,r=n,mid;
    while (l<r-1)
    {
        mid=(l+r)>>1;
        if (R[mid].Val<x) l=mid;
        else r=mid;
    }
    for (int i=l;i<=r;i++)
        if (R[i].Val==x) return i;
}
void Double_Inc(int Ps)
{
    T[Ps].S[0]=T[T[Ps].S_A].S_B;
    T[Ps].CA[0]=T[Ps].C_A;
    T[Ps].CB[0]=T[T[Ps].S_A].C_B;
    for (int i=1;i<18;i++)
    {
        T[Ps].S[i]=T[T[Ps].S[i-1]].S[i-1];
        T[Ps].CA[i]=T[Ps].CA[i-1]+T[T[Ps].S[i-1]].CA[i-1];
        T[Ps].CB[i]=T[Ps].CB[i-1]+T[T[Ps].S[i-1]].CB[i-1];
    }
}
pair<int,int> Get_Ans(int P,int x)
{
    int D_A=0,D_B=0;
    int V=17;
    while (true)
    {
        while ((T[P].S[V]==0 || T[P].CA[V]+T[P].CB[V]>x) && V>=0) V--;
        if (V>=0) D_A+=T[P].CA[V],D_B+=T[P].CB[V],x-=T[P].CA[V]+T[P].CB[V],P=T[P].S[V];
        else break;
    }
    if (T[P].S_A && T[P].C_A<=x) D_A+=T[P].C_A;
    return pair<int,int>(D_A,D_B);
}
inline double Calc(int A,int B)
{
    if (B==0) return 1000000000.0;
    return (double)A/B;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",H+i),R[i].Val=H[i],R[i].ord=i;
    sort(R+1,R+n+1,Cmp);
    for (int i=1;i<=n;i++) L[i].Val=R[i].ord;
    for (int i=1;i<n;i++) L[i].next=i+1;
    for (int i=2;i<=n;i++) L[i].last=i-1;
    for (int i=1;i<=n;i++) Build(i,Find(H[i]));
    for (int i=n;i;i--) Double_Inc(i);
    int X0;
    scanf("%d",&X0);
    int ans;
    double Cur=10000000000.0;
    for (int i=n;i;i--)
    {
        pair<int,int> T=Get_Ans(R[i].ord,X0);
        if (Calc(T.first,T.second)<Cur-1e-8) ans=R[i].ord,Cur=Calc(T.first,T.second);
    }
    printf("%d\n",ans);
    int m;
    scanf("%d",&m);
    for (int i=1,p,x;i<=m;i++)
    {
        scanf("%d%d",&p,&x);
        pair<int,int> T=Get_Ans(p,x);
        printf("%d %d\n",T.first,T.second);
    }
    return 0;
}