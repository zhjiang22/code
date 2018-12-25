#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1<<30;

int a[100][100];
int d[100][100];
int next[100][100];
int n,m;

void powder()
{
	
	int ans=INF,first=0;
	for(int j=n-1;j>=0;j--)
	{
		for(int i=0;i<m;i++)
	{
		if(j==n-1)	d[i][j]=a[i][j];
		else
		{
			int row[3]={i,i-1,i+1};
			if(i==0)	row[1]=m-1;
			if(i==m-1)	row[2]=0;
			sort(row,row+3);
			d[i][j]=INF;
			for(int k=0;k<3;k++)
			{
				int v=d[row[k]][j+1]+a[i][j];
				if(v<d[i][j])	{d[i][j]=v;   next[i][j]=row[k];}
			}
			if(j==0&&d[i][j]<ans){ans=d[i][j]; first=i;}
		}
		
	}
	}cout<<first+1;
		for(int i=next[first][0],j=1;j<n;i=next[i][j],j++)
	 	cout<<i+1;
	 	cout<<endl;
	 	cout<<ans;
}

int main()
{
freopen("D:\\1.txt","r",stdin);
	cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
	powder();
	return 0;
}
