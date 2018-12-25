#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000];
int f[1000];

int main()
{
	int n=1;
	int m=0;
	int z=0;
	while(cin>>a[n++]);
	for(int i=1;i<n;i++)
	f[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
		if(a[i]<a[j])
		f[i]=max(f[i],f[j]+1);
	for(int i=1;i<=n;i++)
	m=max(m,f[i]);
	
	for(int i=1;i<=n;i++)
	f[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
		if(a[i]>a[j])
		f[i]=max(f[i],f[j]+1);
	for(int i=1;i<=n;i++)
	z=max(m,f[i]);
	cout<<z<<endl<<m;
	return 0;
}