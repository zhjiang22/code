#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
int main(void)
{
    freopen("J://duipa//data.txt","w",stdout);
    srand(time(NULL));
    int n=rand()%20+5;
	int m=rand()%20+5;
	printf("%d\n%d\n",n,m);
    while(n--)
    {
        printf("%d\n",rand());
    }
    while(m--)
    {
    	printf("%d\n",rand());
    }
    return 0;
}
