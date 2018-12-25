#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

double low,high;
int t,n;
int sum,zero;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int x;
		sum=zero=low=high=0;
		for(int i=1;i<=n;i++)
			cin>>x,sum+=x,zero+=(x==0);
		high=sum+0.5*n;	low=sum-0.5*(n-zero);
		if(high>100&&low<=100)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
     