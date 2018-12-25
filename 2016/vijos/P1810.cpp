/*
普及组的贪心题啊	好弱啊窝
我们可以直接按照到第一个拦截系统坐标的距离从小到大排序
因为如果我们是距离的话
会有根号精度又不好弄了
我们干脆就保存下距离的平方
因为我们要求的使用价值也是距离的平方
正好可以直接使用
我们按s1从小到大排了序之后
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100005;
struct node
{
	int s1,s2;
}a[MAXN];
int n;
int xx,yy,x2,y2;
int x,y;
int ans=0x7fffff;

bool inline cmp(node a,node b)
{
	return a.s1<b.s1;
}

int main()
{
	scanf("%d%d%d%d",&xx,&yy,&x2,&y2);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		a[i].s1=(x-xx)*(x-xx)+(y-yy)*(y-yy);
		a[i].s2=(x-x2)*(x-x2)+(y-y2)*(y-y2);
	}
	sort(a+1,a+n+1,cmp);
	int cur=0;
	for(int i=n;i>=1;i--)
	{
		cur=max(a[i+1].s2,cur);
		ans=min(ans,a[i].s1+cur);
	}
	cout<<ans<<endl;
	return 0;
}
     