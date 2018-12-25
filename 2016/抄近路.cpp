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
}a[1002];
int f[1002];

int cmp(node a,node b)
{
	return a.x<b.x;
}

int main()
{
	memset(f,0,sizeof(f));
	int x,y;
	int n;
	int Max=-222;
	cin>>x>>y;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			if(a[j].y<a[i].y)
				f[i]=max(f[i],f[j]+1);
			Max=max(f[i],Max);
	}
	cout<<Max<<endl;
	return 0;
}
     