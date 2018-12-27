/*
并查集拆点就好了
对于三条直线 l1,l2,l3，如果 l1//l2,l2//l3 则 l3//l1 
根据这个规则我们明显的可以感受到这是一个并查集的题目，
但是对于 l1⊥l3 不好弄，但是我们知道若 l1⊥l2,l2⊥l3 ,那么 l3//l1 ，
所以我们不妨设一个 l1′,l2′,l3′ ，当 l1 与 l2 在同一个集合时表示 l1//l2 ，
当 l1′ 与 l2 或 l2′ 与 l1在同一个集合中是表示 l1⊥l2. 
那这样可行吗?显然是可以的，应为对于 l1⊥l2 ,
那么 l1′ 与 l2,l2′ 与 l1 在同一个集合里，再加上 l2⊥l3 ,
那么 l2′ 与 l3,l3′ 与 l2 在同一个集合里，那么 l1,l2′,l3 都在同一个集合里，
也就有 l1//l3 ,同理也可以说明 l1//l2,l2⊥l3 时有 l1⊥l3 .
只有互相平行在一个集合和互相垂直在对立集合两种
直接就拆开就好
这种题目也做了几次了
统计平行方案就是统计所有的一对直线
在一个集合就加一个总数咯
然后查询就直接判断两者根节点是否在同一个集合
或者是否对立点和对方在同一个集合
或者都不是那就是不知道了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=205;
int n,m,q;
int fa[2*MAXN];
int ans;

int getfather(int x)
{
    return fa[x]==x?x:fa[x]=getfather(fa[x]);
}

int change(string x)
{
    int d=x.length();
    int ans=0;
    for(int i=1;i<d;i++)
        ans=ans*10+(x[i]-'0');
    return ans;
}

void Merge(int x,int y)
{
    int fx=getfather(x);
    int fy=getfather(y);
    if(fx!=fy)
        fa[fx]=fy;
}

void init()
{
    string a,b;
    int x,y;
    char ch;
    for(int i=1;i<=2*MAXN-1;i++)
        fa[i]=i;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>ch>>b;
        x=change(a);    y=change(b);
        if(ch=='p')
        {
            if(getfather(x)==getfather(y+MAXN))
            {
                cout<<"There must be something wrong..."<<endl;
                exit(0);
            }
            Merge(x,y);
            Merge(x+MAXN,y+MAXN);
        }
        else
        {
            if(getfather(x)==getfather(y))
            {
                cout<<"There must be something wrong..."<<endl;
                exit(0);
            }
            Merge(x+MAXN,y);
            Merge(x,y+MAXN);
        }
    }
}

void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            else    if(getfather(i)==getfather(j))
                ans++;
        }
    cout<<ans/2<<endl;
}

void answer()
{
    string a,b;
    int x,y;
    for(int i=1;i<=q;i++)
    {
        cin>>a>>b;
        x=change(a),y=change(b);
        if(getfather(x)==getfather(y))
            cout<<"Parallel."<<endl;
        else    if(getfather(x)==getfather(y+MAXN))
            cout<<"Vertical."<<endl;
        else
            cout<<"No idea"<<endl;
    }

}

int main()
{
    init();
    solve();
    answer();
    return 0;
}
     