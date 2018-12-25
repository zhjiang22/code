#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int INF=0x7fffff;
int d[2002];
int v[2002];
int a[2002][2002];
int n;

int main()
{
	cin>>n;
	int x,y,w;
	memset(a,0,sizeof(a));
	while(cin>>x>>y>>w)
	{
		if(x==0&&y==0&&w==0)
			break;
		a[x][y]=w;
	}
	int s=1;
	v[1]=1;
	for(int i=1;i<=n;i++)
		d[i]=a[s][i];	
	for(int i=1;i<=n;i++)
	{
		int MAX=0;
		for(int j=1;j<=n;j++)
			if(!v[j]&&a[1][i])
			{
				if(a[i][j]+d[i]>d[j])
					d[j]=a[i][j]+d[i];
			}
	} 
	for(int i=1;i<=n;i++)
		cout<<d[i]<<" ";
	cout<<endl;
	return 0;
}
     