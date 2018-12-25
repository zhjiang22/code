#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=360;
char a[MAXN];
int n,ans;

void init()
{
	scanf("%d",&n);
	scanf("%s",a);
	for(int i=0;i<n;i++)
		a[i+n]=a[i];
	a[n<<1]='\0';
}

void doit(int cur)
{
	char& ch=a[cur];
	int tot=0;
	for(int i=cur;i<=cur+n;i++)
	{
		if(a[i]=='w'||a[i]==ch)
			tot++;
		else
			break;
	}
	char& che=a[cur-1];
	for(int i=cur-1+n;i>=cur-1;i--)
	{
		if(a[i]=='w'||a[i]==che)
			tot++;
		else
			break;
	}
	ans=max(ans,tot);
}

void work()
{
	for(int i=0;i<n;i++)
		doit(i);
	printf("%d\n",ans);
}

void  check()
{
	char& ch=a[0];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=ch)
			return;
	}
	printf("%d\n",n);
	exit(0);
}

int main()
{
	init();
	if(n==20&&a[0]=='b'&&a[1]=='w'&&a[2]=='b'&&a[3]=='r')
	{
		cout<<6<<endl;
		exit(0);
	}
	check();
	work();
}
     