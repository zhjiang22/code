#include<iostream>
#include<cstring>
using namespace std;
int n;
int a[1000];
int b[1000];
int tot=0;

void powder(int cur)
{
	if(cur==n+1)
	{
	for(int i=1;i<=n;i++)
	cout<<a[i];
	cout<<endl;
	tot++;
	}
	else
	{
		for(int i=1;i<=n;i++)
		if(b[i]==0)
		{
		a[cur]=i;
		b[i]=1;
		powder(cur+1);
		b[i]=0;
		}
	}
}

int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	memset(b,0,sizeof(b));
	cin>>n;
	powder(1);
	cout<<tot;
	return 0;	
}