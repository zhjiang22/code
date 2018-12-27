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
	int x,y,w;
}a[2505];
int f[2505];
int n;

int cmp(node a,node b)
{
	return a.w<b.w;
}

int main()
{
	memset(f,0,sizeof(f));
	int l=1;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[l].w,a[l].x=i,a[l++].y=j;
	sort(a+1,a+n*n+1,cmp);
	for(int i=1;i<=n*n;i++)
		for(int j=1;j<i;j++)
		{
			int p=(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y))*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
			f[i]=max(f[i],f[j]+p);
		}
	cout<<f[n*n]<<endl;
	return 0;
}
     