#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int ans;
int n;

void dfs(int cur,bool l,bool r)
{
	if(cur==n)
	{
		ans++;
		return;
	}
	if(!l)
		dfs(cur+1,1,0);
	if(!r)
		dfs(cur+1,0,1);
	dfs(cur+1,0,0);
}

int main()
{
	cin>>n;
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
     