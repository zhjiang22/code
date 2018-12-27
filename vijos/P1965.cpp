/*
什么鬼
本来是想针对小数据我们算一算
大数据直接交无解
结果只有二十分
lgb直接交了无解30分
泪流 无爱~！
搜索题？表示太弱了并不会做Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int A,B,C,X;
int n;
int a[10000];
int can;

int random()
{
    int Return_Value=X;
    X=((long long)X*A+B)%C;
    return Return_Value;
}

int main()
{
	cin>>n>>C;
	if(C>6)
	{
		cout<<"Unsuccessful Hack Attempt"<<endl;
		return 0;
	}
	for(int i=1;i<=n-1;i++)
		cin>>a[i];
	for(int x=0;x<C;x++)
		for(int y=0;y<C;y++)
			for(int k=0;k<C;k++)
			{
				X=x;A=y;B=k;
				for(int i=1;i<=n-1;i++)
				{
					if(a[i]!=random())
						break;
					else	if(i==n-1)
						{cout<<x<<" "<<y<<" "<<k<<endl;
											can=1;}
				}
			}
	if(!can)
		cout<<"Unsuccessful Hack Attempt"<<endl;
	return 0;
}
     