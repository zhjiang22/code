#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

const int n=50;

int sign[n][n];

int main()
{
	freopen("10.in", "w", stdout);
	time_t t;
	srand((unsigned) time(&t));	

	cout << n << endl;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			sign[i][j]=i*n+j+1;
	for (int i=0; i<n*n; i++)
	{
		int x1=rand()%n;
		int x2=rand()%n;
		int y1=rand()%n;
		int y2=rand()%n;
		swap(sign[x1][y1], sign[x2][y2]);
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			cout << sign[i][j] << ' ';
		cout << endl;
	}

	return 0;
}
