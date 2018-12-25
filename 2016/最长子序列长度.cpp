#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char str[500];
char a[202],b[202];
int c1,c2;
int f[202][202];

int main()
{	while(gets(str))
	{
	memset(f,0,sizeof(f));

	sscanf(str,"%s%s",a,b);
	c1=strlen(a);
	c2=strlen(b);
	for(int i=1;i<=c1;i++)
	{
		for(int j=1;j<=c2;j++)
		if(a[i-1]==b[j-1])
		f[i][j]=f[i-1][j-1]+1;
		else
		f[i][j]=max(f[i-1][j],f[i][j-1]);
	}
	cout<<f[c1][c2]<<endl;
	}
	return 0;
}