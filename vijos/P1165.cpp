/*
一道很明显的离散化啦
我们来看一下这道题的意思其实就是
对于n个可相交区间
问其中共有多少个元素
一个典型的裸体了叭
x,y可能达到10^9而数据其实最多只有20000个x,y
这样就会很明显想到离散化了
读入区间后对所有区间快排
以左端点为第一关键字	右端点为第二关键字
从小到大一排
再从1-n-1所有的区间
如果当前的某个区间
可以扩展连到下一个区间
即比如[2,8]和[6,10]
有相交部分
那么这段我们就可以不处理
转移叠加到下一段中去
就是a[i+1].x=a[i].x	a[i+1].y=max(a[i].y,a[i+1].y)
就把当前区间融入到下一个区间了
而当当前区间和下一个区间没有交集之时
这个区间就是一个最大的联合区间了
加上它的元素个数
这样的操作进行到n-1
这个时候第n个区间可能已经融合了某个区间
也可能没有融合
我们再将最后一个区间的长度加入即可
水题Orz
然而窝好弱
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=20005;
struct node
{
	int x,y;
}a[MAXN];
int n;
int ans;

inline bool cmp(node a,node b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
}

int main()
{
	init();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		if(a[i].y>=a[i+1].x)
		{
			a[i+1].x=a[i].x;
			a[i+1].y=max(a[i].y,a[i+1].y);
		}
		else
			ans+=a[i].y-a[i].x;
	}
	ans+=a[n].y-a[n].x;
	cout<<ans<<endl;
	return 0;
}
     