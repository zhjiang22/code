/*
NOIP签到题Orz
字符串处理这种水题
从来是要自己做	因为每个人的想法都会不一样
我比较傻咯写了个傻傻的程序23333
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string c;
string k;
int c1,k1;

void init()
{
	cin>>k>>c;
	k1=k.length();
	c1=c.length();
}

char change(char x)
{
	if(x<='z'&&x>='a')
		x-='a'-'A';
	return x;
}

bool isxiao(char x)
{
	return (x<='z'&&x>='a');
}

char get(char a,char b)
{
	int y=change(b);
	if(isxiao(a))
		return(char)(((a-'a')-(y-'A')+26)%26)+'a';
	else
		return(char)(((a-'A')-(y-'A')+26)%26)+'A';
}

void work()
{
	for(int i=0;i<c1;i++)
		cout<<get(c[i],k[i%k1]);
}

int main()
{
	init();
	work();
	return 0;
}
     