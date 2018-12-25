#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstring>
using namespace std;
string a,b;
int f[1000][1000];

int Min(int a,int b,int c)
{
	return min(min(a,b),c);
}

int main()
{
	cin>>a>>b;
	int c1=a.length();
	int c2=b.length();
	f[0][0]=0;
	for(int i=1;i<=c1;i++)
		f[i][0]=i;
	for(int j=1;j<=c2;j++)
		f[0][j]=j;
	for(int i=1;i<=c1;i++)
		for(int j=1;j<=c2;j++)
		{
			if(a[i-1]==b[j-1])
				f[i][j]=Min(f[i-1][j-1],f[i-1][j]+1,f[i][j-1]+1);
			else
				f[i][j]=Min(f[i-1][j-1]+1,f[i-1][j]+1,f[i][j-1]+1);
		}		
	cout<<f[c1][c2];
	return 0;
}
