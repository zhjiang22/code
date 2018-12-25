#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a,b;
int c,d;
int t;

int gcd(int a,int b)
{
	 return b==0?a:gcd(b,a%b);
}

int main()
{
	freopen("tile.in","r",stdin);
	freopen("tile.out","w",stdout);
	int x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		x=a*c/gcd(a,c);
		y=gcd(b,d);
		if(x%y==0)
			printf("%d\n",x/y);
		else	
		{
			while(1)
			{
				int k=gcd(x,y);
				if(k==1)
					break;
				else
				{
					x/=k;
					y/=k;
				}
			}
			printf("%d/%d\n",x,y);
		}
	}
	return 0;
}
     