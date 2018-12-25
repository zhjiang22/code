/*
一道经典的递归树形结构，运气不错一遍过了，没有犯一些低级的错误
对于一个2^n的串，用到2^(n+1)的数组，输入数据在(2^n)到(2^(n+1)-1)，
相当于在二叉树结构数组后部输入的
然后开始递归，注意：
	我们在手算数据的时候，应该会想到从上向下构造树，即一层一层写下去
但是在写程序的时候，更方便的应该是从下向上建树*
因为可以看出这个二分结构的树状递归的性质是
一个结点的值和其左右子结点的值有关，所以从下向上建立肯定更优
(不然从上向下每次要扫描？ORZ反正很麻烦)
嗯QAQ就这样吧心好累继续水题了
														Powder
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=(1<<11)+1;
struct node
{
	char c;
	int lc,rc;
	node(int x=-1,int y=-1):lc(x),rc(y){};
}tree[maxn];
int n;

char check(int x,int y)
{
	if(tree[x].c=='B'&&tree[y].c=='B')
		return 'B';
	if(tree[x].c=='I'&&tree[y].c=='I')
		return 'I';
	return 'F';
}

void print(int root)
{
	if(root!=-1)
	{
		print(tree[root].lc);
		print(tree[root].rc);
		cout<<tree[root].c;
	}
}

int main()
{
	char ch;
	cin>>n;
	for(int i=(1<<n);i<(1<<(n+1));i++)
	{
		cin>>ch;
		if(ch=='0')
			tree[i].c='B';
		else
			tree[i].c='I';
	}
	int temp=n-1;
	while(temp>=0)
	{
		for(int i=(1<<temp);i<(1<<(temp+1));i++)
		{
			tree[i].lc=2*i;
			tree[i].rc=2*i+1;
			tree[i].c=check(2*i,2*i+1);
		}
		temp--;
	}
	print(1);
	return 0;
}
     