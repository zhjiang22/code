#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100000;
const int INF=0x7ffffff;
struct Edge
{
    int to,next,w;
    Edge()
    {
        to=next=-1;
        w=0;
    }
}e[MAXN<<1];
int fisrt[MAXN];
int d[MAXN];
int cnt[MAXN];
int q[MAXN];
bool in[MAXN];
int s,t;
int n,tot;
int front,rear;

inline void Add_Edge(int x,int y,int w)
{
    tot++;
    e[tot].to=y;    e[tot].w=w;
    e[tot].next=fisrt[x];   fisrt[x]=tot;
}

void init()
{
    memset(fisrt,-1,sizeof(fisrt));
    int x,y,w;
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>w;
        if(x<=t&&y>=s)
            Add_Edge(max(x,s),min(y,t)+1,w);
    }
    for(int i=s;i<=t+1;i++)
        Add_Edge(i,i-1,0);
    for(int i=s;i<=t+1;i++)
        d[i]=INF;
}

void SPFA(int s,int n)
{
    q[rear++]=s;
    in[s]=1;    d[s]=0;     cnt[s]=1;
    while(front!=rear)
    {
        int x=q[front++];   front%=(MAXN-1);
        in[x]=0;
        for(int i=fisrt[x];i!=-1;i=e[i].next)
        {
            int y=e[i].to;  int w=e[i].w;
            if(d[y]>d[x]+w)
            {
                d[y]=d[x]+w;
                if(!in[y])
                {
                    if(++cnt[y]>n)
                        return;
                    in[y]=1;
                    q[rear++]=y;    rear%=(MAXN-1);
                }
            }
        }
    }
}

int main()
{
    init();
    SPFA(s,t-s+2);
    if(d[t+1]!=INF)
        cout<<d[t+1]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
     