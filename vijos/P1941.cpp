/*
如此水的一道省选题~
NOIPT1难度吧？
直接模拟就好了~
这个代码长度给满分啊
*/
#include <iostream>
using namespace std;

const int MAXN=205;
int p[MAXN>>1][3];
int a[MAXN][3];
int ans[MAXN];
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			cin>>a[i][j];
}

int main()
{
	init();
	for(int j=0;j<3;j++)
		for(int i=1;i<=n;i++)
			p[a[i][j]][j]++;
	for(int k=0;k<3;k++)
		for(int i=1;i<=n;i++)
			if(p[a[i][k]][k]==1)
				ans[i]+=a[i][k];
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}
     