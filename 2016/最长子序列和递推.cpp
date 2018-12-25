#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[50001];
long long d[50001];
int n;


int main()
{
	
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	memset(d,-1,sizeof(d));
	d[1]=a[1];
	for(int i=2;i<=n;i++)
	d[i]=max(d[i-1],(long long )0)+a[i];
	long long MAX=-111;
	for(int i=1;i<=n;i++)
	MAX=max(MAX,d[i]);
	cout<<MAX;
	return 0;
}