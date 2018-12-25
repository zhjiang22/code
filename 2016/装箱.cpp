#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[40];
int V,n;
int f[20010];

int main()
{
	cin>>V>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		memset(f,0,sizeof(a));
		
		for(int i=1;i<=n;i++)
			for(int j=V;j>=a[i];j--)
			f[j]=max(f[j],f[j-a[i]]+a[i]);
			cout<<V-f[V];
			return 0;
}