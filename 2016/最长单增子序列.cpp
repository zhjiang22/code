#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=0x7fff;

int a[50002];
int f[50002];
int n;

int main()
{
	int ans=-INF;
	freopen("D:\\in.txt","r",stdin);
	freopen("D:\\out.txt","w",stdout);
	cin>>n;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[0]=-INF;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
			if(a[i]>a[j])
				f[i]=max(f[i],f[j]+1);
			ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}	