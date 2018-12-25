#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int x[420],y[420],c[102];
double d[501][501];
int T,n,v,z1,z2;


void powder(int i)
{
	int a=(x[4*i+1]-x[4*i+2])*(y[4*i+1]-y[4*i+2]);
	int b=(x[4*i+1]-x[4*i+3])*(y[4*i+1]-y[4*i+3]);
	int c=(x[4*i+2]-x[4*i+3])*(y[4*i+2]-y[4*i+3]);
	if(a+b==c)
		x[4*i+4]=x[4*i+2]+x[4*i+3]-x[4*i+1],
		y[4*i+4]=y[4*i+2]+y[4*i+3]-y[4*i+1];
	else if(a+c==b)	
		x[4*i+4]=x[4*i+1]+x[4*i+3]-x[4*i+2],
		y[4*i+4]=y[4*i+1]+y[4*i+3]-y[4*i+2];
	else 
		x[4*i+4]=x[4*i+2]+x[4*i+1]-x[4*i+3],
		y[4*i+4]=y[4*i+2]+y[4*i+1]-y[4*i+3];
	
	for(int i1=1;i1<=4;i1++)
		for(int j=i+1;j<=4;j++)
		d[4*i+i1][4*i+j]=d[4*i+j][4*i+i1]=sqrt(x[4*i+i1]-x[4*i+j])*(y[4*i+i1]-y[4*i+j])*;
	
}

int main()
{
	cin>>n>>v>>z1>>z2;
	 for (i=1;i<=401;i++)
            for (j=1;j<=401;j++)
            d[i][j]=100000000;
	for(int i=0;i<n;i++)
	{
		cin>>x[4*i+1]>>y[4*i+1]>>x[4*i+2]>>y[4*i+2]>>x[4*i+3]>>y[4*i+3]>>c[i];
		powder(i);
	}
	int p=4*n;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=p;i++)
			for(int j=1;j<=p;j++)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	
}