#include<cstdio>
int main()
{
	int n,o,a;
	char x,y;
	scanf("%d",&n);
	scanf("%d",&o);
	while(n--)
	{
		scanf("%c%c %d",&y,&x,&a);
		if(x=='+')
		o+=a;
		if(x=='-')
		o-=a;
		if(x=='*')
		o*=a;
		if(x=='/'||x=='%')
		{
			if(a==0)
			{
				printf("Error");
				
			}
			else
			{
				if(x=='/')
				o/=a;
				else
				o%=a;
			}
		}
	}
	printf("%d",o);
	return 0;
}
