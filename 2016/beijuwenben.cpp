#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
int Next[10000];
char a[10000];

int main()
{
	Next[0]=0;
	int cur,last;
	cur=last=0;
	while(scanf("%s",a+1)==1)
	{
		char ch;
		for(int i=1;i<=strlen(a+1);i++)
		{
			ch=a[i];
			if(ch=='[')
				cur=0;
			else if(ch==']')
				cur=last;
			else
			{
				Next[i]=Next[cur];
				Next[cur]=i;
				if(cur==last)
					last=i;
				cur=i;
			}
		}
		for(int i=Next[0];i!=0;i=Next[i])
		cout<<a[i];
		cout<<endl;
	}
	return 0;
}
     