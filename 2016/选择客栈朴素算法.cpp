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
	int color,v;
}a[20000];
int n,m,cost;

int main()
{
	int ans=0;
	cin>>n>>m>>cost;
	for(int i=1;i<=n;i++)
		cin>>a[i].color>>a[i].v;
	for(int i=1;i<n;i++)
	{
		int m=a[i].v;
		for(int j=i+1;j<=n;j++)
		{
			m=min(m,a[j].v);
			if(a[i].color==a[j].color&&m<=cost)
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
     