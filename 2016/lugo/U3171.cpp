#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,j,z;

int main()
{
	cin>>n>>j>>z;
	while(z>0&&n>0)
	{
		n-=z;
		z-=j;
	}
	if(z<0&&n>0)
		cout<<"run"<<endl;
	else
		cout<<"fight"<<endl;
	return 0;
}
     