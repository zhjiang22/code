/*
再经典不过的并查集了
很简单不想多说
只想提到的是
这个pa数组有很多种初始化
初学可以pa[i]=i
到了后面熟练一点用pa[i]=0来就更方便一些了
*/
#include <iostream>
using namespace std;

int pa[20005];
int n,m;

int Getfather(int x)
{
	return pa[x]==x?x:pa[x]=Getfather(pa[x]);	
}

void init()
{
	for(int i=1;i<=n;i++)
	pa[i]=i;
}

void Union(int x,int y)
{
	pa[Getfather(x)]=Getfather(y);
}

int main()
{
	cin>>n>>m;
	int k;
	cin>>k;
	init();
	
	for(int i=1;i<=m;i++)
	{
		int x1,x2;
		cin>>x1>>x2;
		Union(x1,x2);
	}
	
	for(int i=1;i<=k;i++)
	{
		int y1,y2;
		cin>>y1>>y2;
		if(Getfather(y1)==Getfather(y2))
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
} 