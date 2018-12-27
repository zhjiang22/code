#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int k;
double ans;

int main()
{
	cin>>k;
	int i=0;
	while(ans<=k)
	{
		i++;
		ans+=1.0/double(i);
	}
	cout<<i<<endl;
	return 0;
}
     