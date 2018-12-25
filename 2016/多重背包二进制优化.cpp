#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int f[201];
int w[201];
int v[201];
int V,n,cur=1;

int main()
{
	int w1,v1,num;
	cin>>V>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v1>>w1>>num;
		for(int j=1;j<=num;j<<=1)
		{
			w[cur]=j*w1;
			v[cur++]=j*v1;
			num-=j;
		}
		if(num>0)
		{
			w[cur]=w1*num;
			v[cur++]=v1*num;
		}
	}
	for(int i=1;i<cur;i++)
		for(int j=V;j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+w[i]);
	cout<<f[V]<<endl;
	system("pause");
	return 0;
}
     