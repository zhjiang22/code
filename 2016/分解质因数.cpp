#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[20000];

int s(int n)
{
	for(int i=2;i<=n;i++)
		if(n%i==0)
			return i;
	return 0;
}

int main()
{
	freopen("E:\\in.txt","r",stdin);
	freopen("E:\\out.txt","w",stdout);
	memset(a,0,sizeof(a));
	int i=1;
	int n;
	cin>>n;
	int m=n;
	while(1)
	{
		int x=s(n);
			if(x!=0)
			a[i++]=x,n/=x;
		else break;
	}
	cout<<m<<"=";
	if(a[1])
		cout<<a[1];
	int j=2;
	while(j<i)
		cout<<"*"<<a[j++];
	return 0;
}