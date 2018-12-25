#include<iostream>
#include<algorithm>	
#include<cstdio>
int a[100];
using namespace std;
int zui(int x,int y)
{
 	int i;
 	cin>>x>>y;
 	int m=min(x,y);
 	for(i=m;i>1;i--)
 	if(x%i==0&&y%i==0)
 	break;
 	int a=(x*y)/i;
    return a;
}
int main()
{
    int n;
 	scanf("%d",&n);
 	for(int i=0;i<n;i++)
 	scanf("%d",&a[i]);
	int x=zui(a[0],a[1]);
	for(int i=2;i<n;i++)
	x=zui(x,a[i]);
	cout<<x<<endl;
	system("pause");
	return 0;
} 	
