/*
水题啊~
直接O(nm)枚举就好了
因为高度为0的陶陶不能摘
所以我们干脆就用高度0表示不能摘或者摘完
然后摘到一个标记为0就好啦~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=2005;
int a[MAXN];
int b[MAXN];
int n,m;
int tot;

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
}

int main()
{
	init();
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
			if(b[j]&&b[j]<a[i])
			{
				b[j]=0;
				tot++;
				break;
			}
	}
	cout<<m-tot<<endl;
	return 0;
}
     