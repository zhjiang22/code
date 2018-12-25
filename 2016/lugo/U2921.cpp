#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool a[4][6];
int ans=1;

int main()
{
	for(int i=1;i<=3;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];
	for(int i=1;i<=3;i++)
	{
		bool ok=0; int tot=0;
		for(int j=1;j<=5;j++)
		{
			if(ok)
				tot++;
			if(a[i][j]==1)
				ok=1;
		}
		ans*=tot;
	}
	cout<<ans<<endl;
	return 0;
}
     