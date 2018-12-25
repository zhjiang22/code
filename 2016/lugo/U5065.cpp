#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

double z=1.75;
int x,n;
double w;

int main()
{
	cin>>x>>n;
	if(x>10)
	{
		cout<<"ERROR"<<endl;
		return 0;
	}
	w=z*n;
	int k=(int)(w+0.5);
	if(k%2==0)
		cout<<k/2<<endl;
	else
		cout<<k/2<<".5"<<endl;
	double ans=k*0.5;
	if(ans>=x)
		cout<<"DIE"<<endl;
	else
		cout<<x-ans<<endl;
	return 0;
}
     