#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100
#define fabs(x) ((x)>0?(x):-(x))
#define eps 1e-10

//列主元gauss消去求解a[][]x[]=b[]
//返回是否有唯一解,若有解在b[]中
int gauss_cpivot(int n,double a[][MAXN],double b[]){
	int i,j,k,row;
	double maxp,t;
	for (k=0;k<n;k++){
		for (maxp=0,i=k;i<n;i++)
			if (fabs(a[i][k])>fabs(maxp))
				maxp=a[row=i][k];
		if (fabs(maxp)<eps)
			return 0;
		if (row!=k){
			for (j=k;j<n;j++)
				t=a[k][j],a[k][j]=a[row][j],a[row][j]=t;
			t=b[k],b[k]=b[row],b[row]=t;
		}
		for (j=k+1;j<n;j++){
			a[k][j]/=maxp;
			for (i=k+1;i<n;i++)
				a[i][j]-=a[i][k]*a[k][j];
		}
		b[k]/=maxp;
		for (i=k+1;i<n;i++)
			b[i]-=b[k]*a[i][k];
	}
	for (i=n-1;i>=0;i--)
		for (j=i+1;j<n;j++)
			b[i]-=a[i][j]*b[j];
	return 1;
}
double a[1005][1005],b[1005];
int main()
{
	double x;
	cout<<x<<endl;
	int n,i,j;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
			cin>>b[i];
	}
}