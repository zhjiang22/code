#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int t;
int n;
int a[12];
int big,small;

int main()
{
	cin>>t;
	while(t--)
	{
		big=0,small=0;
		int cur1=1,cur2=1;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		
		sort(a+1,a+n+1);
		if(n%2)
		{
			if(a[1]==0)
			{
				big=a[2]*10+a[1];
				cur1+=2;
				int q=3;
				while(cur1<=(n/2+1))
				{
					big*=10;
					big+=a[q++];
					cur1++;
				}
				int p=n;
				while(cur2<=(n/2))
				{
					small*=10;
					small+=a[p--];
					cur2++;
				}
				cout<<big-small<<endl;
			}
			else
			{
				int q=1;
				while(cur1<=(n/2+1))
				{
					big*=10;
					big+=a[q++];
					cur1++;
				}
				int p=n;
				while(cur2<=(n/2))
				{
					small*=10;
					small+=a[p--];
					cur2++;
				}
				cout<<big-small<<endl;
			}
		}
		else
		{
			int ans=999999;
			for(int i=2;i<=n;i++)
			{
				if(a[1]==0&&i==2)
					continue;
				big=small=0;
				big+=a[i];
				small+=a[i-1];
				int cur1=1;
				for(int j=1;j<=n&&cur1<(n/2);j++)
				{
					if(j==i||j==i-1)	continue;
					else
					{
						big*=10;
						big+=a[j];
						cur1++;
					}
				}
				int cur2=1;
				for(int j=n;j>=1&&cur2<(n/2);j--)
				{
					if(j==i||j==i-1)	continue;
					else
					{
						small*=10;
						small+=a[j];
						cur2++;
					}
				}
				ans=min(ans,abs(big-small));
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
     