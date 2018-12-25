#include<iostream>
using namespace std;

int n;
int a[50];
int ans;

int main()
{
	cin>>n;
	a[1]=1;	a[2]=2;	a[3]=3;
	for(int i=4;i<=n;i++)
	{
		a[i]=a[i-3]+a[i-2]+a[i-1];
	}
	cout<<a[n]<<endl;
	ans=1;
	for(int i=1;i<=n;i++)
		ans*=2;
	cout<<ans<<endl;
	return 0;
}