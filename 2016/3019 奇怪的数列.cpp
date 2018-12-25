#include<iostream>
using namespace std;
long long int a[100];
int main()
{
 	 int n;
 	 a[1]=0;
 	 a[2]=1;
 	 a[3]=0;
	 cin>>n;
     for(int i=4;i<80;i++)
     a[i]=a[i-1]+a[i-2]+a[i-3]+1;
     cout<<a[n];
     system("pause");
	 return 0;

}   
