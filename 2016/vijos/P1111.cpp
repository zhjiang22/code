#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int f[101][101];
char a[102],b[102];

int main()
{
	while(scanf("%s %s",a,b)==2)
	{int c1=strlen(a);
		int c2=strlen(b);
		for(int i=0;i<=c1;i++)
			f[i][0]=0;
		for(int i=0;i<=c2;i++)
			f[0][i]=0;
		for(int i=1;i<=c1;i++)
			for(int j=1;j<=c2;j++)
				if(a[i-1]==b[j-1])
					f[i][j]=f[i-1][j-1]+1;
				else
					f[i][j]=max(f[i-1][j],f[i][j-1]);
		int k=f[c1][c2];
		cout<<c1+c2-k<<endl;}
	return 0;
}
     