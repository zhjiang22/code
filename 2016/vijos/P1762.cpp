/*
虽然是C++
但是还是不得不说
水题...
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string a;
int ans;

int main()
{
	while(cin>>a)
	{
		if(a=="begin")
			break;
		for(int i=0;i<a.length();i++)
			if(a[i]==','||a[i]==':')
				ans++;
	}
	cout<<ans<<endl;
	return 0;
}
     