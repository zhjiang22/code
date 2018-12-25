/*
果然数据太弱了啊
OTZ
直接Floyd暴力做就好
我们先读入一个文化关系和一个图
考虑到n不大	直接用邻接矩阵存图就好了
然后我们就可以根据文化关系
枚举每对点	判断他们的关系是否排斥
如果排斥就把距离设为INF(注意这里d初始化INF)
即排斥关系的话虽然有路(读入图改了距离)
但是也会被重新弄成INF
然后我们就直接一个裸的Floyd就好了
一开始把关系判断写反了
结果第二个样例过不了是-1
然后试着一交结果AC了
感觉不对啊	然后找了半天
发现那个关系判断的地方写反了应该是j在前面
即1排斥2 2不一定排斥1	所以我们如果c[j]排斥c[i]
那么i到j才是INF
不能弄反了
结果这样都能AC
Orz太弱了这个数据我给跪啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
const int INF=0x7fffff;
int a[MAXN][MAXN];
int c[MAXN];
int n,m,k,s,t;
int d[MAXN][MAXN];

void init()
{
	cin>>n>>k>>m>>s>>t;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=INF;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		d[x][y]=d[y][x]=w;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[c[j]][c[i]])//注意这个顺序
				d[i][j]=INF;
}

void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	if(d[s][t]!=INF)
		cout<<d[s][t]<<endl;
	else
		cout<<-1<<endl;
}

int main()
{
	init();
	Floyd();
	return 0;
}
     
