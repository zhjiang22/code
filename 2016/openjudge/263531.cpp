#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10005;
const int MAXK=105;
int f[MAXN][MAXK];
int a[MAXN];
int n,k;

void init()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]%=k;
	f[0][0]=1;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		for(int j=0;j<k;j++)
				f[i][j]|=(f[i-1][(j-a[i]+k)%k]|f[i-1][(j+a[i])%k]);
	if(f[n][0])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
     