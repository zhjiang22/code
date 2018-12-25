/*
第100题
这坑爹的测评机编译参数又错了？一加某几个头文件就炸，还是有先见之明
手写了个abs
可以用dp或者记忆化搜索做
直接暴力点搜索就好啦没啥解释的
注意不要傻了把y1，y2打反了啥的就好
*/
#include <iostream>
using namespace std;

long long f[1009][1009];//最后一个点要开到Longlong
int n,m;
int x1,y1;
int x2,y2;

int ab(int x){return x>0?x:-x;}

long long dfs(int x,int y)
{
	if(x==x1&&y==y1)//到达了目标~
		return 1;
	if(2*(x-x1)<ab(y-y1))return 0;//剪枝，易知因为每次要向右跳，当距离起点纵坐标太远时，
								  //最好的情况就是y-2,x-1，所以当距离起点的横距离
								  //的两倍比纵距离还小时，则不可能到达可以剪枝
	if(x>n||x<1||y<1||y>m)//判断越界
		return 0;
	if(f[x][y])
		return f[x][y];//记忆化搜索
	return f[x][y]=dfs(x-2,y+1)+dfs(x-2,y-1)+dfs(x-1,y+2)+dfs(x-1,y-2);//四种走法
}

int main()
{
	cin>>n>>m;
	cin>>x1>>y1;
	cin>>x2>>y2;
	long long x=dfs(x2,y2);//从终点往辉走
	if(x==0)
		cout<<"NO"<<endl;
	else
	cout<<x<<"00000000"<<endl;
	return 0;
}
     