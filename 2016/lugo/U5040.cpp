#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=2005;
int s[MAXN];
int ax[MAXN*MAXN];
int n,x;
int la;
int ans;

void init()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(s[i]!=0)
				ax[++la]=s[i]*x-s[j];
	sort(ax+1,ax+la+1);
}

int ffind(int x)
{
	int l=1;	int r=la;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(ax[mid]==x)
			return mid;
		else	if(ax[mid]>x)
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(ffind(s[i]*s[j])!=-1)
				ans++;
		}
	cout<<ans<<endl;
	return 0;
}
     
