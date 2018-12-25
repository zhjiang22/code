/*
很明显是裸的Kruskal
只是要判断一下最后答案是不是在s之内
并且有没有把所有点连通起来
因为我们用的是Kruskal算法
所以判断是否把所有点连通我们只需要
判断所有点是否在同一个集合中
即根节点是否都相同即可
注意精度问题
蛮基础的问题的	也没啥陷阱
练了练手
Claris说得对
都是套路啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100004;
struct node
{
	int x,y;
	double w;
	bool operator < (const node&b)const
	{
		return w<b.w;
	}
}a[MAXN];
int fa[MAXN];
int n;
int m;
double s;
double ans;

int getfather(int x)
{
	return fa[x]==x?x:fa[x]=getfather(fa[x]);
}

void inline Add_Edge(int x,int y,double w)
{
	m++;
	a[m].x=x;	a[m].y=y;	a[m].w=w;
}

void init()
{
	int x,y;
	double w;
	cin>>s>>n;
	while(scanf("%d%d%lf",&x,&y,&w)==3)
		Add_Edge(x,y,w);
	for(int i=1;i<=n;i++)
		fa[i]=i;
}

void Kruskal()
{
	int tot=0;
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
	{
		int fx=getfather(a[i].x);
		int fy=getfather(a[i].y);
		if(fx!=fy)
		{
			tot++;
			fa[fx]=fy;
			ans+=a[i].w;
			if(tot==n-1)
				break;
		}
	}
}

void out()
{
	int k=getfather(1);
	for(int i=2;i<=n;i++)
		if(getfather(i)!=k)
		{
			cout<<"Impossible"<<endl;
			return;
		}
	if(ans<=s)
		printf("Need %.2lf miles of cable\n",ans);
	else
		cout<<"Impossible"<<endl;
}

int main()
{
	init();
	Kruskal();
	out();
	return 0;
}
     