#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int f[MAXN][MAXN>>1];
int n,V,R;
int ans,ansk;

int main()
{
	int v,r;
	cin>>V>>R>>n;
	ansk=R;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>r;
		for(int j=V;j>=v;j--)
			for(int k=R;k>=r;k--)
			{
				f[j][k]=max(f[j][k],f[j-v][k-r]+1);
				ans=max(ans,f[j][k]);
			}
	}
	for(int j=R;j>=0;j--)
		for(int i=V;i>=0;i--)
			if(f[i][j]==ans)
			{
				ansk=j;
				break;
			}
	cout<<ans<<" "<<R-ansk<<endl;
	return 0;
}
     