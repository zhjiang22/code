#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
const int MAXSIZE=10;
int ch[MAXN][MAXSIZE];
int v[MAXN];
char c[15];
int tot;
int n,q;

void insert()
{
	int u=0;	int n=strlen(c);
	for(int i=0;i<n;i++)
	{
		int p=(c[i]-'0');
		if(!ch[u][p])
		{
			ch[u][p]=++tot;	u=tot;
		}
		else
			u=ch[u][p];
		v[u]++;
	}
}

int query()
{
	int u=0,n=strlen(c);
	for(int i=0;i<n;i++)
	{
		int p=c[i]-'0';
		int& t=ch[u][p];
		if(t)
			u=t;
		else
			return 0;
	}
	return v[u];
}

void init()
{
	scanf("%d",&n);
	scanf("%d",&q);	getchar();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c);
		insert();
	}
}

void question()
{
	for(int i=1;i<=q;i++)
	{
		scanf("%s",c);
		cout<<query()<<endl;
	}
}

int main()
{
	init();
	question();
}
     