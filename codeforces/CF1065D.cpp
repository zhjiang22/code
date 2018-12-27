#include <bits/stdc++.h>
using namespace std;

const int MAXN=12;
struct PK
{
    int x;
    int y;
    int nowd;
    int cur;
    int step;
    int changes;
    bool operator==(const PK& p)const
    {
        return x==p.x&&y==p.y&&nowd==p.nowd;
    }
};
struct Place
{
    int x,y;
}a[MAXN*MAXN];
bool inq[MAXN][MAXN][MAXN*MAXN][5];
int d[MAXN][MAXN][MAXN*MAXN][5];
int change[MAXN][MAXN][MAXN*MAXN][5];
int g[MAXN][MAXN];
int n;

void init()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
            a[g[i][j]].x=i;
            a[g[i][j]].y=j;
        }
    memset(d,0x3f,sizeof(d));
    memset(change,0x3f,sizeof(change));
}

PK s1,s2,s3;
queue<PK> q;

int cur1[8][2]={{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
int cur2[36][2]=
        {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},
        {-1,0},{-2,0},{-3,0},{-4,0},{-5,0},{-6,0},{-7,0},{-8,0},{-9,0},
        {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},
        {0,-1},{0,-2},{0,-3},{0,-4},{0,-5},{0,-6},{0,-7},{0,-8},{0,-9}};
int cur3[36][2]=
{{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9},
{-1,-1},{-2,-2},{-3,-3},{-4,-4},{-5,-5},{-6,-6},{-7,-7},{-8,-8},{-9,-9},
{-1,1},{-2,2},{-3,3},{-4,4},{-5,5},{-6,6},{-7,7},{-8,8},{-9,9},
{1,-1},{2,-2},{3,-3},{4,-4},{5,-5},{6,-6},{7,-7},{8,-8},{9,-9}};

inline bool valid(const int& x,const int& y)
{
    return x>=1&&x<=n&&y>=1&&y<=n;
}

void work()
{
    s1.x=s2.x=s3.x=a[1].x;  s1.y=s2.y=s3.y=a[1].y;
    s1.cur=1;   s2.cur=2;   s3.cur=3;
    s1.nowd=s2.nowd=s3.nowd=1;
    q.push(s1); q.push(s2); q.push(s3);
    inq[s1.x][s1.y][s1.nowd][s1.cur]=1;
    inq[s2.x][s2.y][s2.nowd][s2.cur]=1;
    inq[s3.x][s3.y][s3.nowd][s3.cur]=1;
    d[s1.x][s1.y][s1.nowd][s1.cur]=0;
    d[s2.x][s2.y][s2.nowd][s2.cur]=0;
    d[s3.x][s3.y][s3.nowd][s3.cur]=0;
    change[s1.x][s1.y][s1.nowd][s1.cur]=0;
    change[s2.x][s2.y][s2.nowd][s2.cur]=0;
    change[s3.x][s3.y][s3.nowd][s3.cur]=0;
    PK ed;
    ed.x=a[n*n].x;  ed.y=a[n*n].y;  ed.nowd=n*n;
    bool flag=0;
    int minchange=0x3fffff;
    int ans=0x3fffff;
    while(!q.empty())
    {
        PK now=q.front();   q.pop();
        if(flag&&(now.step>ans))
            break;
        if(now==ed)
        {
            flag=1;
            ans=now.step;
            minchange=min(minchange,change[now.x][now.y][now.nowd][now.cur]);
        }
        if(now.cur==1)
        {
            for(int i=0;i<8;i++)
            {
                int nx=now.x+cur1[i][0];
                int ny=now.y+cur1[i][1];
                if(valid(nx,ny)&&g[nx][ny]!=now.nowd+1&&(now.step+1<d[nx][ny][now.nowd][now.cur]||(now.step+1==d[nx][ny][now.nowd][now.cur]&&change[now.x][now.y][now.nowd][now.cur]<change[nx][ny][now.nowd][now.cur])))
                {
                    change[nx][ny][now.nowd][now.cur]=change[now.x][now.y][now.nowd][now.cur];
                    d[nx][ny][now.nowd][now.cur]=now.step+1;
                    if(!inq[nx][ny][now.nowd][now.cur])
                    {
                        q.push(PK{nx,ny,now.nowd,now.cur,now.step+1});
                        inq[nx][ny][now.nowd][now.cur]=1;
                    }
                }
                else    if(valid(nx,ny)&&g[nx][ny]==now.nowd+1&&(now.step+1<d[nx][ny][now.nowd+1][now.cur]||(now.step+1==d[nx][ny][now.nowd+1][now.cur]&&change[now.x][now.y][now.nowd][now.cur]<change[nx][ny][now.nowd+1][now.cur])))
                {
                    change[nx][ny][now.nowd+1][now.cur]=change[now.x][now.y][now.nowd][now.cur];
                    d[nx][ny][now.nowd+1][now.cur]=now.step+1;
                    if(!inq[nx][ny][now.nowd+1][now.cur])
                    {
                        q.push(PK{nx,ny,now.nowd+1,now.cur,now.step+1});
                        inq[nx][ny][now.nowd+1][now.cur]=1;
                    }
                }
            }
        }
        else    if(now.cur==2)
        {
            for(int i=35;i>=0;i--)
            {
                int nx=now.x+cur2[i][0];
                int ny=now.y+cur2[i][1];
                if(valid(nx,ny)&&g[nx][ny]!=now.nowd+1&&(now.step+1<d[nx][ny][now.nowd][now.cur]||(now.step+1==d[nx][ny][now.nowd][now.cur]&&change[now.x][now.y][now.nowd][now.cur]<change[nx][ny][now.nowd][now.cur])))
                {
                    change[nx][ny][now.nowd][now.cur]=change[now.x][now.y][now.nowd][now.cur];
                    d[nx][ny][now.nowd][now.cur]=now.step+1;
                    if(!inq[nx][ny][now.nowd][now.cur])
                    {
                        q.push(PK{nx,ny,now.nowd,now.cur,now.step+1});
                        inq[nx][ny][now.nowd][now.cur]=1;
                    }
                }
                else    if(valid(nx,ny)&&g[nx][ny]==now.nowd+1&&(now.step+1<d[nx][ny][now.nowd+1][now.cur]||(now.step+1==d[nx][ny][now.nowd+1][now.cur]&&change[now.x][now.y][now.nowd][now.cur]<change[nx][ny][now.nowd+1][now.cur])))
                {
                    change[nx][ny][now.nowd+1][now.cur]=change[now.x][now.y][now.nowd][now.cur];
                    d[nx][ny][now.nowd+1][now.cur]=now.step+1;
                    if(!inq[nx][ny][now.nowd+1][now.cur])
                    {
                        q.push(PK{nx,ny,now.nowd+1,now.cur,now.step+1});
                        inq[nx][ny][now.nowd+1][now.cur]=1;
                    }
                }
            }
        }    
        else    if(now.cur==3)
        {
            for(int i=35;i>=0;i--)
            {
                int nx=now.x+cur3[i][0];
                int ny=now.y+cur3[i][1];
                if(valid(nx,ny)&&g[nx][ny]!=now.nowd+1&&(now.step+1<d[nx][ny][now.nowd][now.cur]||(now.step+1==d[nx][ny][now.nowd][now.cur]&&change[now.x][now.y][now.nowd][now.cur]<change[nx][ny][now.nowd][now.cur])))
                {
                    change[nx][ny][now.nowd][now.cur]=change[now.x][now.y][now.nowd][now.cur];
                    d[nx][ny][now.nowd][now.cur]=now.step+1;
                    if(!inq[nx][ny][now.nowd][now.cur])
                    {
                        q.push(PK{nx,ny,now.nowd,now.cur,now.step+1});
                        inq[nx][ny][now.nowd][now.cur]=1;
                    }
                }
                else    if(valid(nx,ny)&&g[nx][ny]==now.nowd+1&&(now.step+1<d[nx][ny][now.nowd+1][now.cur]||(now.step+1==d[nx][ny][now.nowd+1][now.cur]&&change[now.x][now.y][now.nowd][now.cur]<change[nx][ny][now.nowd+1][now.cur])))
                {
                    change[nx][ny][now.nowd+1][now.cur]=change[now.x][now.y][now.nowd][now.cur];
                    d[nx][ny][now.nowd+1][now.cur]=now.step+1;
                    if(!inq[nx][ny][now.nowd+1][now.cur])
                    {
                        q.push(PK{nx,ny,now.nowd+1,now.cur,now.step+1});
                        inq[nx][ny][now.nowd+1][now.cur]=1;
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)
            if(now.cur!=i&&(now.step+1<d[now.x][now.y][now.nowd][i]||(now.step+1==d[now.x][now.y][now.nowd][i]&&change[now.x][now.y][now.nowd][now.cur]+1<change[now.x][now.y][now.nowd][i])))
            {
                change[now.x][now.y][now.nowd][i]=change[now.x][now.y][now.nowd][now.cur]+1;
                d[now.x][now.y][now.nowd][i]=now.step+1;
                if(!inq[now.x][now.y][now.nowd][i])
                {
                    q.push(PK{now.x,now.y,now.nowd,i,now.step+1});
                    inq[now.x][now.y][now.nowd][i]=1;
                }
            }
    }
    cout<<ans<<" "<<minchange<<endl;
}

int main()
{
    init();
    work();
    return 0;
}