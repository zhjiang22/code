/*
普及组水题~
直接模拟就好咯~
果然还是适合普及组啊窝~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string a;
int l;

void init()
{
	cin>>a;
	l=a.length();
}

int main()
{
	init();
	int ans=0,k=0;
	for(int i=0;i<l-1;i++)
		if(a[i]!='-')
			ans+=(++k)*(a[i]-'0');
	ans%=11;
	if(ans==10)
	{
		if(a[l-1]=='X')
			cout<<"Right"<<endl;
		else
		{
			for(int i=0;i<l-1;i++)
				cout<<a[i];
			cout<<'X'<<endl;
		}
	}
	else
	{
		if(a[l-1]==ans+'0')
			cout<<"Right"<<endl;
		else
		{
			for(int i=0;i<l-1;i++)
				cout<<a[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}
     