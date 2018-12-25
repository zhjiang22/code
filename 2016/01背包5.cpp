#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int V;
int f[100][100];
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
		for(int j=0;j<=V;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=v)		f[i][j]=max(f[i][j],f[i-1][j-v]+w);
		}
	}
		cout<<f[n][V];
	return 0;
}