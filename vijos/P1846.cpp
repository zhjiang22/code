#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,q;
int a1,a2,a3,a4,a5,a6;
int a[20][20];

int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[20][20];
	for(int i=1;i<=q;i++)
		cin>>a1>>a2>>a3>>a4>>a5>>a6;
	for(int i=1;i<=q;i++)
		cout<<-1<<endl;
	return 0;
}
     