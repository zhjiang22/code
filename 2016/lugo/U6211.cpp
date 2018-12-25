#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

const int MAXN=10005;
char a[MAXN],b[MAXN];
int f[2][MAXN];
int n,m;
int ans;

int main()
{
	gets(a);	gets(b);
	n=strlen(a);	m=strlen(b);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(a[i]==b[j])
			{
				if(j!=0)
					f[i%2][j]=f[(i+1)%2][j-1]+1;
				else
					f[i%2][j]=1;
				ans=max(ans,f[i%2][j]);
			}
			else
				f[i%2][j]=0;
	}
	printf("%d\n",ans);
	return 0;
}