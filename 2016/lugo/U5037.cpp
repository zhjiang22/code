#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
int a[MAXN];
int b[MAXN];
int x1,y1;
int x2,y2;
int cnt;
int ans;
int n;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	x1=x2=1;
	y1=y2=n;
}

int main()
{
	init();
	while(cnt++<n)
	{
		if(b[y2]>a[y1])
		{
			ans++;
			y1--;	y2--;
		}
		else	if(b[y2]<a[y1])
		{
			x2++;
			y1--;
		}
		else
		{
			if(b[x2]>a[x1])
			{
				ans++;
				x1++;	x2++;
			}
			else
				x2++,y1--;
		}
	}
	cout<<cnt<<endl;
	cout<<ans<<endl;
	return 0;
}
     