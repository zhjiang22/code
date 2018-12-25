#include<iostream>
#include<cstring>
using namespace std;
int a[9][9];
int f[20];
int n,tot=0;

int Try(int k)
{
	for(int i=1;i<=n;i++)
	if(f[i]==f[k]&&a[i][k]==1&&i!=k)
	return 0;
	return 1;
}

void dfs(int k)
{
	if(k==n+1)
	tot++;
	else
	for(f[k]=1;f[k]<=4;f[k]++)
		if((Try(k))&&f[k]<=4)
	dfs(k+1);
}

int main()
{
	freopen("D:\\1.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cin>>a[i][j];
		dfs(1);
		cout<<tot<<endl;
		return 0;
}