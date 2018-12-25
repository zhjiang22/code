#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=505;
struct node
{
    int tpyed;
    int v,c;
}a[MAXN];
int n,MAXW;
int ans=-1,ans2,tot=1;

void init()
{
    char x[15];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",x);
        if(x[0]=='G')
        	a[i].tpyed=0;
        else	if(x[0]=='D')
        	a[i].tpyed=1;
        else	if(x[0]=='M')
        	a[i].tpyed=2;
        else
        	a[i].tpyed=3;
        scanf("%d%d",&a[i].v,&a[i].c);
    }
    cin>>MAXW;
}

void dfs(int cur,int p1,int p2,int p3,int p4,int v,int c,int maxv,int have)
//cur当前人,p1守门员,p2后卫,p3中锋,p4前锋,v价值,c花费,maxv最大价值
{
    if(cur==n+1)
    {
        if(p1+p2+p3+p4==11)
            if(c<MAXW)
                if(p1==1&&p2<=5&&p2>=3&&p3<=5&&p3>=2&&p4>=1&&p4<=3)
                {
                    if(v+maxv>ans||(v+maxv==ans&&c<ans2))
                    {
                        tot=1;
                        ans2=c;
                        ans=v+maxv;
                    }
                    else    if(v+maxv==ans&&c==ans2)
                    {
                        tot++;
                    }
                }
        return;
    }
    if(c>MAXW)
        return;
    if(p1>1||p2>5||p3>5||p4>3)
        return;
    if(p1+p2+p3+p4>11)
        return;
    if(have+(n-cur)<10)
        return;
    int x=0,y=0,z=0,o=0;
    if(a[cur].tpyed==0)
        x++;
    else    if(a[cur].tpyed==1)
        y++;
    else    if(a[cur].tpyed==2)
        z++;
    else    
        o++;
    dfs(cur+1,p1+x,p2+y,p3+z,p4+o,v+a[cur].v,c+a[cur].c,max(maxv,a[cur].v),have+1);
    dfs(cur+1,p1,p2,p3,p4,v,c,maxv,have);
} 

int main()
{
    init();
    dfs(1,0,0,0,0,0,0,0,0);
    cout<<ans<<" ";
    cout<<ans2<<" ";
    cout<<tot<<endl;
    return 0;
}