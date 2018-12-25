/*
LIS问题，坐标递增关系递推即可，注意应排序，且排序后横纵坐标双重条件不能少
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct node
{
	int x,y;
}a[100002];
int n,m,k;
int f[100002];

int cmp(node a,node b)
{
	return a.x<b.x;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+k+1,cmp);//一定要排序~
	int ans=-9;
	for(int i=0;i<=k;i++)
		f[i]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
			if(a[i].x>a[j].x&&a[i].y>a[j].y)//双重条件不能少
				f[i]=max(f[j]+1,f[i]);
		ans=max(ans,f[i]);
	}
	
	cout<<int(100*(double(n+m-2*ans)+sqrt(2)*ans)+0.5)<<endl;
	return 0;
}
     