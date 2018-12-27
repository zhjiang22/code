/*
OrzNOIP2014Day2第一题必水啊23333
原谅我比较懒
我一开始打的都是int(long long要多打好多啊)
然后就直接用sublime的功能一键改了long long
再直接改一下主函数返回值类型就好咯QAQ
然后看到一个图，就129*129而已
一共也就这么几个点	我们直接枚举所有点就好了
但是有点害怕会超时啊
记录有可能有公共场所的点横纵坐标的最小最大四个极值
就像一个区域框了起来
然后就直接从这些极值范围枚举就好了
快的要死
但一定要记得
在扩展坐标查找公共场所的时候
一定要判断是否i<0||j<0||i>128||j>128
不然数组就越界访问了
然后你就gg了
嗯看一下代码就好了
很简单不难想到注意细节就好
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const long long Maxn=132;
const long long INF=9999999999999999;
long long a[Maxn][Maxn];
long long n;
long long d;
long long maxx,maxy,minx,miny;
long long ans=-INF;
long long tot;

void init()
{
	cin>>d>>n;
	long long x,y,w;
	for(long long i=1;i<=n;i++)
	{
		cin>>x>>y>>w;
		maxx=max(maxx,x+d);
		maxy=max(maxy,y+d);
		minx=min(minx,x-d);
		miny=min(miny,y-d);
		a[x][y]=w;
	}	
}

long long solve(long long x,long long y)
{
	long long sum=0;
	for(long long i=x-d;i<=x+d;i++)
		for(long long j=y-d;j<=y+d;j++)
			{
				if(i<0||j<0||i>128||j>128)
					continue;
				sum+=a[i][j];
			}
	return sum;
}

int main()
{
	init();
	for(long long i=minx-d;i<=maxx+d;i++)
		for(long long j=minx-d;j<=maxy+d;j++)
		{	
			if(i<0||j<0||i>128||j>128)
				continue;
			long long k=solve(i,j);
			if(k>ans)
				ans=k,tot=1;
			else	if(k==ans)
				tot++;
		}
	cout<<tot<<" "<<ans<<endl;
	return 0;
}
     