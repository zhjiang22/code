/*
可以用来练习快排，归并排序，基数排序等排序方法
我比较懒所以直接STL爆炸2333
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int n,k;
int a[100002];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cout<<a[k]<<endl;
	return 0;
}
     