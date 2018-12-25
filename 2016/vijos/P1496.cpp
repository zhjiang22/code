/*
赤裸裸的枚举
范围这么小
我们可以先打好表
每个数字要用多少火柴
然后对于一个二位数要用多少火柴就直接可以分解出每一位
相加就好
写一个函数来得到他要多少火柴
这个挺简单的
还看到过一道这个一样类型的
只不过+变成了-
然后数据范围n到了500
然后还是有最多1<=T<=1000询问
然后取个模
就是要动态规划了
神犇题
https://vijos.org/p/1967
*/
#include <iostream>
#include <cstring>
using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};
int w[2050];
int n;

int solve(int x)
{
	if(x==0)
		return a[0];
	int ans=0; 
	while(x)
	{
		ans+=a[x%10];
		x/=10;	
	}
	return ans;
}

void init()
{
	for(int i=0;i<=2000;i++)
		w[i]=solve(i);
}

int main()
{
	int ans=0;
	cin>>n;
	init();
	for(int i=0;i<=1000;i++)
		for(int j=i;j<=1000;j++)
		{
			if(w[i]+w[j]>n-6)
			continue;
			int t=w[i+j];
			if(t+w[i]+w[j]+4==n)
				if(i==j)	ans++;
				else		ans+=2;	
		}
	cout<<ans<<endl;
	return 0;
} 