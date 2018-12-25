#include<iostream>
using namespace std;
string a;
int k;
int n;

void powder()
{
	while(k--)
	{
		int i=0;
		while(i<n&&a[i]<a[i+1])
		i++;
		for(int j=i+1;j<n;j++)
		a[j-1]=a[j];	
	}
}

void out()
{
	for(int i=0;i<n-k;i++)
	cout<<a[i];
}

int main()
{
	cin>>a>>k;
	n=a.length();
	powder();
	out();
	return 0;	
}