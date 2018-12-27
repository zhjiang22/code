#include <stdio.h>
#include <string.h>
#define maxn 100010
#define inf 30000
int n,ans,data[maxn*2];
char s[maxn*2];
int cmp(int a,int b)
{
	int i;
	for (i=1;i<n;i++)
	{
		if (data[i+a-1]<data[i+b-1])
			return -i;
		if (data[i+a-1]>data[i+b-1])
			return i;
	}
	return 0;
}
 
void run(void)
{
	int i,min,now,k={0};
	min=inf;
	for (i=0;i<n;i++)
	{
		if (data[i]<min)
			min=data[i];
	}
	now=0;
	i=0;
	while(++i<=n)
	{
		if (data[i]<=min)
		{
			k=cmp(now,i);
			if (k>0)
			{
				now=i;
 
			}
			if (k<0)
			{
				i+=-k-1;
			}
			if (k==0)
				break;
		}
	}
	ans=now;
}
 
void ini(void)
{
	int i;
	char c;
	scanf("%d\n",&n);
	for (i=0;i<n;i++)
	{
		scanf("%c",&c);
		if (c==10)
			scanf("%c",&c);
		data[i]=data[i+n]=c-'a';
		s[i]=s[i+n]=c;
	}
	s[2*n]=0;
}
 
int main(void)
{
	ini();
	run();
	printf("%d\n",ans);
	while(1);
}
