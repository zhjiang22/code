/*
直接裸的dfs了
有点像素数环？
但是更水根本不需要回溯，看到n最大就到8而已
我们用cur记录层数
用x来记录当前已经选到的数字了
我们每层递归下去都要满足新的数是要满足素数的
一位一位构造就好了
然后差不多应该用printf应该可以秒出解叭
注意一开始递归的时候我们就可以直接针对一位的素数来写
精神安慰更好一点2333333
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n;

bool is_prim(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}

void dfs(int x,int cur)
{
	if(cur==n)
	{
		cout<<x<<endl;
		return;
	}
	for(int i=1;i<=9;i++)//0可以直接忽略
	{
		int c=x*10+i;
		if(is_prim(c))
			dfs(c,cur+1);
	}
}

int main()
{
	cin>>n;
	dfs(2,1);
	dfs(3,1);
	dfs(5,1);
	dfs(7,1);
	return 0;
}
     