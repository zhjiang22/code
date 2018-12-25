#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long MAXN=10050;
struct node
{
	long long x,y;
}a[MAXN];
long long n;
long long ans;
long long x=0,y=0;

void init()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].y);

}
int main()
{
	init();
	long long i=1,j=1;
	while(i<=n&&j<=n)
	{
		x+=a[j].x;	y+=a[i].y;
		if(x<=y)
		{
			ans++;
			while(x!=0&&y!=0)
				x--;	y--;
		}
		else
		{
			long long p=y;
			y=0;
			do
			{
				x+=a[j].x;
				if(p>x)
					x=0,p-=x;
				else
					x-=p;
				j++;
			}
			while(!x&&j<=n);
				i++;
			continue;
		}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}
     