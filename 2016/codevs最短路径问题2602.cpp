#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

struct node
{
	double x,y;
}o[105];
double f[105][105];
int n,m;

double wap(int i,int j)
{
	double p=o[i].x-o[j].x;
	double q=o[i].y-o[j].y;
	return (double)sqrt(p*p+q*q);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		f[i][j]=9999999;
	for(int i=1;i<=n;i++)
	cin>>o[i].x>>o[i].y;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int c1,c2;
		cin>>c1>>c2;
		f[c1][c2]=f[c2][c1]=wap(c1,c2);
	}
	int s,t;
	cin>>s>>t;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	printf("%.2lf\n",f[s][t]);
	return 0;
} 