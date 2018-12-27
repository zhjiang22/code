#include<bits/stdc++.h>
using namespace std;

string a,b;
int n,m;

void init()
{
	n=a.length();
	m=b.length();
}

void work()
{
	if(n>m)
	{
		printf("No\n");
		return;
	}
	int i=0,j=0;
	while(i<n&&j<m)
	{
		if(a[i]==b[j])		
			i++,j++;
		else
			j++;
	}
	if(i==n)
		printf("Yes\n");
	else
		printf("No\n");
}

int main()
{
	while(cin>>a>>b)
	{
		init();
		work();
	}
	return 0;
}
     