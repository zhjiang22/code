#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[50008],b[50008];

bool cmp(int a,int b)
{	
	return a>b;

}

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++)
		{
		cin>>a[i];
		b[i]=a[i];
		}
		int t=n;
		while(t>1)
		{
			sort(a,a+n);
			a[1]=a[0]*a[1]+1;
			a[0]=9999999;
			t--;
			
		}
		t=n;
		while(t>1)
		{
			sort(b,b+n,cmp);
			b[0]=b[0]*b[1]+1;
			b[1]=0;
			t--;
		}
		cout<<a[1]-b[0];
	}
	return 0;
}