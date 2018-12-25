/*
设f[i][j]为左端点不超过i，右端点不超过j的最大值，则有： 
f[i][j] = max{f[i - 1][j],f[i][j - 1],f[i - 1][j - 1] + sum[j] - sum[i - 1]}; 
为什么可以这样做呢？
我们来看这题是要求没有区间重复的问题
有点LCS的味道？
一个区间不能选那么必然是被覆盖了的
那就对应着
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
long long f[MAXN][MAXN];
long long l[MAXN],w[MAXN];
int n,least,maxl;

void init()
{
	int ll,ww;
	scanf("%d%d%d",&n,&least,&maxl);
	for(int i=1;i<=n;i++)
		scanf("%d",&ll),l[i]=l[i-1]+ll;
	for(int i=1;i<=n;i++)
		scanf("%d",&ww),w[i]=w[i-1]+ww;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(l[j]-l[i-1]>=least&&l[j]-l[i-1]<=maxl)
				f[i][j]=max(f[i-1][j-1]+w[j]-w[i-1],max(f[i-1][j],f[i][j-1]));
			else
				f[i][j]=max(f[i-1][j],f[i][j-1]);	
	cout<<f[n][n]<<endl;
	return 0;
}
