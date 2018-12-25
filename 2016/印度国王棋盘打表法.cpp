#include<iostream>
using namespace std;
unsigned long long a[101];

int main()
{
	unsigned long long sum=0;
	a[1]=1;
	for(int i=2;i<=100;i++)
		a[i]=(a[i-1]*2);
	int n,m;
	cin>>n>>m;
	for(int i=n;i<=m;i++)
		sum+=a[i];
	if(sum>=100000)
	{
	int x=sum%1000;
	while(sum>=1000)
	sum/=10;
	cout<<sum<<" "<<x;
	}
	else cout<<sum;
	return 0;
} 