/*
这个基数的鬼东西~
唉数学不好随便乱搞就好啦~
我也不知道为什么，负数的进制就是这么写的，反正记住就是，
如果余数是负数，那就加上base，然后再用n-新余数 再除以base
然后随便乱搞就行了~~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int x,a;
vector<int> g;

int main()
{
	while(scanf("%d%d",&x,&a)==2)
	{
		g.clear();	int k;
		cout<<x<<"=";
		while(x)
		{
			k=x%a;	x/=a;	
			if(k<0)
				k-=a,x++;
			g.push_back(k);
		}
		int l=g.size();
		for(int i=l-1;i>=0;i--)
			if(g[i]<10)
				cout<<g[i];
			else
				cout<<(char)('A'+(g[i]-10));
		cout<<"(base "<<a<<")"<<endl;
	}
	return 0;
}
     