#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
string a,b;

void powder(int x1,int y1,int x2,int y2)
{
	if(x1>y1)	return;
	int i;
	char root=b[y2];
	cout<<root;
	for(i=x1;i<=y1;i++)
		if(a[i]==root)
			break;
	int cnt=i-x1;
	powder(x1,i-1,x2,x2+cnt-1);
	powder(i+1,y1,x2+cnt,y2-1);
}

int main()
{
	freopen("D:\\in.txt","r",stdin);
	freopen("D:\\out.txt","w",stdout);
	cin>>a>>b;
	int c1=a.length();
	int c2=b.length();
	powder(0,c1-1,0,c2-1);
	return 0;
}