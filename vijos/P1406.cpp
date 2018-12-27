/*
考虑到两种做法 记忆化搜索或者Floyd
最短路算法 
由于数据太小了 可以用邻接矩阵 我们不妨给每一个点一个编号cnt 
那么f[i][j]表示cnt为I和cnt为j的点之间的最路径是多少 
如果两个点挨着 
那么就f[i][j]=0 
否则 f[i][j]=1; 
对于那些并不能联通的点 f[i][j]=inf; 
所以下一步你们就放心大胆的跑floyd就行了 
建图是N方的 
对每个点的处理是接近线性的 
所以合起来也就是一个N立方的复杂度 
重要的是建图 
建完图之后你跑什么都行。。。什么spfa dij Floyd 随意了 
但是还是floyd是比较简单的
这里还有一个优化 
我们可以设置一个终极起点 到第一排的每个点的距离为0其余为inf 
同理也可以设置一个终极终点。。。。。 

记忆化做法会更加简单一些，可以避免建图的麻烦
我写的记忆化的方法更加简单(其实也不算记忆化吧，爆搜，但是有博客这样写啊2333)
下面附上了别人写的Floyd做法
其实原理都差不多了，但是这个搜索会更快一点~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int INF=0x7ffffff;
const int MAXN=23;
int f[MAXN][MAXN];
int n,m;
char a[MAXN][MAXN];
int ans=INF;
int z[4][4]={{1,0},{-1,0},{0,-1},{0,1}};

void search(int x,int y)
{
	for(int i=0;i<=4;i++)
		{
			int newx=x+z[i][0];int newy=y+z[i][1];
			if(newx<1||newx>n||newy<1||newy>m)
				return;
			int v;
			if(a[x][y]==a[newx][newy])
				v=f[x][y];
			else
				v=f[x][y]+1;
			if(f[newx][newy]>v)//剪枝，如果当前都不是最优解，则没有必要继续向下找
			{				   //因为不可能再更新更优解
				f[newx][newy]=v;
				search(newx,newy);
			}
		/*if (newx==n)
			ans=min(ans,f[newx][newy]);*/
		//这样找只有60分是错的，要遍历一遍数组
		}
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int j=1;j<=m;j++)
		f[1][j]=1;	
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=INF;
	for(int j=1;j<=m;j++)
		search(1,j);
	for(int j=1;j<=m;j++)
		ans=min(ans,f[n][j]);
	cout<<ans<<endl;
	return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 400+5
int map[N][N],n,m;
char str[N][N];
void check(int i,int j,int cnt)
{
    if (str[i][j]==str[i][j+1]&&j+1<=m)
        map[cnt][cnt+1]=map[cnt+1][cnt]=0;
    else if(str[i][j]!=str[i][j+1]&&j+1<=m)
        map[cnt][cnt+1]=map[cnt+1][cnt]=1;
    if (str[i][j]==str[i][j-1]&&j-1>0)
        map[cnt][cnt-1]=map[cnt-1][cnt]=0;
    else if(str[i][j]!=str[i][j-1]&&j-1>0)
        map[cnt][cnt-1]=map[cnt-1][cnt]=1;
    if (str[i][j]==str[i-1][j]&&i-1> 0&&cnt-m>0)
        map[cnt][cnt-m]=map[cnt-m][cnt]=0;
    else if(str[i][j]!=str[i-1][j]&& i-1>0 && cnt-m>0)
        map[cnt][cnt-m]=map[cnt-m][cnt]=1;
    if (str[i][j]==str[i+1][j]&&i+1<=n)
        map[cnt][cnt+m]=map[cnt+m][cnt]=0;
    else if(str[i][j]!=str[i+1][j]&&i+1<=n)
        map[cnt][cnt+m]=map[cnt+m][cnt]=1;
}
int main()
{

    cin>>n>>m;
    int cnt=0;
    memset(map,0x3f,sizeof map);
    for(int i=1;i<=n;++i)
        scanf("%s",str[i]+1);   
    for(int i=1;i<=m;++i)//避免枚举起点
        map[cnt][i]=0;
    int end=n*m+1;
    for(int i=(n-1)*(m)+1;i<=n*m;++i)//避免枚举终点
        map[i][end]=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            check(i,j,++cnt);
    for(int k=0;k<=cnt+1;++k)
        for(int i=0;i<=cnt+1;++i)
            for(int j=0;j<=cnt+1;++j)
                map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
    cout<<map[0][end]+1;//0就是入口，0到第一个位置需要打一次没有算上，所以+1
} 
*/
