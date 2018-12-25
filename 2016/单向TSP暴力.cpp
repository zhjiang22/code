#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1<<30;

int a[100][100];
int n,m,mi=INF;

void powder(int x,int y,int ans)
{
	if(y==n)
		if(ans<mi)
		{
		mi=ans;
		return;
		}
		else
		return; 
	if(ans>=mi)
	return ;
	int row[3]={x,x-1,x+1};
	if(x==0)	row[1]=m-1;
	if(x==m-1)	row[2]=0;
	for(int i=0;i<3;i++)
	powder(row[i],y+1,ans+a[x][y]);
}

int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
	powder(0,0,0);
	cout<<mi<<endl; 
	return 0;
}
