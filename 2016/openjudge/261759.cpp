#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int a[MAXN];
int f[MAXN];
int top;
int n;

int find(int x)
{
	int l=1,r=top;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(x>f[mid])
			l=mid+1;
		else
			r=mid-1;
	}
	return l;
}

int main()
{
	cin>>n;
	int x;
	f[top]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x>f[top])
			f[++top]=x;
		else
		{
			int cur=find(x);
			f[cur]=x;
		}
	}
	cout<<top<<endl;
	return 0;
}
     