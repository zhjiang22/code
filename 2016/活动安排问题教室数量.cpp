#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct node
{
	int x;
	int v;
}a[20005];
int n,m;
int k,ans;

int cmp(node a,node b)
{
	return a.x<b.x;
}

int main()
{
	int ans=-1;
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{	
		cin>>a[i].x;
        a[i].v=(i%2)?1:-1;
	}
	sort(a+1,a+2*n+1,cmp);
	for(int i=1;i<=2*n;i++)
	{
		k+=a[i].v;
		ans=max(ans,k);
	}
	cout<<ans<<endl;
	system("pause");
	return 0;
}
     