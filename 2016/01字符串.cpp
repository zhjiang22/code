#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[35];
int n;
int ans=0;

        
void dfs(int cur)
{
	if(cur==n+1)
		{
			ans++;
			for(int i=1;i<=n;i++)
				cout<<a[i];
			cout<<endl;
		}
	else
	{
		for(int i=0;i<=1;i++)
		{
			if(cur<3)	a[cur]=i,dfs(cur+1);
			else
			{	
				if((i!=a[cur-1])||(i!=a[cur-2]))
			{
				a[cur]=i;
				dfs(cur+1);
			}
				else continue;
			}
		}
	}
}

int main()
{
	freopen("D:\\in.txt","r",stdin);
	freopen("D:\\out.txt","w",stdout);
	cin>>n;
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}