#include<iostream>
#include<cstring>
using namespace std;

struct node
{
	int x,y;
   friend bool operator <( const node &a,const node &b)
 { 
     return a.y<b.y;
}
};

node a[10000];

int n;
int cur;

int main()
{
	//freopen("tv.in","r",stdin);
	//freopen("tv.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i].x>>a[i].y;
	sort(a,a+n);
	cur=a[0].y;
	int ans=1;
	for(int i=1;i<n;i++)
	{
		if(a[i].x>=cur)
		{
			ans++;
			cur=a[i].y;
		}
	}
	cout<<ans;
	return 0;
}