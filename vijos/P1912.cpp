/*
数据真的水成狗啊
对于这个gcd判断是否是互质
如果我们只试到sqrt(min(x,y))
那么有可能y是x的整数倍
那么我们在主程序中应该是如果当前比例>目前最优比例
才更新
Orz不然就可能会取到更大的数
比如说这组数据
{
20
1000
1111
}
答案很明显是1 50
但是如果k<ans改成k<=ans
很明显出来的答案应该是19 19*50(我数学差懒得算啊凑合看)
然后就很明显会WA
为了测试一下除到sqrt 和直接除到最小数能快多少
然后惊奇地发现如果改成<=不改gcd这个函数
也能AC
唉真是醉了
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const double INF=99999999;
int a,b,l;
double bi;
double ans=INF;
int p,q;

bool gcd(int x,int y)
{
	int k=min(x,y);
	for(int i=2;i<=sqrt(k);i++)
		if(x%i==0&&y%i==0)
			return 0;
	return 1;
}

int main()
{
	cin>>a>>b>>l;
	bi=((double)a/(double)b);
	for(int i=1;i<=l;i++)
		for(int j=(int)(i*bi);j<=l;j++)
		{
			if(!gcd(i,j))
				continue;
			double k=(double)j/(double)i;
			if(k>=bi&&k<ans)
			{
				ans=k;
				p=i;
				q=j;
			}
		}
	cout<<q<<" "<<p<<endl;
	return 0;
}
     