/*
直接一个循环就好咯~
想几个月前的自己还傻的用公式推导
真是物是人非啊
我会越来越强的>3<
*/
#include <iostream>
using namespace std;

int ans;
int n;
int tot;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			ans+=i;
			tot++;
			if(tot==n)
				break;
		}
		if(tot==n)
			break;
	}
	cout<<ans<<endl;
	return 0;
}
     