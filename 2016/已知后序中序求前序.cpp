#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

string a,b;

void powder(int x1,int y1,int x2,int y2)
{
	if(x1>y1)	return ;
	char root=b[y2];
	cout<<root;
	int p=x1;
	while(a[p]!=root)	p++;
	int cnt=p-x1;
	powder(x1,p-1,x2,x2+cnt-1);
	powder(p+1,y1,x2+cnt,y2-1);
	
}

int main()
{
	cin>>a>>b;
	int c1=a.length();
	int c2=b.length();
	powder(0,c1-1,0,c2-1);
	return 0;
}