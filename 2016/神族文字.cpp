#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <map>
using namespace std;

map<string,string> wa;
char a[20],b[20];

int main()
{
	while(1)
	{
		char t;
		if((t=getchar())=='\n')
			break;
		else
		{
			a[0]=t;
			int i=1;
			while(1)
			{
				t=getchar();
				if(t==' ')
				{a[i]='\0';break;}
				else
					a[i++]=t;
			}
		}
		cin>>b;
		getchar();
		
		wa[b]=a;
	}
	string buf;
	while(cin>>buf)
		if(wa[buf]!="")
			cout<<wa[buf]<<endl;
		else
			cout<<"eh"<<endl;
	return 0;
}
     