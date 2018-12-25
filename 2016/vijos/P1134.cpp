#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF=0x7fffff;
int a[5][5];//操作数字
int k[5];//操作符
int b[5];//操作的位置
string ch;

int main()
{
	for(int i=1;i<=4;i++)
	{
		cin>>ch;
		if(ch.size()==1)
		{
			if(ch[0]<='9'&&ch[0]>='1')
				a[1][i]=ch[0]-'0';
			else
			{
				if(ch[0]=='J')
					a[1][i]=11;
				else if(ch[0]=='Q')
					a[1][i]=12;
				else
					a[1][i]=13;
			}
		}
		else
			a[1][i]=10;
	}
	for(int i=1;i<=4;i++)
		cout<<a[1][i]<<endl;
	for(int i=1;i<=4;i++)
		k[i]=0,b[i]=1;
	int i=1;
	while(a[4][1]!=24)
	{
		if(i==4)
			i--;
		k[i]++;
		if(k[i]==5)
			b[i]++,k[i]=1;
		for(int l=1;l<=4;l++)
		{
			for(int j=1;j<=4;j++)
				cout<<a[l][j]<<" ";
			cout<<endl;
		}
		cout<<i<<" "<<b[i]<<" "<<k[i]<<endl;
		cout<<endl;
		if(b[i]==5-i)
		{
			b[i]=1;
			k[i]=0;
			i--;
		}
		else
		{
			for(int j=1;j<=4;j++)
			{
				if(j==b[i])
				{
					switch(k[i])
					{
						case 1:a[i+1][b[i]]=a[i][b[i]]+a[i][b[i]+1];
                   			break;
           			    case 2:a[i+1][b[i]]=a[i][b[i]]-a[i][b[i]+1];
                  		    break;
            			case 3:a[i+1][b[i]]=a[i][b[i]]*a[i][b[i]+1];
                  		    break;
           			    case 4:if(a[i][b[i]+1]!=0 && a[i][b[i]]%a[i][b[i]+1]==0) 
                    				a[i+1][b[i]]=a[i][b[i]]/a[i][b[i]+1];
                  			   else
                     				a[i+1][b[i]]=INF;
					}
				}
				else	if(j<b[i])
					a[i+1][j]=a[i][j];
				else
					a[i+1][j]=a[i][j+1];
			}
			i++;
		}
		if(i==1&&k[i]==0)
			break;
	}
	if(i==1)
		cout<<0<<endl;
	else
		cout<<1<<endl;
	return 0;
}
     