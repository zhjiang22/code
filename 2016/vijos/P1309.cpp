/*
如果一个正方形被划分为n个凸多边形,这些凸多边形边数的最大值max=3n+1;
*/
#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstring>
using namespace std;

int m;
long long n;
string a;
int b[11]={1,2,4,8,16,32,64,128,256,512,1024};

int main()
{
	cin>>a;
	cin>>m;
	int len=a.length();
	for(int i=0;i<len;i++)
			n=(n*10+a[i]-'0')%b[m];
	cout<<(n*3)%b[m]+1<<endl;
	return 0;
}