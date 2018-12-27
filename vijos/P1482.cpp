/*
模拟？OTZ
一开始一直在想直接暴力匹配会不会炸
看来是我想多了23333
注意这道题的两个坑点
1.delate不是delate啊，是de1ate(出题人丧心病狂没看到直接爆零)
2.输入的信息会含有空格,所以直接cin一个string就炸了...
窝是用的gets来弄了
那么问题其实就在于怎么判断一个字符串是不是危险的了
我们可以看到一个字符串也就是10个以内
我们完全可以直接暴力O(n^4)枚举这四个、字符
然后判断是否有问题就行了
这样的话复杂度是完全过的去的
枚举一个字符串的时间也就是10^4(实际上会少很多)
一共有10^4个字符串
那么实际运算远远小于10^8的
所以可以稳过了(差不多可以秒杀了)
暴力出奇迹啊~！
细心一点如果要输出的东西最好还是复制为妙
毕竟总有丧心病狂的出题人啊
害怕
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char a[13];
int n,l;

bool check(char *a)
{
	int l=strlen(a);
	if(l<4)
		return 1;
	for(int i=0;i<l;i++)
		for(int j=i+1;j<l;j++)
			for(int k=j+1;k<l;k++)
				for(int p=k+1;p<l;p++)
					if(a[i]==a[j]&&a[k]==a[p])
						return 0;
					else	if(a[i]==a[p]&&a[j]==a[k])
						return 0;
	return 1;
}

int main()
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		gets(a);
		if(check(a))
			printf("safe\n");
		else
			printf("de1ete\n");
	}
	return 0;
}
     