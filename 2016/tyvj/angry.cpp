#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

const int MAXN=100005;
const int INF=0x7fffff;
int a[MAXN];
int n,d;
int tot;
int ans=INF;
int ansl,ansr;

int main()
{
	clock_t s=clock();
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=0;
	while(r<n)
	{
		while(tot<d&&r<n)
		{
			r++;
			tot+=a[r];
		}
		if(tot>=d&&r-l+1<ans)
		{
			ansl=l;	ansr=r;
			ans=r-l+1;
		}
		while(tot>=d&&l<=r)
		{
			tot-=a[l++];
			if(tot>=d&&r-l+1<ans)
			{
				ansl=l;	ansr=r;
				ans=r-l+1;
			}
		}
	}
	if(ans==INF)
		cout<<"I’m angry"<<endl;
	else
	{
		int sum=0;
		for(int i=ansl;i<=ansr;i++)
			cout<<i<<" ",sum+=a[i];
		cout<<endl;
		cout<<sum<<endl;
	}
	cout<<(double)(clock()-s)/CLOCKS_PER_SEC<<endl;
	return 0;
}
     