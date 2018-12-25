/*
很明显这题就是一个乘法原理，我们求出每位上有可能的数字情况，
然后所有情况数相乘即为最终答案
我们可以考虑用Floyd的有向图的传递闭包
因为如果a可以转成b b可以转成c
那么a也可以转成c
注意这里数据过大一定要用高精度乘法
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=505;
int ans[MAXN];
bool map[12][12];
int b[12];
int k;
string a;
int x,y;
int l=1;

void work(int x)//高精度乘法
{
	for(int i=0;i<l;i++)
		ans[i]*=x;
	for(int i=0;i<l;i++)
		if(ans[i]>=10)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
			l=max(l,i+2);
		}
}

int main()
{
	cin>>a;
	cin>>k;
	for(int i=1;i<=k;i++)//先建图
	{
		cin>>x>>y;
		map[x][y]=1;
	}
	for(int i=0;i<=9;i++)//自己到自己为1
		map[i][i]=1;
	for(int k=0;k<=9;k++)//Floyd求出所有能转换的关系
		for(int i=0;i<=9;i++)
			for(int j=1;j<=9;j++)
			if(map[i][k]&&map[k][j])
				map[i][j]=1;
	for(int i=0;i<=9;i++)//求出每个数字可以转换成多少个数字(注意包括自己)
	{
		int tot=0;
		for(int j=0;j<=9;j++)
			if(map[i][j])
				tot++;
		b[i]=tot;
	}
	ans[0]=1;//高精度初始化1
	for(int i=0;i<a.length();i++)
		work(b[a[i]-'0']);//乘法原理
	for(int i=l-1;i>=0;i--)
		cout<<ans[i];
	return 0;
}
     