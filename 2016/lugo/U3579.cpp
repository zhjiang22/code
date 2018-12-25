#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string a;
int n;
int c,o,w;
long long ans;

int main()
{
	cin>>n;
	cin>>a;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]=='W')
			w++;
		else	if(a[i]=='O')
			o+=w;
		else
			ans+=o;
	}
	cout<<ans<<endl;
	return 0;
}
     