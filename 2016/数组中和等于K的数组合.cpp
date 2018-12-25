#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;
int a[50002];
int n;
int key;
int ans=0;

void powder(int w,int i)
{
	int l=i+1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(w+a[mid]==key)
		{
			cout<<w<<" "<<a[mid]<<endl;
			ans=1;
			return ;
		}
		else	if(w+a[mid]<key)
			l=mid+1;
		else
			r=mid-1;
	}
}

int main()
{
	 cin>>key>>n;
	 for(int i=1;i<=n;i++)
	 	cin>>a[i];
	 sort(a+1,a+n+1);
	 for(int i=1;i<=n;i++)
	 	powder(a[i],i);
	 if(!ans)
	 	cout<<"No Solution"<<endl;
	 return 0;
}
     