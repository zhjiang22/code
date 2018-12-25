#include<cstdio>
int main()
{
	int n,o,a;
	char x;
	scanf("%d",&n);
	scanf("%d%*c",&o);
	while(n--)
	{
		scanf("%c %d",&x,&a);
		if(x=='+')
		o+=a;
		if(x=='-')
		o-=a;
		if(x=='*')
		o*=a;
		if(x=='/'||x=='%')
		{
			if(a==0)
			printf("Error");
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
