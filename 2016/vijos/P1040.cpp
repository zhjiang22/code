#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

char str1[10002],str2[10002];
int a[10002],b[10002],c[20010];
int c1,c2;

void init()
{
	for(int i=0;i<c1;i++)
		a[c1-i-1]=str1[i]-'0';
	for(int i=0;i<c2;i++)
		b[c2-i-1]=str2[i]-'0';
}

int main()
{
	scanf("%s %s",str1,str2);
	c1=strlen(str1);
	c2=strlen(str2);
	init();
	for(int i=0;i<c1;i++)
		for(int j=0;j<c2;j++)
		{
			c[i+j]+=a[i]*b[j];
			if(c[i+j]>=10)
				c[i+j+1]+=c[i+j]/10,c[i+j]%=10;
		}
	int k;
	for(k=c1+c2;k>=0;k--)
		if(c[k]!=0)	break;
	for(int i=k;i>=0;i--)
		cout<<c[i];
	return 0;
}
     