#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

unsigned int f[50][50];
unsigned int n,m,k;

void init()
{
	for(unsigned int i=0;i<=n;i++)
		f[i][0]=1;	
	for(unsigned int j=1;j<=m;j++)
		f[0][j]=1;

	for(unsigned int i=1;i<=n;i++)
		for(unsigned int j=1;j<=m;j++)
			f[i][j]=f[i-1][j-1]+f[i-1][j];
}

void print(unsigned int x,unsigned int y,unsigned int z)
{
	if(x==0)	return;
	unsigned int num=f[x-1][y];
	if(num<z)
	{
		cout<<"1";
		print(x-1,y-1,z-num);
	}
	else 
	{
		cout<<"0";
		print(x-1,y,z);
	}
}

int main()
{
	cin>>n>>m>>k;
	init();
	print(n,m,k);
	return 0;
}