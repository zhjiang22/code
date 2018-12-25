#include<iostream>
#include<cstring>
using namespace std;

int a[10]={6,2,5,5,4,5,6,3,7,6};
int w[2050];
int n;

int solve(int x)
{
	if(x==0)
		return a[0];
	int ans=0; 
	while(x)
	{
		ans+=a[x%10];
		x/=10;	
	}
	return ans;
}

void init()
{
	for(int i=0;i<=2000;i++)
		w[i]=solve(i);
}

int main()
{
	int ans=0;
	cin>>n;
	init();
	for(int i=0;i<=1000;i++)
		for(int j=i;j<=1000;j++)
		{
			if(w[i]+w[j]>n-6)
			continue;
			int t=w[i+j];
			if(t+w[i]+w[j]+4==n)
				if(i==j)	ans++;
				else		ans+=2;	
		}
	cout<<ans<<endl;
	return 0;
} 
