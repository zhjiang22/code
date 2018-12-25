#include<cstdio>
#include<iostream>
using namespace std;

long long double a[10000];
long b[10000];

int main()
{
 	long n;
 	cin>>n;
 	for(int i=0;i<n;i++)
 	cin>>a[i];
 	memset(b,0,sizeof(b));
 	sort(a,a+n);
 	for(int i=0;i<n;i++)
 	{
	 		if(a[i]==a[i+1])
 	{
	 				b[i+1]+=b[i];
    }
    else
    {
	 	cout<<a[i];
		 if(b[i])
	 	cout<<" "<<b[i];
    }
    }
    system("pause");
    return 0;
}
    
 	
