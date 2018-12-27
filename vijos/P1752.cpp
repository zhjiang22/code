/*
水题啊字符串处理
tyvj的某次NOIP模拟赛也有一道和这个差不多意思的题目
然而那道题用了什么双射就是要自动对应
然后我就gg了
还傻逼一样写错了个地方
第一题崩了第二题反而AC了23333
我们用一个g[]和g1[]分别来记录谁被谁映射和谁映射谁
这样就要双面检查
嗯挺简单的也不想多说
只能说注意细节
细节决定成败
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=30;
const int MAXNv=1005;
int g[MAXN];
int g1[MAXN];
char a[MAXNv];
char b[MAXNv];
char c[MAXNv];
char d[MAXNv];

int main()
{
	gets(a);
	gets(b);
	gets(c);
	memset(g,-1,sizeof(g));
	memset(g1,-1,sizeof(g1));
	int k=strlen(a);
	for(int i=0;i<k;i++)
	{
		if(g[a[i]-'A']!=-1&&g[a[i]-'A']!=b[i]-'A')
		{
			printf("Failed");
			return 0;
		}
		else	if(g1[b[i]-'A']!=-1&&g1[b[i]-'A']!=a[i]-'A')
		{
			printf("Failed");
			return 0;
		}
		else
		{
			g[a[i]-'A']=(b[i]-'A');
			g1[b[i]-'A']=(a[i]-'A');
		}
	}	
	for(int i=0;i<=25;i++)
		if(g[i]==-1)
		{
			printf("Failed");
			return 0;
		}
	int d=strlen(c);
	for(int i=0;i<d;i++)
	{
		printf("%c",g[c[i]-'A']+'A');
	}
	return 0;
}	
     
