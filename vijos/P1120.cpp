/*
直接简单贪心+模拟即可
记录下所有有花生的地方，然后按花生数从大到小排序
因为题目要求了要先摘多的才能再摘小的
所以就可以直接贪心选择最大的也是就排序后数组中从前到后考虑
对于每个点判断一下:
当前已耗时+采摘时间1+走过去的时间+回到路边的时间 是否满足时间限制
如果满足就采摘 并更新当前坐标的位置
不然退出循环输出结果
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct node
{
	int x,y,v;
	bool operator < (const node& x) const
	{
		return v>x.v;
	}
}a[450];
int n,m;
int t;
int k;
int ans;
int cost;
int nowx,nowy;

int cail(int x)
{
	return abs(a[x].x-nowx)+abs(a[x].y-nowy);
}

int main()
{
	cin>>n>>m>>t;
	int v;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>v;
			if(v)
				a[++k]={i,j,v};
		}
	sort(a+1,a+k+1);
	nowy=a[1].y;
	for(int i=1;i<=k;i++)
	{
		if(cost+cail(i)+1+a[i].x<=t)
		{
			ans+=a[i].v;
			cost+=cail(i)+1;
			nowx=a[i].x,nowy=a[i].y;
		}
		else
			break;
	}
	cout<<ans<<endl;
	return 0;
}
     