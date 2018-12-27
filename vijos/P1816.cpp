/*
排序题？	Orz不能一遍A了OI再见
让我开始写吧
////////////////////
66666两分钟写完直接A了
唉这种签到题就不说了
Orz让我休息一下QWQ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=200005;
int a[MAXN];
int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int tot=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
			tot++;
		else
		{
			cout<<a[i]<<" "<<tot<<endl;
			tot=1;
		}
	}
	return 0;
}
