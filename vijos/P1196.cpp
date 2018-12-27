/*
我们看到数据可以达到10000位就知道肯定是有规律可行的
所以如果实在想不到就多试几个数据找规律叭
来看个正解
当游戏状态属于前者时，
Matrix67可以把糖果数被5除余1、4或正好除尽的那一堆分成糖果数被5除余数都是2或3的两堆
（他总能做到这一点）
而对方不得不把其中一堆糖果又分出新的糖果数被5除余1、4或正好除尽的一堆留给Matrix67操作。
这样逼着对方总是面临必败的状态，使得最后对方不得不把2个糖果或者3个糖果分成两堆，
从而使Matrix67赢得游戏。
反过来，当Matrix67面临两堆糖果的数目被5除余数都是2或3的状态时，Shadow总可以取胜。
所以就是如果两堆的个数的个位数都是2 3 7 8的一个的话
就是Shadow取胜
不然就是Matrix
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
char a[MAXN];
char b[MAXN];

int main()
{
	while(scanf("%s%s",a,b)==2)
	{
		char x=a[strlen(a)-1];
		char y=b[strlen(b)-1];
		if((x=='2'||x=='3'||x=='7'||x=='8')&&(y=='2'||y=='3'||y=='7'||y=='8'))
			printf("Shadow\n");
		else
			printf("Matrix67\n");
	}
	return 0;
}
