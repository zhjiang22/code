#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=20005;
int line[MAXN],list[MAXN];
int ln,lm;
int n,m,k;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int x,y;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		line[x]=1;	list[y]=1;
	}
	for(int i=1;i<=n;i++)
		if(!line[i])
			ln++;
	for(int i=1;i<=m;i++)
		if(!list[i])
			lm++;
	cout<<ln*lm<<endl;
	return 0;
}
     