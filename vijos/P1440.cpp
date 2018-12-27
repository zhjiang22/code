/*
Orz水题啊
由于只有四个移动方向，所以x、y可以分开考虑。
只考虑y，y[1]到y[n]要移动到同一行，代价最小，
则假设p为y[]的中位数，都移动到第p行，代价最小。
再来看x，由于x是紧密的排在一起的，我们对x排序之后，排在第 i 位的士兵一定在最终排列的第 i 位，
那么我们如果对 x 排序之后，每个x[i]-=i，就变成了将 x 移动到同一列了（与上面的问题相同了）。
其实也就是三个sort的事情
注意中位数的选取
基础功了 排序后的(n+1)/2
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=10005;
int x[maxn],y[maxn];
int n;
int ans;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
}

int main()
{
	init();
	sort(x+1,x+n+1);
	sort(y+1,y+n+1);
	for(int i=1;i<=n;i++)
		x[i]-=i;
	sort(x+1,x+n+1);
	int k=(n+1)/2;
	for(int i=1;i<=n;i++)
		ans+=(abs(x[i]-x[k])+abs(y[i]-y[k]));
	cout<<ans<<endl;
	return 0;
}
     