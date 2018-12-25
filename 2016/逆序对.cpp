#include <iostream>
#include <cstring>
using namespace std;

int a[100002];
int T[100002];
int n;
long long ans=0ll;

void powder(int x,int y)
{
	if(y-x>1)
	{
		int mid=(x+y)>>1;
		int p=x,i=x,q=mid;
		powder(x,mid);
		powder(mid,y);
		while(p<mid||q<y)
		{
			if(q>=y||(p<mid&&a[p]<=a[q]))
				T[i++]=a[p++];
			else
				{
					T[i++]=a[q++];
					ans+=mid-p;
				}
		}
		for(int i=x;i<y;i++)
			a[i]=T[i];
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	powder(1,n+1);
	cout<<ans<<endl;
	return 0;
}