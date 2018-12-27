#include<bits/stdc++.h>
using namespace std;

const int MAXN=1005;
char b[MAXN];
int a[MAXN][4];
int n,m;
int t;

int get_idx(const char& x)
{
	if(x=='A')	return 0;
	if(x=='C')	return 1;
	if(x=='G')	return 2;
	if(x=='T')	return 3;
}

char get_back(const int& x)
{
	if(x==0)	return 'A';
	if(x==1)	return 'C';
	if(x==2)	return 'G';
	if(x==3)	return 'T';
}

void init()
{
	cin>>n>>m;
	memset(a,0,sizeof(a));
	getchar();
	for(int k=1;k<=n;k++)
	{
		gets(b);
		for(int i=0;i<m;i++)
			a[i][get_idx(b[i])]++;
	}
	/*for(int i=0;i<m;i++)
	{
		for(int j=0;j<4;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}*/
}

void work()
{
	int ans=0;
	for(int i=0;i<m;i++)
	{
		int maxd=-1;
		int cur=0;
		for(int j=0;j<4;j++)
			if(a[i][j]>maxd)
			{
				maxd=a[i][j];
				cur=j;
			}
		ans+=(n-maxd);
		putchar(get_back(cur));
	}
	putchar('\n');
	printf("%d\n",ans);
}

int main()
{
	cin>>t;
	while(t--)
	{
		init();
		work();
	}
	return 0;
}
     