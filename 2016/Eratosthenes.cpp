#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

const int EOP=1e6;
bool vis[EOP];

void Et()
{
	clock_t s=clock();
	int m=sqrt(EOP+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=EOP;j+=i)
			{
				if(j==3)
					cout<<i<<" "<<j<<endl;
				vis[j]=1;
			}
	printf("%.4lf\n",(double)(clock()-s)/CLOCKS_PER_SEC);
}

int main()
{
	Et();
}
     