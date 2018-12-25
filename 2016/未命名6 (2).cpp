#include<iostream>
#include<algorithm>
using namespace std;

int tot=0,n;
int a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

void powder(int x,int y)
{
	if(x==y)
	{
		for(int i=0;i<n;i++)
		cout<<a[i]<<",";
		cout<<endl;
		tot++;
	}
	else
	{
		for(int i=x;i<=y;++i)
		{
			swap(a[x],a[i]);
			powder(x+1,y);
			swap(a[x],a[i]);
		}
	}
}

int main()
{
	cin>>n;
	powder(0,n-1);
	cout<<tot;
	return 0;
}