#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double a,l;
	cin>>a>>l;
	int n=1,d=1;
	int ansn,ansd;
	double min=9999999,cha;
	while(n<=l&&d<=l)
	{
		cha=a-(double)n/d;
		if(min>fabs(cha))
		{
			min=fabs(cha);
			ansn=n;
			ansd=d;
		}
		if(cha>0)
		n++;
		else 
		d++;
	}
	cout<<ansn<<" "<<ansd;
	return 0;
}