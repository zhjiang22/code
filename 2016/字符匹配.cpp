#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100000;
char a[maxn];
int b[26];
int main()
{
	int x=0;
	gets(a);
	memset(b,0,sizeof(b));
	for(int i=0;i<sizeof(a);i++)
	b[a[i]-97]++;
	for(int i=0;i<=25;i++)
	if(b[i]%2)
	x++;
	printf("%d",x);
	return 0;
}
