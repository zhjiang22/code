/*
T1水题...Orz直接模拟就好啦~
这种题目不能一遍过就要...
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=300;
struct student
{
	int c,m,e,s,idx;
}a[MAXN];
int n;

inline bool cmp(const student&a,const student&b)
{
	if(a.s==b.s)
		if(a.c==b.c)
			return a.idx<b.idx;
		else
			return a.c>b.c;
	else
		return a.s>b.s;
}

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].c>>a[i].m>>a[i].e,
		a[i].s=a[i].c+a[i].m+a[i].e,
		a[i].idx=i;
}

int main()
{
	init();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=5;i++)
		cout<<a[i].idx<<" "<<a[i].s<<endl;
	return 0;
}
     