#include<bits/stdc++.h>
using namespace std;

const int MAXN=30005;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int n,m;

void init()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
}

void work()
{
	int fx=n/m;
	int x=n;
	if(x==0)
	{
		printf("%d/%d = %d.(0)\n",n,m,fx);
		printf("   1 = number of digits in repeating cycle\n");
		return;
	}
	int cur=-1;
	int r=0;
	while(true)
	{
		b[++cur]=x/m;
		if(c[x])
		{
			r=cur-c[x];
			break;
		}
		c[x]=cur;
		x%=m;
		x*=10;
	}
	if(r<50)
	{
			printf("%d/%d = %d.",n,m,fx);
			for(int i=1;i<c[x];i++)
				printf("%d",b[i]);
			putchar('(');
			for(int i=c[x];i<cur;i++)
				printf("%d",b[i]);
			putchar(')');
			printf("\n");
	}
	else
	{
		printf("%d/%d = %d.",n,m,fx);
		putchar('(');
		for(int i=1;i<=50;i++)
			printf("%d",b[i]);
		printf("...)\n");
	}
	printf("   %d = number of digits in repeating cycle\n",r);
	printf("\n");

}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		init();
		work();
	}
	return 0;
}
     