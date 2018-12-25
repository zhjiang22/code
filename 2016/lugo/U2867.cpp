#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int x;
double s;
double ans;

int main()
{
	cin>>s>>x;
	x*=5;
	for(int i=1;i<=x;i++)
	{
		ans+=s;
		s*=1.2;
	}
	printf("%.2lf\n",ans);
	return 0;
}
     