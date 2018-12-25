#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const double xyz=0.6180339887498949;
int n;
double a[30005];
double ans=9999999999.0;
int x,y;

int search(double e,int p)
{
	int l=p+1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]<=e)
			l=mid+1;
		else r=mid-1;
	}
	double w=fabs(a[l]-e);
	double b=fabs(a[l-1]-e);
	double c=fabs(a[l+1]-e);
	if(w<b&&w<c)
		return l;
	else if(b<w&&b<c)
		return l-1;
	else return l+1;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		double t=(a[i]/(xyz));
		int k=search(t,i);
		double temp=fabs(a[i]/a[k]-xyz);
		if(temp<ans)
		{
			ans=temp;
			x=a[i];
			y=a[k];
		}
	}
	cout<<x<<endl<<y<<endl;
	return 0;
}
     