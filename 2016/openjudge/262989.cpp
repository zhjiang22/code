/*
f[i][j]表示到第i件余数为j的最优解
我们可以这样考虑，
方案1：余数为x，拿到的糖是100 一定优于 
方案2：余数是x，拿到的糖是50, 所以可以这么dp
就是我们先对于所有的f[i][j]用其对应的f[i-1][]更新出一个值
然后对于所有的f[i][]考虑取f[i][j]和f[i-1][j]的最优值
即更新上来
其实窝是第一次看过这样做的啦2333333333
可能是窝太弱惹%%%%cy
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
int f[MAXN][MAXN];
int n,k;
int x;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		f[i][x%k]=x;
		for(int j=0;j<k;j++)
			if(f[i-1][j])
				f[i][(j+x)%k]=f[i-1][j]+x;
		for(int j=0;j<k;j++)
			f[i][j]=max(f[i][j],f[i-1][j]);
	}
	cout<<f[n][0]<<endl;
	return 0;
}
