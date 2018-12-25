#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[15];
int v[15];
int n;

void dfs(int cur)
{
	if(cur==n+1)
	{
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
		{
			a[cur]=i;
			v[i]=1;
			dfs(cur+1);
			v[i]=0;
		}
}

int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
     