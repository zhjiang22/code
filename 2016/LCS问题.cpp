#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string a,b;
int c1,c2,x=0;
char p[100];
int f[100][100];
int d[100][100];

void powder()
{
	for(int i=1;i<=c1;i++)
		for(int j=1;j<=c2;j++)
		if(a[i-1]==b[j-1])
		{
		f[i][j]=f[i-1][j-1]+1;
		d[i][j]=0;
		}
		else	if(f[i-1][j]>=f[i][j-1])
		{
			f[i][j]=f[i-1][j];
			d[i][j]=1;
		}
		else
		{
			f[i][j]=f[i][j-1];
			d[i][j]=-1;
		}
}

void print()
{
	int i=c1,j=c2;
	while(i>0&&j>0)
	{
		if(d[i][j]==0)
		{
			p[x++]=a[i-1];
			i--;	j--;
		}
		
		else if(d[i][j]==1)
		i--;
		
		else
		j--;
	}
}

int main()
{
	memset(f,0,sizeof(f));
	cin>>a>>b;
	c1=a.length();
	c2=b.length();
	powder();
	print();
	for(int i=f[c1][c2]-1;i>=0;i--)
	cout<<p[i];
	return 0;
}