#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char a[10002];
int b[30]={0};

int cmp(int x,int y)
{
	return x>y;
}

int main()
{
	int b12;
	int i=0;
	int sum=0;
	int x=26;
	gets(a);
	int y=strlen(a);
	for(int i=0;i<y;i++)
		if(a[i]<'a')
			a[i]+=32;
	for(int i=0;i<y;i++)
		b[a[i]-'a']++;
	sort(b,b+26,cmp);
	while(b[i])
	{
		sum+=b[i++]*x--;
	}
	cout<<sum<<endl;
	return 0;
}