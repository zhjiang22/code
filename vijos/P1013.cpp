/*
嗯一道计算几何+最短路
其实题目不难的
唯一的难度就是判断两点能否直接到达
即两点连线上是否有别的墙挡住
这个据说是可以用叉积很快的
但是如果用相似三角形比例
也是可以写出来的
然后我们对于每堵墙两个洞即四个点
我们可以判断能否在一条直线上中间无障碍物
如果可以就是他们的欧几里得距离
如果不可以就设为INF
建立邻接矩阵
然后随便跑个最短路就好了
还是FLoyd最方便最快捷
Orz主要还是最好写2333333333
然后判断是否能连线
我这种弱弱真的懒得写啊
就随便复制了个叉积的然后改了一下用进来了
千万别学我Orz
嗯就这样水过去吧
黑书上计算几何有这种题目
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100;
const double INF=999.0;
struct node
{
    double x,y;
}p[MAXN];
int n,K;
double d[MAXN][MAXN];

double inline ojld(int i,int j)
{
    return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)
               +(p[i].y-p[j].y)*(p[i].y-p[j].y));
}

double det(double x1,double y1,double x2,double y2)//行列式
{
return x1*y2-x2*y1;
}
double cross(node p0,node p1,node p2)//叉积
{
double ans = det(p1.x-p0.x,p1.y-p0.y,p2.x-p0.x,p2.y-p0.y);
return ans;
}
bool check(int a,int b)//判断能否连通
{
if(p[a].x == p[b].x) return false;
for(int i = a+1;i < b;i++)
   {
   if(p[i].x == p[a].x || p[i].x == p[b].x) continue;
   node temp;
   if(i%4==1)
     {
     temp.x = p[i].x,temp.y = 10;
     if(cross(p[a],p[b],temp)*cross(p[a],p[b],p[i]) < 0 && cross(temp,p[i],p[a])*cross(temp,p[i],p[b]) < 0)
       return false;
     }
   if(i%4==0)
     {
     temp.x = p[i].x,temp.y = 0;
     if(cross(p[a],p[b],temp)*cross(p[a],p[b],p[i]) < 0 && cross(temp,p[i],p[a])*cross(temp,p[i],p[b]) < 0)
       return false;
     }
   if(i%4==2)
     {
     temp.x = p[i+1].x,temp.y = p[i+1].y;
     if(cross(p[a],p[b],temp)*cross(p[a],p[b],p[i]) < 0 && cross(temp,p[i],p[a])*cross(temp,p[i],p[b]) < 0)
       return false;
     }
   }
return true;
}

void init()
{
    double x;
    cin>>n;
    K=4*n+1;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        p[i*4+1].x=p[i*4+2].x=p[i*4+3].x=p[i*4+4].x=x;
        cin>>p[i*4+4].y>>p[i*4+3].y>>p[i*4+2].y>>p[i*4+1].y;
    }
    p[0].x=0,p[0].y=5;
    p[K].x=10,p[K].y=5;
    for(int i=0;i<=K;i++)
        for(int j=0;j<=K;j++)
            d[i][j]=INF;
}

void getd()
{
    for(int i=0;i<=K;i++)
        for(int j=i+1;j<=K;j++)
            if(check(i,j))
                d[i][j]=ojld(i,j);
}

void Floyd()
{
    for(int k=0;k<=K;k++)
        for(int i=0;i<=K;i++)
            for(int j=0;j<=K;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    printf("%.2lf\n",d[0][K]);
}

int main()
{
    init();
    getd();
    Floyd();
    return 0;
}
     