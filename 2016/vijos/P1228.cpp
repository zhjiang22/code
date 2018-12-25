/*
Orz看到大神都写最小费用最大流
我这个弱弱就只能写个裸的KM算法了
我们看到要求最小匹配
我的思路是
把每条边权变成负的
那么我们求出的负的边权的最大完美匹配
取个相反数就是要求的答案咯
但是很坑啊要用浮点数来做
然后很傻逼地在dfs中
判断lx[x]+ly[i]==g[x][i]
直接写了个等于
结果直接TLE7个点WA一个点
然后很神奇地想了半天以为是O(n^4)太慢了
就写了个O(n^3)发现TLE8个点666
然后就想了一下不对啊最多40个点撑死不是这个原因啊
然后想了半天就想起来
这里浮点数判断相等不是作死吗？
然后一改
瞬间过了9个点
然后还是WA一个点
然后就调了数据一看
Orz但是是0
取个相反数前面输出-0.000
QAQ于是加了个特判就直接过了
Orz看来我还是太弱
这种水题都被坑了
哎我乃弱逼一枚
最后允许我吐槽一下样例
这样例给的非常好
给了和没给一样
我给满分
QWQ
直接秒过
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=45;
const double INF=999999;
struct node
{
	int x,y;
}a[MAXN];
int n;
double g[MAXN][MAXN];
double lx[MAXN],ly[MAXN],slack[MAXN];
int s[MAXN],t[MAXN];
int match[MAXN];
double ans;

double getd(int i,int j)
{
	return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

void init()
{
	scanf("%d",&n);
	n<<=1;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=2*n;j++)
			g[i][j]=-INF;
	for(int i=1;i<=n;i++)
		for(int j=n/2+1;j<=n;j++)
			g[i][j]=g[j][i]=-getd(i,j);
}

bool dfs(int x)
{
    s[x]=1;
    for(int i=1;i<=n;i++)
    {
        if((lx[x]+ly[i]-g[x][i])>=-1e-4&&(lx[x]+ly[i]-g[x][i])<=1e-4&&!t[i])
        {
            t[i]=1;
            if(!match[i]||dfs(match[i]))
            {
                match[i]=x;
                return true;
             }
        }
    }
    return false;
}

void update()
{
    double a=INF;
    for(int i=1;i<=n;i++)   if(s[i])
        for(int j=1;j<=n;j++)   if(!t[j])
            a=min(a,lx[i]+ly[j]-g[i][j]);
    for(int i=1;i<=n;i++)
    {
        if(s[i])    lx[i]-=a;
        if(t[i])    ly[i]+=a;
    }
}

void KM()
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(match,0,sizeof(match));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            lx[i]=max(lx[i],g[i][j]);
    for(int i=1;i<=n;i++)
        for(;;)
        {
            memset(s,0,sizeof(s));
            memset(t,0,sizeof(t));
            if(dfs(i))
                break;
            else
                update();
        }
    for(int i=1;i<=n;i++)
        ans+=g[i][match[i]];
    if(ans!=0)
    	ans=-ans;
    printf("%.3lf\n",(ans/2));
}


int main()
{
	init();
	KM();
	return 0;
}
     