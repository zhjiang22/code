/*
既然水题
我就不多说话
随便处理一下就好了
样例还是很良心的OTZ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=50;
char a[MAXN];
int l;

int main()
{
	gets(a);
	l=strlen(a);
	if(l==1)
	{
		cout<<a[0]<<endl;
		return 0;
	}
	else
	{
		int k=l-1;
		int p=0;
		if(a[p]=='-')
		{
			cout<<"-";
			p++;
		}
		while(a[k]=='0')
			k--;
		for(int i=k;i>=p;i--)
			cout<<a[i];
	}
	return 0;
}
     