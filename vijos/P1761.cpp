/*
狗血字符串题~~~
这种题目看别人题解也没啥用~
还是要自己多做多尝试~~
多试几种情况~
如果是二十分只过2 4点很有可能是没有考虑到
要要查找的单词比如说只含一个字母
同时是要被查找的文章某几个单词的前缀
这样就会导致统计数增多~
代码有点丑还是自己写写叭~~
STLstring也是可以用的
不过要加点优化了
但是NOIP最好还是不建议用STLstring叭~
毕竟读入真神慢
手写也无大碍
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1000005;
char a[MAXN],c[MAXN];
int n;
int tot;

void doit(char* c)
{
	int l=strlen(c);
	for(int i=0;i<l;i++)
		if(c[i]>='A'&&c[i]<='Z')
			c[i]+=('a'-'A');
}

void init()
{
	gets(a);	gets(c);
	doit(a);	doit(c);
}

void work()
{
	int la=strlen(a);	int lc=strlen(c);
	int i=0;	
	int fisrt=-1;	int tot=0;
	while(i<lc)
	{
		while(c[i]==' '&&i<lc)
			i++;
		int nowi=i;
		if(i==lc)
			break;
		int j=0;
		while(c[i]!=' ')
		{
			if(c[i]==a[j]&&i<lc)
			{
				i++;	j++;
			}
			else
				break;
		}
		if(j==la&&(c[i]==' '||i==lc)&&fisrt==-1)
			fisrt=nowi;
		if(j==la&&(c[i]==' '||i==lc))
			tot++;
		while(c[i]!=' ')
			i++;
	}
	if(fisrt!=-1)
		printf("%d %d\n",tot,fisrt);
	else
		printf("-1\n");
}

int main()
{
	init();
	work();
}
     