#include<iostream>
#include<algorithm>
using namespace std;

int su(int x)
{
	for(int i=2;i<=x/2;i++)
	if(x%i==0)
	return 0;
	else
	return 1;
}

int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	int y=max(n,m);
	int x=min(n,m);
	for(int i=x+1;i<y;i++)
	{
		if(su(i))
		ans=ans+i;
	}
	cout<<ans<<endl;
	return 0; 
} 
