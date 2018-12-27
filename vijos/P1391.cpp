/*
各种大犇都是用的SPFA算法撸了两遍，窝就是这么6用Dijkstra算法做23333
Dijkstra算法变形，注意如何找当前需要的用来更新值的下家，并且如何更新；
初始化问题一定要注意，此题数据弱，若数据过大，
则应该用堆或者优先队列优化的Dijkstra算法来做
但是事实告诉我们这是一道水题23333orz
然而差点不能一遍过，还好多对拍了一会
此题亮点：
Dijkstra变形QWQ
													只会做水题的Powder
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF=0x7fffff;//QAQ好像这个INF并无任何很大卵用
int d[2002];
int v[2002];//标记是否到过
int a[2002][2002];
int n;

int main()
{
	cin>>n;
	int x,y,w;
	memset(a,0,sizeof(a));//a初始化应为0，即无法到达
	while(cin>>x>>y>>w)
	{
		if(x==0&&y==0&&w==0)
			break;
		a[x][y]=w;
	}
	int s=1;
	v[1]=1;
	for(int i=2;i<=n;i++)
		d[i]=a[s][i];
	for(int i=1;i<=n;i++)
	{
		int MAX=0;
		int num;
		for(int j=1;j<=n;j++)//每次找到所有未访问点中距离最大的值
			if(!v[j])		 //类似于最短路中最短边
			{
				if(d[j]>MAX)
					MAX=d[j],num=j;//更新并记录此值
			}
		v[num]=1;//加入集合中
		for(int j=1;j<=n;j++)//用此最大rp值去更新各个点的rp值
			if(!v[j])
				if(d[j]<min(d[num],a[num][j]))//必须要比d[num]小且比a[num][j]小才行
					d[j]=min(d[num],a[num][j]);//类似于d[num]+a[num][j]但是要注意只要取最小值就好惹
	} 
	for(int i=2;i<=n;i++)
		cout<<d[i]<<endl;
	return 0;
}
     