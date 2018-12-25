#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char ch;
long long ans;
long long f;

bool isnum(char ch)
{
	return (ch<='9'&&ch>'0');
}

int main()
{
	long long num=0;
	long long now=1;
	long long tot=0;
	while(ch=getchar())
	{

		if(ch=='\n')
			break;
		tot++;
		if(!isnum(ch))
		{
			if(num>ans)
			{
				ans=num;
				f=now+1;
			}
			num=0;
			now=tot;
			continue;
		}
		else
		{
			num=(num*10)+ch-'0';
		}
	}
	cout<<f<<endl;
	return 0;
}
     