/*
水题啊
直接记忆化搜索就好了
然后按照他的要求来返回值就行了
不多说惹
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=30;
int f[MAXN][MAXN][MAXN];
bool v[MAXN][MAXN][MAXN];
int a,b,c;

int dfs(int x,int y,int z)
{
	if(x<=0||y<=0||z<=0)
		return 1;
	if(x>20||y>20||z>20)
		return dfs(20,20,20);
	if(v[x][y][z])
		return f[x][y][z];
	v[x][y][z]=1;
	if(a<b&&b<c)
		return f[x][y][z]=dfs(x,y,z-1)+dfs(x,y-1,z-1)+dfs(x,y-1,z);
	else
		return f[x][y][z]=dfs(x-1,y,z)+dfs(x-1,y-1,z)+dfs(x-1,y,z-1)-dfs(x-1,y-1,z-1);
}

int main()
{
	while(cin>>a>>b>>c)
	{
		if(a==-1&&b==-1&&c==-1)
			break;
		else
			printf("w(%d, %d, %d) = %d\n",a,b,c,dfs(a,b,c));
	}
}
     