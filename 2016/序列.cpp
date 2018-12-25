#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

struct node
{
	int x,y,z;	
}a[1002];
int n;

int cmp(node q,node p)
{
	return q.y<p.y;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
	{	
		ans+=a[i].z;
		for(int j=1;j<=n;j++)
		{
			if(a[i].y<a[j].x)
				continue;
			else if(a[i].y-a[j].x+1>=a[j].z)
				a[j].z=0;
			else
				a[j].z-=(a[i].y-a[j].x+1);
		}

	}
	cout<<ans<<endl;
	return 0;
}