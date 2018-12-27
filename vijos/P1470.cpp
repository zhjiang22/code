/*
好dp~	奇妙~	fantastic~
果断智商低想不出来
因为是环形的所以状态很难设计
转移也有点麻烦
还是向题解投降了
面向题解编程~！
0表示树高为10且后一棵要更高
1表示树高为20且后一棵要更高
2表示树高为20且后一棵要更矮
3表示树高为30且后一棵要更矮
那么设计出这样的状态就很好解决了
f[i][x]表示到了第i个位置当前状态是x最优价值
对应的转移是这样的
f[i][0]=max(f[i-1][2],f[i-1][3])+a[i][0];
f[i][1]=f[i-1][3]+a[i][1];
f[i][2]=f[i-1][0]+a[i][1];
f[i][3]=max(f[i-1][0],f[i-1][1])+a[i][2];
因为是环形
所以我们枚举第一棵的所有的情况
同时最后转移出来的f[n][]必须还要满足这个对应的f[1][]的状态
然后尝试更新答案即可
涨姿势了~	多理解叭~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100001;
const int INF=(1<<30)-1;
int f[MAXN][4];
int a[MAXN][3];
int n,ans;

inline void getans(int x)
{
	ans=max(ans,x);
}

inline void getinit()
{
	f[1][0]=f[1][1]=f[1][2]=f[1][3]=-INF;
}

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			cin>>a[i][j];
}

void dp()
{
	for(int i=2;i<=n;i++)
	{
		f[i][0]=max(f[i-1][2],f[i-1][3])+a[i][0];
		f[i][1]=f[i-1][3]+a[i][1];
		f[i][2]=f[i-1][0]+a[i][1];
		f[i][3]=max(f[i-1][0],f[i-1][1])+a[i][2];
	}
}

int main()
{
	init();
	getinit();	f[1][0]=a[1][0];	dp();	getans(max(f[n][2],f[n][3]));
	getinit();	f[1][1]=a[1][1];	dp();	getans(f[n][3]);
	getinit();	f[1][2]=a[1][1];	dp();	getans(f[n][0]);
	getinit();	f[1][3]=a[1][2];	dp();	getans(max(f[n][0],f[n][1]));	
	cout<<ans<<endl;
	return 0;
}
     