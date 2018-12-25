#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN=105;
int  a[MAXN],b[MAXN],c[MAXN],d[MAXN],e[MAXN];
string name[MAXN];
int n;
int sum_price;

void init()
{
	cin>>n;
	char x;
	for(int i=1;i<=n;i++)
	{
		cin>>name[i];
		scanf("%d %d",&a[i],&b[i]);
		cin>>x;
		if(x=='Y')
			c[i]=1;
		cin>>x;
		if(x=='Y')
			d[i]=1;
		scanf("%d",&e[i]);
	}
}

int price[MAXN];
int MAX,max_num;

void work()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>80&&e[i]>=1)
			price[i]+=8000;
		if(a[i]>85&&b[i]>80)
			price[i]+=4000;
		if(a[i]>90)
			price[i]+=2000;
		if(a[i]>85&&d[i])
			price[i]+=1000;
		if(b[i]>80&&c[i])
			price[i]+=850;
	}
	for(int i=1;i<=n;i++)
	{
		sum_price+=price[i];
		if(price[i]>=MAX)
		{
			MAX=price[i];
			max_num=i;
		}
	}
}

void output()
{
	cout<<name[max_num]<<endl;
	cout<<price[max_num]<<endl;
	cout<<sum_price<<endl;
}

int main()
{
	init();
	work();
	output();
	return 0;
}