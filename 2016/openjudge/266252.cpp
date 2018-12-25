#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=25;
bool f[MAXN][MAXN];
char a[MAXN];
char b[MAXN];
int la,lb;

void init()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	la=strlen(a+1);	lb=strlen(b+1);
}

int main()
{
	init();
	f[0][0]=1;
	for(int i=1;i<=la;i++)
	{
		bool p=f[i-1][0];
		if(a[i]=='*')
			f[i][0]=p;
		for(int j=1;j<=lb;j++)
		{
			p|=f[i-1][j];
			if((a[i]=='?'||a[i]==b[j])&&f[i-1][j-1])
				f[i][j]=1;
			if(a[i]=='*')
				f[i][j]=p;
		}
	}
	if(f[la][lb])
		printf("matched");
	else 
		printf("not matched");
	return 0;
}
     