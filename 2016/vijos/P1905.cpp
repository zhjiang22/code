/*
签到题啊
随便模拟一下就好了
我是为了保险直接用了建游戏结果图的方法了
这里是为了直观有些边的值为0本来可以不用写
但作为处女座的喔还是写了
注意输入一定要从0开始输入循环方式
不然%不能得到循环的效果Orz
就这样吧233333
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXN=205;
int a[MAXN];
int b[MAXN];
int n,nA,nB;
int x,y;
int g[5][5];

void init()
{
	cin>>n>>nA>>nB;
	for(int i=0;i<nA;i++)
		cin>>a[i];
	for(int j=0;j<nB;j++)
		cin>>b[j];
}

void getg()
{
	g[0][1]=0;	g[0][2]=1;	g[0][3]=1;	g[0][4]=0;
	g[1][0]=1;	g[2][0]=0;	g[3][0]=0;	g[4][0]=1;

	g[1][2]=0;	g[1][3]=1;	g[1][4]=0;
	g[2][1]=1;	g[3][1]=0;	g[4][1]=1;

	g[2][3]=0;	g[2][4]=1;
	g[3][2]=1;	g[4][2]=0;

	g[3][4]=1;	g[4][3]=0;
}

int main()
{
	init();
	getg();
	for(int i=0;i<n;i++)
	{
		int nowa=a[i%nA];
		int nowb=b[i%nB];
		x+=g[nowa][nowb];
		y+=g[nowb][nowa];
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
