#include <iostream>
using namespace std;

int a[12];
int x,ans;

int main()
{
	for(int i=1;i<=10;i++)
		cin>>a[i];
	cin>>x;
	x+=30;
	for(int i=1;i<=10;i++)
		if(x>=a[i])
			ans++;
	cout<<ans<<endl;
	return 0;
}
     