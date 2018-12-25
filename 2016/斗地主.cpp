#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int a[30],b[100],p[21];
int T;
int n;

int main()
{
	int i;
	cin>>T>>n;
	int s;
	while(T--)
	{
	memset(p,0,sizeof(p));
	int tot=0;
		for(i=1;i<=n;i++)
		cin>>a[i]>>b[i];
		for(i=1;i<=n;i++)
		p[a[i]]++;
		if(p[0])
		{
			p[0]-=2;
			tot++;
		}
		for(i=1;i<=20;i++)
		if(p[i]==3||p[i]==4)
		{
			cout<<1<<endl;
			break;
		}
		else if(p[i]==2)
		{
			tot++;
		}
		else if(p[i]==1)
		tot++;
		if(i==21)cout<<tot<<endl;
	}
	return 0;
}