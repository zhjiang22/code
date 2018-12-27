#include <bits/stdc++.h>
using namespace std;

#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define _rep(i,a,b) for(int i=(a);i<=(b);i++)

int t;
string a;
int l;

void init()
{
	cin>>a;
	l=a.length();
}

void work()
{
	int ans=0;
	int cur=0;
	_for(i,0,l)
	{
		if(a[i]=='O')
		{
			ans+=(++cur);
		}
		else
			cur=0;
	}
	cout<<ans<<endl;
}

int main()
{
	cin>>t;
	while(t--)
	{
		init();
		work();
	}
	return 0;
}