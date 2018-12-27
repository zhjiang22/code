#include <stdio.h>


int main()
{
	
int n;
	scanf("%d",&n);
	int x;
	while(n>0)
	{
		scanf("%d",&x);
		n--;
		if(x>0)
		{
			printf("%d",x);
			break;
		}
	}
	while(n>0)
	{
		scanf("%d",&x);
		n--;
		if(x>0)
		{
			printf(" %d",x);
		}
		
	}
	printf("\n");
	return 0;
 } 