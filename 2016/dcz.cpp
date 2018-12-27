#include <stdio.h>
int main()
{
	int num,i;
	int left[16];
	int M=(1<<16);
	while(scanf("%d",&num)!=EOF)
	{
		if(num<0)
			num+=M;
		i=15;
		for(;0!=num/2;i--)
		{
			left[i]=num&1;
			num>>=1;
		}
		left[i]=1;
		for(i--;i>=0;i--)
		{
			left[i]=0;
		}
		for(i++;i<16;i++)
			{
				printf("%d",left[i]);
				
	        }
	        printf("\n");
	}
	return 0;


}