#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int V,n;
int f[5000];
int num,v,w;

int main()
{
	cin>>V>>n;
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>w>>num;
		for(int j=1;j<=num;j++)
			for(int k=V;k>=v;k--)
			{
				f[k]=max(f[k],f[k-v]+w);
				if(f[k]>ans)
					ans=f[k];
			}
	}
	cout<<ans<<endl;
	system("pause");
	return 0;
}
     