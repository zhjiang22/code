#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=55;
struct node
{
	int x,y;
};
char a[MAXN][MAXN];
vector<node> v;
int n,m;
int ans;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
}

bool check(int x,int y)
{
	if((x>1&&a[x-1][y]=='#')||x==1)
		if(x+1<=n&&x+2<=n)
			if(a[x][y]!='#'&&a[x+1][y]=='.'&&a[x+2][y]=='.')
				return 1;
	if((y>1&&a[x][y-1]=='#')||y==1)
		if(y+1<=m&&y+2<=m)
			if(a[x][y]!='#'&&a[x][y+1]=='.'&&a[x][y+2]=='.')
				return 1;
	return 0;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(check(i,j))
				ans++,v.push_back((node){i,j});
		}
	cout<<ans<<endl;
	for(int i=0;i<v.size();i++)
		cout<<v[i].x<<" "<<v[i].y<<endl;
	return 0;
}
     