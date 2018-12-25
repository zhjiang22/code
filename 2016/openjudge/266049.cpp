#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[5]={0,10,20,50,100};
int f[MAXN];
int n;

int main()
{
	cin>>n;
	if(n==0)
		cout<<0<<endl;
	else
	{
		f[0]=1;
		for(int i=1;i<=4;i++)
			for(int j=a[i];j<=n;j++)
				f[j]+=f[j-a[i]];
	}
	cout<<f[n]<<endl;
	return 0;
}
     