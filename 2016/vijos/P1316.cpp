/*
很多年前做的水题23333，直接排序+判重
*/
#include <iostream>
#include <algorithm>
using namespace std;

int a[100];
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int t=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1])
			t++;
	cout<<t<<endl;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1])
			cout<<a[i]<<" ";
	return 0;
}