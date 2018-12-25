#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=10000;
int a[maxn];
int main()
{
 	int n;
 	cin>>n;
 	for(int i=0;i<n;i++)
 	cin>>a[i];
 	sort(a,a+n);
 	cout<<a[n-2];
 	system("pause");
 	return 0;
}
 
