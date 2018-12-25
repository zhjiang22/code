#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct node
{
	int x,y;
}a[102];
int n;
int x,y;

int cmp(node a,node b)
{
	return a.y<b.y;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[i].x=min(x,y);
		a[i].y=max(x,y);
	}
	sort(a+1,a+n+1,cmp);
	int cur=a[1].y;
	int ans=1;
	for(int i=2;i<=n;i++)
		if(a[i].x>=cur)
			ans++,cur=a[i].y;
	cout<<ans<<endl;
	system("pause");
	return 0;
}
     