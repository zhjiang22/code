#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	while(cin>>n&&n)
	{
		long long int ans=0,a,last=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			ans+=abs(last);
			last+=a;
		}
		cout<<ans<<endl;
	}
	return 0;
}
