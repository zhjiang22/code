#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[10002];
int s;
int n;
int ans;

int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int i=1,j=n;
	while(i<=j)
	{
		if(a[i]+a[j]<=s)
		{
			ans++;
			i++;
			j--;
		}
		else
		{
			ans++;
			j--;
		}
	}
	cout<<ans<<endl;
	system("pause");
	return 0;
}
     