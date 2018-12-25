#include<iostream>
#include<algorithm>
using namespace std;

int z(int a,int b)
{
	int s1,s2,s;
	if(a==b)
	return 1;
	else
	s1=min(a,b),s2=max(a,b);
	
	if(s2%s1==0)
	return s2/s1;
	else
	{
		s=s2%s1;
		return z(s,s1)+s2/s1;
	}
}

int main()
{
		int x,y;
		cin>>x>>y;
		cout<<z(x,y);
		return 0;
}