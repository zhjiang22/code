#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int a[102][102];
int n;
int x,y,w;

int main()
{
	cin>>n;
	memset(a,0x3f,sizeof(a));
	while(cin>>x>>y>>w)
		a[x][y]=a[y][x]=w;
	for(int i=1;i<=n;i++)
		f[i][i]=0;//此步不能少~~！！
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	int ans=0x7fffff;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int MAX=0;
			for(int k=1;k<=n;k++)
				MAX=max(MAX,min(a[i][k],a[j][k]));
			if(MAX<ans)
			{
				ans=MAX;
				x=i;
				y=j;
			}
		}
	cout<<x<<" "<<y<<endl;
	system("pause");
	return 0;
}
     