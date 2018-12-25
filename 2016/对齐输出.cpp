#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
	freopen("E:\\in.txt","r",stdin);
	freopen("E:\\out.txt","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	cout<<setw(8)<<a<<setw(8)<<b<<setw(8)<<c;
	return 0;
}