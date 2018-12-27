/*
简单贪心即可
对于所有的区间按右端点从小到大排序，然后先判断是否覆盖了足够多的数
如果还未覆盖到两个数，那么我们就从右往左扫描(即是先考虑选择右端点的数)，
此贪心策略同区间选点覆盖问题，容易证明
直到选择该区间选择到了两个数为止
则继续考虑下一个区间
嗯就这么简单
														Powder
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct node
{
	int x,y;
}a[10005];
bool used[10005];
int n;
int ans;

int cmp(node a,node b)
{
	return a.y<b.y;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int j=a[i].x;j<=a[i].y;j++)
			if(used[j])
				k++;
		for(int j=a[i].y;j>=a[i].x&&k<2;j--)
			if(!used[j])
			{
				used[j]=1;
				k++;
				ans++;
			}
	}
	cout<<ans<<endl;
	return 0;
}
     