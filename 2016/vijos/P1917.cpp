/*
此题巧妙利用了要求数一定出现超过一半，节约空间一个个数读入，用k来记录个数，
运用+ -对消的方法求出出现最多的数
注意一定要用scanf读入不然完美超时
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int x,n;
int k;

int main()
{
	scanf("%d%d",&n,&x);
	int a;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
		if(a==x)
			k++;
		else	if(k==0)
			x=a,k++;
		else k--;
	}
	cout<<x<<endl;
	return 0;
}
     