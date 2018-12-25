#include<iostream>
#include<algorithm>
using namespace std;

int s,n;
int a[1000];
int d[1000];
int b[1000];

int dp(int s)
{
	if(d[s]!=-1)
		return d[s];
	
	d[s]=-(1<<30);
	for(int i=1;i<=n;i++)
		if(s>=a[i])
		d[s]=max(d[s],dp(s-a[i])+1);
		return d[s];	
}

int main()
{

	memset(d,-1,sizeof(d));
		d[0]=0;
	cin>>s>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp(s);
	
	cout<<d[s];
	return 0;
}