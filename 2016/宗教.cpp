#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int pa[50005];
int n,m;

int getfather(int x)
{
	return pa[x]==x?x:pa[x]=getfather(pa[x]);
}

void bing(int x,int y)
{
	pa[getfather(x)]=getfather(y);
}

int main()
{
	int ans=0,Case=1;
	while(cin>>n>>m&&n&&m)
	{
		ans=0;
	for(int i=1;i<=n;i++)
		pa[i]=i;
	
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		bing(x,y);
	}
	
	for(int i=1;i<=n;i++)
		if(pa[i]==i)
		ans++;
	cout<<"Case "<<Case++<<": "<<ans<<endl;
	}
	return 0;
}