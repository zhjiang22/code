#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
const int MOD=1000000007;
int a[14]={0,1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
int f[MAXN];
int n;

int main()
{
	cin>>n;
	if(n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	f[0]=1;
	for(int i=1;i<=12;i++)
		for(int j=a[i];j<=n;j++)
			f[j]=(f[j]+f[j-a[i]])%MOD;
	cout<<f[n]<<endl;
	return 0;
}
     