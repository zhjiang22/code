#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int W,V;
int w[100],v[100];
int f[100][100];
int n;

int main()
{
	cin>>V;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>v[i]>>w[i];
	memset(f,0,sizeof(f));	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=V;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=v[i])		f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
		}
		cout<<f[n][V];
	return 0;
}