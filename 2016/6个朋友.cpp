#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int fa[10003];
int num[10003];
int n,m;

int cmp(int x,int y)
{
	return x>y;
}

int getfather(int x)
{
	return fa[x]==x?x:fa[x]=getfather(fa[x]);
}

void Union(int x,int y)
{
	int p=getfather(x);
	int q=getfather(y);
	if(p!=q)
	{
		fa[p]=q;
		num[q]+=num[p];
	}
}

int main()
{
	freopen("E:\\code\\input.txt","r",stdin);
	freopen("E:\\code\\output.txt","w",stdout);
	memset(num,0,sizeof(num));
	int ans=0,tot=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		Union(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i)
			ans++;
		num[getfather(i)]++;
	}
	if(ans>6)
	{
		cout<<"T_T"<<endl;
		sort(num+1,num+n+1,cmp);
		cout<<num[1]+num[2]+num[3]+num[4]+num[5]+num[6];
	}

	else 
		cout<<"^_^";
	return 0;
}