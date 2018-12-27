#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[8];

int main()
{
	int x,y;
	for(int i=1;i<=7;i++)
	{
		cin>>x>>y;
		a[i]=x+y;
	}
	int ans=7;
	int p=0;
	for(int i=1;i<=7;i++)
		if(a[i]>ans)
			ans=a[i],p=i;
	if(p==0)
		cout<<0<<endl;
	else
		cout<<p<<endl;
	return 0;
}
     