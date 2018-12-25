#include<stdio.h>
int a[10000];
void zi(int n,int a[],int cur)
{
	int i,s;
	for(i=0;i<cur;i++)
		printf("%d",a[i]);
	printf("\n");
	s=cur? a[cur-1]+1:0;
	for(i=s;i<n;i++)
	{
		a[cur]=i;
		zi(n,a,cur+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	zi(n,a,0);
	return 0;
}