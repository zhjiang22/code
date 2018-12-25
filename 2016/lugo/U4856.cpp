#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

set<int> s;
int ans;
int n;

int main()
{
	cin>>n;
	int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(!s.count(x))
		{
			s.insert(x);
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
     