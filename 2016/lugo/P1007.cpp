#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int maxw,minw;
int n,l;
int x;

int main()
{
	cin>>l>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		minw=max(minw,min(x,l+1-x));
		maxw=max(maxw,max(x,l+1-x));
	}
	cout<<minw<<" "<<maxw<<endl;
	return 0;
}
     