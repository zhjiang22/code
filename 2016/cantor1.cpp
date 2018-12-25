#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int k=1,s=0;
		for(;;)
		{
			s+=k;
			if(s>=n)
			{
				if(k%2)
				cout<<s-n+1<<k-s+n;
				else 
				cout<<k-s+n<<"/"<<s-n+1<<endl;
				break;
			}
			k++;
		}
	}
	return 0;
}
