/*
STL直接模拟即可，但是要注意呀
vector和数组一样开始元素是0，而第一个编号是1
一定要小心，总体还是挺简单的

																Powder
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> v;
int k=1;
int n,m,ans;

int main()
{
	cin>>n>>m;
	v.clear();
	for(int i=1;i<=n;i++)
		v.push_back(i);
	for(int i=1;i<=m;i++)
	{
		int p=i*i*i%5+1;
		k+=p;
		if(k>v.size())
			k=p+1;
		if(i!=m)//第m次是跳到的位置，不能删除，需要判断
		v.erase(v.begin()+k-1);//删除该位置
	}
	cout<<v[k-1]<<endl;//k应该-1
	return 0;
}
     