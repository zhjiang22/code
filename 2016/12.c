#include<stdio.h>
int a[10000];
void pai(int n,int a[],int cur)
{
	int i,j,ok=1;
	if(cur==n)
	{
		for(i=0;i<n;i++)
		printf("%d",a[i]);
		printf("\n");
	}
	else for(i=1;i<=n;i++)
	{
		for(j=0;j<cur;j++)
		{
			if(a[j]==i) ok=0;}
				if(ok)
				{
					a[cur]=i;
					pai(n,a,cur+1);
				}
	}	
}
int main()
{
	int n;
	scanf("%d",&n);
	pai(n,a,0);
	return 0;
}
