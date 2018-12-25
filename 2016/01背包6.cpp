#include<iostream>
#include <cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int V;
int f[100];
int n;

int main()
{
	freopen("D:\\in.txt","r",stdin);
	freopen("D:\\out.txt","w",stdout);
	int v,w;
	cin>>n;
	cin>>V;
	memset(f,0,sizeof(f));	
	for(int i=1;i<=n;i++)
	{
		cin>>v>>w;
		for(int j=V;j>=v;j--)
			f[j]=max(f[j],f[j-v]+w);
	}
		cout<<f[V];
	return 0;
}