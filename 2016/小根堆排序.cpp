#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAXN=500003;
int a[MAXN];
int n;

void make(int i,int m)
{
	while(i*2<=m)
	{
		i*=2;
		if(i+1<=m&&a[i+1]>a[i])
			i++;
		if(a[i]>a[i/2])
		{
			swap(a[i],a[i/2]);
		}
		else break;
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=(n/2);i>=1;i--)
		make(i,n);
	for(int i=n;i>=2;i--)
		swap(a[i],a[1]),make(1,i-1);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
     