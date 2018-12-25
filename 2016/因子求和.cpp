#include<iostream>
using namespace std;

int main()
{
	int n,s=0;
	cin>>n;
	for(int i=2;i<=(n/2);i++)
		if(n%i==0)
		s+=i;
	
	cout<<s<<endl;
	return 0;
} 