#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN=10000008;
bool vis[MAXN+6];
int primer[MAXN+6];
int l,n,k;

void prime()
{
	bool o=0;
	int c=sqrt(MAXN+0.5);
	vis[1]=1;
	for(int i=2;i<=c;i++)
		if(!vis[i])
		{
			for(int j=i*i;j<=MAXN;j+=i)
				vis[j]=1;
		}
	vis[1]=1;
	for(int i=1;i<=MAXN;i++)
		if(!vis[i])
		{
			primer[++l]=i;	
			if(i>=n&&!o)
			{
				k=l;
				o=1;
			}
		}
}

int main()
{
	cin>>n;
	prime();
	for(int i=k;i<=l;i++)
		if(!vis[i])
		{
			cout<<primer[i]<<endl;
			return 0;
		}
	return 0;
}
     