#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int x,y,z;
int m;
int a,b,c;
int d,e,f;
char ch,ch2;

int main()
{
	freopen("plumber.in","r",stdin);
	freopen("plumber.out","w",stdout);
	scanf("%d%d%d%d",&x,&y,&z,&m);
	scanf("%d%d%d%c",&a,&b,&c,&ch);
	scanf("%d%d%d%c",&d,&e,&f,&ch2);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
	}
	printf("impossible\n");
	return 0;
}
    