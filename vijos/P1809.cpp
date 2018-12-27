/*
NOIP普及最后一题竟然成了水题模拟。。。
首先我们要弄清楚这样的关系(别被题目骗了)
有必胜策略，玩家总能保证电脑取不到最大边，
且玩家能取到的最优边一定是某个顶点的次大边
我们可以发现如果计算机只能被动拆小涵每次选择武将的最大默契，
那么上次选择的就无力拆散了。因此每个武将第二大的肯定不会被拆散。
所以我们只需要找第二大的中的最大值即可。
所以就成了一个赤裸裸的模拟题了而已~
只要找出所有点(武将)的第二大的默契值即可这就是可以得到的最大价值
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=505;
int g[MAXN][MAXN];
int ans;
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			cin>>g[i][j];
			g[j][i]=g[i][j];
		}
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		int max1=0,max2=0;
		for(int j=1;j<=n;j++)
		{
			int &x=g[i][j];
			if(x>max1)
			{
				max2=max1;	max1=x;
			}
			else	if(x>max2)
				max2=x;
		}
		ans=max(ans,max2);
	}
	cout<<1<<endl;
	cout<<ans<<endl;
	return 0;
}
     