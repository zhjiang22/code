#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int n,V;
int w[20005];
int v[20005];
int f[50004];

int main()
{
	cin>>n>>V;
	int w1,v1,num;
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		cin>>v1>>w1>>num;
		for(int j=1;j<=num;j<<=1)
		{
			w[cur]=w1*j;
			v[cur++]=v1*j;
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
     