/*
模拟直接水过~
直接按照左端点从左到右排个序~
然后再判断合并总的区间和当前的区间的关系
然后选择进入下一个区间还是继续将该区间合并起来
很简单的~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=50005;
struct node
{
	int x,y;
	bool operator <(const node& b)const
	{
		return x<b.x;
	}
}a[MAXN];
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
}

int main()
{
	init();
	sort(a+1,a+n+1);
	node p=a[1];
	for(int i=2;i<=n;i++)
	{
		if(p.y<a[i].x)
		{
			cout<<p.x<<" "<<p.y<<endl;
			p=a[i];
		}
		else
			p.y=max(p.y,a[i].y);
	}
	cout<<p.x<<" "<<p.y<<endl;
	return 0;
}
     