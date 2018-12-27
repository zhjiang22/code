#include <stdio.h>
#include <iostream>
using namespace std;
int main (void)
{
	static int matrix[100][100];
	int i=0,j=0,n,count=1,loop;
	scanf("%d",&n);
	matrix[i][j]=1;
	for(loop=0;count<n*n;loop++)
	{
		for(;((j+1)<(n-loop))&&(count<n*n);)
		{
			j++;
			matrix[i][j]=count+1;
			count++;
		}
			if(loop==0)
			cout<<i<<" "<<j<<endl;
		for(;((i+1)<(n-loop))&&(count<n*n);)
		{
			i++;
			matrix[i][j]=count+1;
			count++;
		}
		if(loop==0)
			cout<<i<<" "<<j<<endl;
		for(;((j-1)>=loop)&&(count<n*n);)
		{
			j--;
			matrix[i][j]=count+1;
			count++;
		}
		if(loop==0)
			cout<<i<<" "<<j<<endl;
		for(;((i-1)>=(loop+1))&&(count<n*n);)
		{
			i--;
			matrix[i][j]=count+1;
			count++;
		}
		if(loop==0)
			cout<<i<<" "<<j<<endl;

	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",matrix[i][j]);
		printf("\n");
	}
	return 0;
}
