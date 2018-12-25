#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[10000];
int main()
{
 	int ok=0;
 	gets(a);
 	int b=strlen(a);
 	if(a[0]=='-')
 	{
	 			cout<<'-';
	 			for(int i=b-1;i>=1;i--)
	 			{
				 		if(a[i]!='0')
                		ok=1;
                		if(ok)
                		cout<<a[i];
                }
				}
     else
     {
                for(int i=b-1;i>=0;i--)
	 			{
				 		if(a[i]!='0')
                		ok=1;
                		if(ok)
                		cout<<a[i];
                }
     }
     system("pause");
     return 0;
}
	 			
 	
